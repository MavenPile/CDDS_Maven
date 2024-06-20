#include "Game.h"
#include "Critter.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include <iostream>

Game::Game()
{
    // WINDOW
    m_screenW = 800;
    m_screenH = 450;
    m_window = new raylib::Window(m_screenW,m_screenH, "Critters vs. Destroyer");

    //  RANDOM SEED
    srand(time(NULL));

    //  INITIALISING TEXTURES
    Texture2D* critTex = new (Texture2D)(LoadTexture("res/10.png"));
    Texture2D* desTex = new (Texture2D)(LoadTexture("res/9.png"));

    if (!IsTextureReady(*critTex))
    {
        std::cout << "critTex failed to load properly..." << std::endl;
        
        m_window->Close();
    }
    else if (!IsTextureReady(*desTex))
    {
        std::cout << "desTex failed to load properly..." << std::endl;
        
        m_window->Close();
    }

    m_textures.Add(critTex, "critter_texture");
    m_textures.Add(desTex, "destroyer_texture");

    //  INITIALISING CRITTERS
    for (int i = 0; i < m_CRITTER_COUNT; i++)
    {
        // create a random direction vector for the velocity
        Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
        // normalize and scale by a random speed
        velocity = Vector2Scale(Vector2Normalize(velocity), m_MAX_VELOCITY);

        m_critters[i] = new Critter();

        // create a critter in a random location
        m_critters[i]->Init(
            Vector2{ (float)(5 + rand() % (m_screenW - 10)), (float)(5 + (rand() % m_screenH - 10)) },
            velocity,
            12, m_textures["critter_texture"]);
    }

    //  INITIALISING DESTROYER
    m_destroyer = new Critter();
    Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
    velocity = Vector2Scale(Vector2Normalize(velocity), m_MAX_VELOCITY);
    m_destroyer->Init(Vector2{ (float)(m_screenW >> 1), (float)(m_screenH >> 1) }, velocity, 20, m_textures["destroyer_texture"]);

    m_timer = 1;
    m_nextSpawnPos = m_destroyer->GetPosition();
}

Game::~Game()
{
    for (int i = 0; i < m_CRITTER_COUNT; i++)
    {
        delete m_critters[i];
    }

    delete m_destroyer;

    delete m_textures["critter_texture"];
    delete m_textures["destroyer_texture"];
}

