#ifndef CLIOP_H
#define CLIOP_H

#define VERS_CLIOP_MAJOR 0
#define VERS_CLIOP_MINOR 0
#define VERS_CLIOP_PATCH 0

#include"types.h"

void cliop_option_append(char option, char *description, void *exec_func); /* append a option to Global Options */
void cliop_option_exec(int argc, char **argv); /* read and execute all options their given */

#define HELPSITE_FUNCTION helpsite_show
void helpsite_show(char **arg, uint arg_count);

#endif
