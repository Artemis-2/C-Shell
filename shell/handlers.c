#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
#include <signal.h>
	#include "myheader.h"

void interruptc()
{
	if(root_pid==getpid())
	{
	signal(SIGINT, interruptc);
	fflush(stdout); 
	}
}

void interruptz()
{
	if(root_pid==getpid())
	{
		//printf("^^^^\n");
		//printf("%d\n",this_pid );
		if(this_pid<0)
		{
		//printf("&&&&\n");
		}
		else
		{
		//	printf("oooo\n");
			for(int g=0;g<no_of_proc;g++)
			{
				if(proc_list[g].proc_id==this_pid)
				{
		//			printf("HRERER\n");
					proc_list[g].bg_flag=1;
					proc_list[g].proc_status=2;
					kill(this_pid, SIGTSTP);
				}
			}
		}
	}
	//print_command_line();
}