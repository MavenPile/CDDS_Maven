#pragma once

#include "raylib.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include <iostream>

#include "raylib-cpp.hpp"

#include "HashTable.h"

class Critter;

class Game
{
private:

	//	CONSTANTS
	const int m_CRITTER_COUNT = 50;
	const int m_MAX_VELOCITY = 80;

	//	WINDOW
	raylib::Window* m_window;
	int m_screenW;
	int m_screenH;
	float m_timer;

	//	OBJECT
	Critter* m_critters[1000];

	Critter* m_destroyer;
	Vector2 m_nextSpawnPos;

	//	TEXTURES

	HashTable<Texture2D> m_textures;

	//	AVE FPS CALC
	int m_totalFPS = 0;
	int m_frameCount = 0;
	int m_aveFPS = 0;

public:

	Game();
	~Game();

	void Run();
};