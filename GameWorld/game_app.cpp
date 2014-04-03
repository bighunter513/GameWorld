/*********************************************************************************
@ file: game_app.cpp
@ brief: The Main application of Game
@ Author: guoxiaolin
@ Create Date: 2014/04/03
@ Change log:

Copyright@2014  DeNA Corp.
*********************************************************************************/
#include "game_app.h"
#include <iostream>
#include "error_code.h"
#include "AI/AIController.h"

using namespace std;

GameApp::GameApp() : m_status(NOT_INIT)
{
}

GameApp::~GameApp()
{
	fini();
}

GameApp* GameApp::instance()
{
	static GameApp inst;
	return &inst;
}

int  GameApp::init()
{
	m_status = READY;
	m_cur_tick = m_start_tick = get_current_tick();
	return 0;
}

int GameApp::run()
{
	if (m_status != READY) 
	{
		cout << "GameApp need init first." << endl;
		return EC_INVALID_STATUS;
	}

	cout << "Welcome to bighunter's GameWorld." << endl;
	m_status = RUNNING;

	m_cur_tick = get_current_tick();
	getAIController()->tick(m_cur_tick);
	m_cur_tick++;

	while (m_status == RUNNING)
	{
		// while wait timeout
		// call aicontroller->tick()
		while (get_current_tick() < m_cur_tick + 1)
		{
			; // no op , simulate wait
		};

		tick_t  now = get_current_tick();
		while (now >= m_cur_tick + 1)
		{
			getAIController()->tick(m_cur_tick);
			
			// for test
			if (m_cur_tick >= 100) return EC_SUCCESS;

			m_cur_tick++;
		};
	}

	return EC_SUCCESS;
}

void GameApp::fini()
{
	return;
}


