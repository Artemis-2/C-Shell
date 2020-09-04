#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"
//#include <string>
void get_pwd()
{
	char cwd[100];
	getcwd(cwd,100);
	printf("%s\n",cwd);

}