void Game::Run()
{
	while (!m_window->ShouldClose())
	{
		//	UPDATE
        float delta = GetFrameTime();

        // update the destroyer
        m_destroyer->Update(delta);
        // check each critter against screen bounds
        if (m_destroyer->GetX() < 0) {
            m_destroyer->SetX(0);
            m_destroyer->SetVelocity(Vector2{ -m_destroyer->GetVelocity().x, m_destroyer->GetVelocity().y });
        }
        if (m_destroyer->GetX() > m_screenW) {
            m_destroyer->SetX(m_screenW);
            m_destroyer->SetVelocity(Vector2{ -m_destroyer->GetVelocity().x, m_destroyer->GetVelocity().y });
        }
        if (m_destroyer->GetY() < 0) {
            m_destroyer->SetY(0);
            m_destroyer->SetVelocity(Vector2{ m_destroyer->GetVelocity().x, -m_destroyer->GetVelocity().y });
        }
        if (m_destroyer->GetY() > m_screenH) {
            m_destroyer->SetY(m_screenH);
            m_destroyer->SetVelocity(Vector2{ m_destroyer->GetVelocity().x, -m_destroyer->GetVelocity().y });
        }

        // update the critters
        // (dirty flags will be cleared during update)
        for (int i = 0; i < m_CRITTER_COUNT; i++)
        {
            m_critters[i]->Update(delta);

            // check each critter against screen bounds
            if (m_critters[i]->GetX() < 0) {
                m_critters[i]->SetX(0);
                m_critters[i]->SetVelocity(Vector2{ -m_critters[i]->GetVelocity().x, m_critters[i]->GetVelocity().y });
            }
            if (m_critters[i]->GetX() > m_screenW) {
                m_critters[i]->SetX(m_screenW);
                m_critters[i]->SetVelocity(Vector2{ -m_critters[i]->GetVelocity().x, m_critters[i]->GetVelocity().y });
            }
            if (m_critters[i]->GetY() < 0) {
                m_critters[i]->SetY(0);
                m_critters[i]->SetVelocity(Vector2{ m_critters[i]->GetVelocity().x, -m_critters[i]->GetVelocity().y });
            }
            if (m_critters[i]->GetY() > m_screenH) {
                m_critters[i]->SetY(m_screenH);
                m_critters[i]->SetVelocity(Vector2{ m_critters[i]->GetVelocity().x, -m_critters[i]->GetVelocity().y });
            }

            // kill any critter touching the destroyer
            // simple circle-to-circle collision check
            float dist = Vector2Distance(m_critters[i]->GetPosition(), m_destroyer->GetPosition());
            if (dist < m_critters[i]->GetRadius() + m_destroyer->GetRadius())
            {
                m_critters[i]->Destroy();
                // this would be the perfect time to put the critter into an object pool
            }
        }

        // check for critter-on-critter collisions
        for (int i = 0; i < m_CRITTER_COUNT; i++)
        {
            for (int j = 0; j < m_CRITTER_COUNT; j++) {
                if (i == j || m_critters[i]->IsDirty()) // note: the other critter (j) could be dirty - that's OK
                    continue;
                // check every critter against every other critter
                float dist = Vector2Distance(m_critters[i]->GetPosition(), m_critters[j]->GetPosition());
                if (dist < m_critters[i]->GetRadius() + m_critters[j]->GetRadius())
                {
                    // collision!
                    // do math to get critters bouncing
                    Vector2 normal = Vector2Normalize(Vector2Subtract(m_critters[j]->GetPosition(), m_critters[i]->GetPosition()));

                    // not even close to real physics, but fine for our needs
                    m_critters[i]->SetVelocity(Vector2Scale(normal, -m_MAX_VELOCITY));
                    // set the critter to *dirty* so we know not to process any more collisions on it
                    m_critters[i]->SetDirty();

                    // we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
                    // to make sure the other critter is clean before we do the collision response
                    if (!m_critters[j]->IsDirty()) {
                        m_critters[j]->SetVelocity(Vector2Scale(normal, m_MAX_VELOCITY));
                        m_critters[j]->SetDirty();
                    }
                    break;
                }
            }
        }

        m_timer -= delta;
        if (m_timer <= 0)
        {
            m_timer = 1;

            // find any dead critters and spit them out (respawn)
            for (int i = 0; i < m_CRITTER_COUNT; i++)
            {
                if (m_critters[i]->IsDead())
                {
                    Vector2 normal = Vector2Normalize(m_destroyer->GetVelocity());

                    // get a position behind the destroyer, and far enough away that the critter won't bump into it again
                    Vector2 pos = m_destroyer->GetPosition();
                    pos = Vector2Add(pos, Vector2Scale(normal, -50));
                    // its pretty ineficient to keep reloading textures. ...if only there was something else we could do
                    m_critters[i]->Init(pos, Vector2Scale(normal, -m_MAX_VELOCITY), 12, m_textures["critter_texture"]);
                    break;
                }
            }
            m_nextSpawnPos = m_destroyer->GetPosition();
        }

		//	DRAW
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // draw the critters
        for (int i = 0; i < m_CRITTER_COUNT; i++)
        {
            m_critters[i]->Draw();
        }
        // draw the destroyer
        // (if you're wondering why it looks a little odd when sometimes critters are destroyed when they're not quite touching the 
        // destroyer, it's because the origin is at the top-left. ...you could fix that!)
        m_destroyer->Draw();

        DrawFPS(10, 10);

        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();


        m_frameCount++;
        m_totalFPS += GetFPS();
        m_aveFPS = m_totalFPS / m_frameCount;
        
        if (10 <= GetTime())
        {
            m_window->Close();
        }
	}

    for (int i = 0; i < m_CRITTER_COUNT; i++)
    {
        m_critters[i]->Destroy();
    }

    std::cout << m_aveFPS << std::endl;
}