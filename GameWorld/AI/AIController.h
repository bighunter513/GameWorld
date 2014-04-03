
#ifndef BIGHUNTER_AI_CONTROLLER_H
#define BIGHUNTER_AI_CONTROLLER_H

#include "../common_macro.h"
#include "../utility/time_utility.h"
#include <list>

class AIContext;

typedef std::list<AIContext*>  AIContextContainer;

class AIController
{
public:
	static AIController* instance();
	~AIController();

	void tick(tick_t  cur_tick);

public:
	void add_context();


private:
	AIContextContainer   m_context_list;

private:
	DISALLOW_COPY_AND_ASSIGN(AIController);
};

#define getAIController()  AIController::instance() 

#endif