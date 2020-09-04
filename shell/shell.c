
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <signal.h>
	#include <grp.h>
	#include "myheader.h"
	

	// void swap(char*s1,char*s2)
	// {char* temp;*temp=*s1;*s1=*s2;*s2=*temp;}
	// void reverseStr(char str[200]) 
	// { 
	//     int n = strlen(str); 
	  
	//     // Swap character starting from two 
	//     // corner
	//     for (int i = 0; i < n / 2; i++) 
	//         swap(&str[i], &str[n - i - 1]); 
	// } 
	//string get_word(int i,)


	int main(void)
	{
		 char cwd[100]={0};
		 getcwd(cwd,100);
		 //printf("HERE\n");
		 	strcpy(home,cwd);
		 	root_pid=getpid();
		 
		
			while(1)
			{
			char main_inp[100];
			for(int i=0;i<100;i++)
				main_inp[i]='\0';
			//printf("HERE1\n");
			char c;int rdr=0;int sub_cmds=1;
			checkChild();
			print_command_line(home);
			//printf("HERE2\n");
			//NEW LINES!!!!!!
			this_pid=rdr-1;
  			setpgid(root_pid, root_pid);
  			tcsetpgrp(0, root_pid);
  			signal(SIGINT, interruptc);
  			signal(SIGTSTP, interruptz);
			while(1)
			{
				c=getchar();
				if(c==';')
				sub_cmds++;
		else		if(c!='\n'&&c!=EOF)
				{
					main_inp[rdr++]=c;
				}
				else
				{
				//	inp[rdr]='\0';
					break;
				}
			}
			//printf("here%s\n",main_inp);
			//printf("$$$%d\n",sub_cmds );	
			int lctr=0;
			int cmd_start=0;
			//TAKEN FROM HERE AND PUT INTO new_inp.c
			get_newcmd(sub_cmds,main_inp);

		
		}


		
		return 0;

	}