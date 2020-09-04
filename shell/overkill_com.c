#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include "myheader.h"

// extern int no_of_proc;

// typedef struct{
// 	int proc_id;
// 	char proc_name[100];
// 	int proc_status;
// 	int bg_flag;
// }my_proc;

// extern my_proc proc_list[1024];

void exe_overkill()
{
	for(int i=0;i<no_of_proc;i++)
		{
			kill(proc_list[i].proc_id,SIGKILL);
			proc_list[i].proc_status=0;
		}
	return;

}
void exe_kjob(char broke_inp[100][100])
{
	int job_no=atoi(broke_inp[1]);
	int sig_no=atoi(broke_inp[2]);
	if(job_no<no_of_proc&& sig_no>=1&& sig_no<=30)
	{
	if(sig_no==1||sig_no==2||sig_no==9||sig_no==10||sig_no==13||sig_no==14||sig_no==15||sig_no==16
	||sig_no==30||sig_no==31)//terminate process
	{
		proc_list[job_no].proc_status=0;
	}
	else if(sig_no==20||sig_no==17||sig_no==18)
	{
		proc_list[job_no].proc_status=2;
	}
	else if(sig_no==25)
	{
		proc_list[job_no].proc_status=1;
	}
	kill(proc_list[job_no].proc_id, sig_no);
}
else
printf("Error\n");


}