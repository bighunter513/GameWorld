
#include "AIContext.h"
#include <iostream>

using namespace std;

AIContext::AIContext(int id) : m_id(id), m_begin_tick(0)
{
}

AIContext::~AIContext()
{
}

void AIContext::tick(tick_t  cur_tick)
{
	if (m_begin_tick == 0)   m_begin_tick = cur_tick;

	cout << "Context: " << m_id << " tick: " << cur_tick << endl;

}


