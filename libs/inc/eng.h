#pragma once

#include <utils.h>

#define MAX_SIZE (50) //controlled by developer

struct eh_engine {
	struct utils util[MAX_SIZE];
	unsigned int count;
};	


