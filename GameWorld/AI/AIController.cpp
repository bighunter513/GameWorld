
#include "AIContext.h"
#include "AIController.h"
#include <iostream>

using namespace std;

AIController::AIController()
{
}

AIController::~AIController()
{

}

AIController* AIController::instance()
{
	static AIController inst;
	return &inst;
}

void AIController::tick(tick_t  cur_tick)
{
	// for each AIContext
	// AIContext->tick() ?
	//cout << "tick: " << cur_tick << endl;

	{
		// for test
		if (cur_tick % 20 == 0)
		{
			AIContext*  cont = new AIContext(cur_tick);
			m_context_list.insert(m_context_list.end(), cont);
			cout << "add Context: " << cur_tick << " to list." << endl;
		}
	}

	for (auto context : m_context_list)
	{
		context->tick(cur_tick);
	}

	for (AIContextContainer::iterator itor = m_context_list.begin(); itor != m_context_list.end(); )
	{
		if ((*itor)->get_running_tick(cur_tick) >= 30)
		{
			cout << "remove Context: " << (*itor)->get_id() << " from list." << endl;
			itor = m_context_list.erase(itor);
		}
		else
		{
			++itor;
		}
	}
}

