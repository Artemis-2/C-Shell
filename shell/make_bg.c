	#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "myheader.h"
// typedef struct myproc22
// {
// 	int pid_no;
// 	char proc_name[100];
// }MYPROC22;
// MYPROC22 tryproc11[100];
// extern int curr_proc2;
// extern int no_of_proc;

// typedef struct{
// 	int proc_id;
// 	char proc_name[100];
// 	int proc_status;
// 	int bg_flag;
// }my_proc;

// extern my_proc proc_list[1024];

void get_to_bg(int is_a_bg,char inp[100],char broke_inp[100][100])
{
	//printf("IM CALLED!\n");
	strcpy(proc_list[no_of_proc].proc_name,broke_inp[0]);
	proc_list[no_of_proc].proc_status=1;
	proc_list[no_of_proc].bg_flag=1;
    //printf("%d\n",proc_list[no_of_proc].proc_status );
     //printf("%d\n",proc_list[no_of_proc].bg_flag );
	
	//printf("AAAA\n");	char * try1;
    // this_pid=1;
	char ** args;

args=(char**)malloc(100*sizeof(char*));
	for(int f=0;f<100;f++)
	{
		if(strcmp(broke_inp[f],"&")==0)args[f]=NULL;
	else	if(broke_inp[f]!=NULL && broke_inp[f][0]!='\0'){
		args[f]=(char*)malloc(100*sizeof(char));
				strcpy(args[f],broke_inp[f]);
			}
	else args[f]=NULL;
}

	int pid=fork();
    proc_list[no_of_proc++].proc_id=pid;
    // this_pid=pid;

	if(pid==0)
	{
	
	//printf("***\n" );
	if (execvp(args[0], args) < 0) 
		{
			printf("Error\n");
		}
		exit(0);

	}
	else
	{
	//	int stat1=0;
	//	waitpid(pid, &stat1, WUNTRACED);

			
	}
	//my_proc[no_of_proc-1].proc_status=0;
	
		// strcpy(tryproc11[curr_proc2].proc_name, broke_inp[0]);
		// 		tryproc11[curr_proc2].pid_no = pid;	
		// 		return tryproc11;		
	
}


		
	
