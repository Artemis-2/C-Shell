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

void exe_jobs()
{
	printf("JOB NO  		JOB NAME 		JOB PID 		FG/BG 		STATE\n");
	for(int i=0;i<no_of_proc;i++)
		{
			
			printf("%d 		",(i) );
			printf("%s 		",proc_list[i].proc_name);
			printf("%d 		",proc_list[i].proc_id);
			//printf("%d",proc_list[i].bg_flag );
			if(proc_list[i].bg_flag==0)
				printf("FG         ");
			else
				printf("BG         ");
			//printf("%d",proc_list[i].proc_status );
			if(proc_list[i].proc_status==0)
				printf("Killed		\n");
			else if(proc_list[i].proc_status==1)
				printf("Running 		\n");
			else
				printf("Stopped 		\n");

		}


	return;

}