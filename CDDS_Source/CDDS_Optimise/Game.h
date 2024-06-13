#pragma once

#include "raylib.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include <iostream>

class Critter;

class Game
{
public:

	//	CONSTANTS
	const int m_CRITTER_COUNT = 50;
	const int m_MAX_VELOCITY = 80;

	//	WINDOW
	int m_screenW;
	int m_screenH;
	float m_timer;

	//	OBJECT
	Critter* m_critters[1000];

	Critter* m_destroyer;
	Vector2 m_nextSpawnPos;

	//	AVE FPS CALC
	int m_totalFPS = 0;
	int m_frameCount = 0;

public:

	Game();
	~Game();

	void Run();
};

