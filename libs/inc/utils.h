#pragma once

typedef void (*Util_func)(void *);

struct utils {
	Util_func util_func;
	char *name;
};

int register_utils(struct utils *);

void endianchk (void *);
