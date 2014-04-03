/*********************************************************************************
 @ file: game_app.h
 @ brief: The Main application of Game
 @ Author: guoxiaolin
 @ Create Date: 2014/04/03
 @ Change log:
  
 Copyright@2014  DeNA Corp.
 *********************************************************************************/


#ifndef BIGHUNTER_GAME_APP_H
#define BIGHUNTER_GAME_APP_H

#include "utility/time_utility.h"

class GameApp
{
	enum APP_STATUS { NOT_INIT=0, READY, RUNNING, STOP  };
public:
	static GameApp* instance();
	~GameApp();

	int  init();
	int  run();
	void fini();

	void stop() { m_status = STOP; }

public:
	tick_t      m_start_tick;
	tick_t      m_cur_tick;

private:
	GameApp();
	GameApp(const GameApp&);
	GameApp& operator=(const GameApp&);

private:
	APP_STATUS  m_status;
	
};

#define get_app()  GameApp::instance() 

#endif
