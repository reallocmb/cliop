#include<stdio.h>
#include"types.h"

#include"c_internal.h"

void helpsite_show(char **arg, uint arg_count)
{
	printf("Helpsite !\n");

	void *end;
	for (end = &options_global.array[options_global.count]; options_global.array != end; options_global.array++)
    {
        printf("%c -> %s\n",
                (*options_global.array).option,
                (*options_global.array).description);
    }
}
