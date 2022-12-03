#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"c_internal.h"

OptionsGlobal options_global;

#define OPTION_ALLOC_SIZE 20

void cliop_option_append(char option, char *description, void *exec_func)
{
    static _Bool init = false;

    if (!init)
    {
        options_global.array = malloc(OPTION_ALLOC_SIZE * sizeof(Option));
        init = true;
    }

    if (options_global.count % OPTION_ALLOC_SIZE == 0)
        options_global.array = realloc(options_global.array, (options_global.count + OPTION_ALLOC_SIZE) * sizeof(Option));

	options_global.array[options_global.count].option = option;
	strncpy(options_global.array[options_global.count].description, description, 100);
	options_global.array[options_global.count++].exec_func = exec_func;
}

Option *get_option(char option)
{
	void *end;
	for (end = &options_global.array[options_global.count]; options_global.array != end; options_global.array++)
		if ((*options_global.array).option == option)
			return options_global.array;

	return NULL;
}

void cliop_option_exec(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Give me some Args!!!:)\n");
        return;
	}
	Option *option = NULL;
	char **arg = malloc(10 * sizeof(char *));
	uint arg_count = 0;
	if (arg == NULL)
		return;

	/* go thrue all arguments */
	void *end;
	argv++;
	for (end = &argv[argc - 1]; argv != end; argv++)
	{
		/* check for option */
		if ((*argv)[0] == '-' || argv == end - 1)
		{
			if (option != NULL)
			{
				option->exec_func(arg, arg_count);
				arg_count = 0;
			}

			option = get_option((*argv)[1]);
			if (option == NULL)
			{
				fprintf(stderr, "Can't find the option <-%c>\n", (*argv)[1]);
				exit(1);
			}
		} else
		{
			arg[arg_count++] = *argv;
		}
	}

	option->exec_func(arg, arg_count); /* execute last option */
}
