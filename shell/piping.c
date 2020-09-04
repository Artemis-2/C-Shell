#include<stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h> 
#include "myheader.h"
int pipcount=0;

char** split_pipes(char inp[100])
{
	// printf("%s&&&\n",inp );
	int ctr=0;
	int ptr=0;
	char** broke_pipes=(char **)(malloc(sizeof(char)*100*100));
	for(int w=0;w<100;w++)
		broke_pipes[w]=(char *)malloc(sizeof(char)*100);
	for(int q=0;q<strlen(inp);q++)
	{
		if(inp[q]=='|')
		{
			broke_pipes[ctr][ptr]='\0';
			ctr++;
			ptr=0;
			pipcount++;
			// printf("##\n");
		}
		else
		{
			// printf("***\n");
			broke_pipes[ctr][ptr++]=inp[q];
		}
		

	}
	return broke_pipes;

}





void pipe_handler(char inp[100])
{
	int pid, status, prev, nxt;
	int saved_stdin = dup(0);
	int saved_stdout = dup(1);
	char** dumy=(char **)(malloc(sizeof(char)*100*100));
	for(int w=0;w<100;w++)
		dumy[w]=(char *)malloc(sizeof(char)*100);
	dumy=split_pipes(inp);
	char broke_pipes[100][100];
	for(int e=0;e<100;e++)
		{strcpy(broke_pipes[e],dumy[e]);
		//printf("%s\n",broke_pipes[e] );

		}		
		int parr[2];
	
	for (int ptr=0; ptr<=pipcount; ++ptr)
	{
		//write(2,"here!",5);
		
		
		if (ptr!=0)
		{
			//write(2,"here1",5);
			close(parr[1]);
			saved_stdin = dup(0);
			//close parr[1];
			dup2(parr[0], 0);
			close(parr[0]);
			//i++
		}
		if (ptr!=pipcount)
		{
			//write(2,"here2",5);
			pipe(parr);
			saved_stdout= dup(1);
			
			dup2(parr[1], 1);
			//close parr[0];
		}
		pid = fork();
		if (pid == 0)
		{
			//write(2,"plswrk",6);
			get_newcmd(1,broke_pipes[ptr]);
			exit(0);
		}
		else 
		{
			//write(2,"plspls",6);
			waitpid(pid, &status, WUNTRACED);
			dup2(saved_stdin,0);
			dup2(saved_stdout,1);
		}
	}
	//return 0;
}



