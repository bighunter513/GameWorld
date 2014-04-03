
#ifndef BIGHUNTER_TIME_UTILITY_H
#define BIGHUNTER_TIME_UTILITY_H

#include <time.h>
#include "../public/config.h"

typedef long tick_t;

// @return : return the tick count process running from start.
inline tick_t  get_current_tick()
{
	return  ( clock() * TICK_PER_SECOND / CLOCKS_PER_SEC );
}


#endif

