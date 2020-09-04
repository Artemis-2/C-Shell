	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <signal.h>
	#include <grp.h>
	#include <sys/wait.h>
	#include "myheader.h"

void make_fg(char broke_inp[100][100])
{
	int job_no=atoi(broke_inp[1]);
	int old_pid=proc_list[job_no].proc_id;
	int stat=1;
	int ans=0;
	if(job_no<=no_of_proc)
	{
		proc_list[job_no].proc_status=0;
		proc_list[job_no].bg_flag=0;
		//kill the old process
		kill(old_pid, SIGCONT);
		ans=waitpid(old_pid,&stat,WUNTRACED);
		if(ans<0)
			printf("Error\n");

	}
	else
	{
		printf("Wrong job number\n");
	}

}


void make_bg(char broke_inp[100][100])
{
	int job_no=atoi(broke_inp[1]);
	int old_pid=proc_list[job_no].proc_id;
	int stat=1;
	int ans=0;
	if(job_no<=no_of_proc)
	{
		proc_list[job_no].proc_status=1;
		//kill the old process
		kill(old_pid, SIGCONT);
		

	}
	else
	{
		printf("Wrong job number\n");
	}

}