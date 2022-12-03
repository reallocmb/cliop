#ifndef C_INTERNAL_H
#define C_INTERNAL_H

#include"types.h"

typedef struct {
	char option;
	char description[100];
	void (*exec_func)(char **arg, uint arg_count);
} Option;

/* store all options */
typedef struct {
	Option *array;
	uint count;
} OptionsGlobal;

extern OptionsGlobal options_global;

#endif
