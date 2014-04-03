
#ifndef BIGHUNTER_AI_CONTEXT_H
#define BIGHUNTER_AI_CONTEXT_H

#include "../utility/time_utility.h"

class AIContext
{
public:
	explicit AIContext(int id);
	~AIContext();

	int get_id() const { return m_id;  }

	void tick(tick_t  cur_tick);

	tick_t  get_running_tick(tick_t cur_tick) { return (cur_tick - m_begin_tick);  }

private:
	int     m_id;
	tick_t  m_begin_tick;
};



#endif
