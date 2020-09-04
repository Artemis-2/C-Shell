#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include<fcntl.h> 
#include<errno.h>
#include "myheader.h"
	//#include <string>

	// #include "cli.c"
	// #include "pwd_com.c"
	// #include "cd_com.c"
	// #include "pinfo_com.c"
	// #include "background.c"
	// #include "echo_com.c"
	// #include "ls_com.c"
	// #include "make_bg.c"
void send_com(int bg_flag, char inp[100], char broke_inp[100][100])
{
	
		//printf("%d\n",bg_flag );
	//printf("hererer\n");
	//printf("%s\n",broke_inp[0] );
	checkChild();
		if(strcmp(broke_inp[0],"")==0)
		{
			return;
		}
		if(strcmp(broke_inp[0],"quit")==0)
		{
			exit(0);
		}
		else if(bg_flag==1)
		{
			get_to_bg(bg_flag,inp,broke_inp);
		}
		else if(strcmp(broke_inp[0],"cd")==0)
		{
			get_cd(broke_inp,home);
		}
		else if(strcmp(broke_inp[0],"ls")==0)
		{
			get_ls(inp,broke_inp);	
		}
		else if(strcmp(broke_inp[0],"echo")==0)
		{
			get_echo(broke_inp,inp);

		}
		else if(strcmp(broke_inp[0],"setenv")==0)
		{
			setenv_com(broke_inp,0);
		}
		else if(strcmp(broke_inp[0],"pwd")==0)
		{
			get_pwd();
		}
		else if(strcmp(broke_inp[0],"unsetenv")==0)
		{
			unsetenv_com(broke_inp,0);
		}
		else if(strcmp(broke_inp[0],"pinfo")==0)
		{
			// int n=strlen(broke_inp[1]);
			// int passer=0;
			// for(int h=n-1;h>=0;h--)
			// {
			// 	passer=passer*10+(int)(broke_inp[1][h]-'0');

			// }
			get_pinfo(atoi(broke_inp[1]));
		}
		else if(strcmp(broke_inp[0],"overkill")==0)
		{
			exe_overkill();
		}
		else if(strcmp(broke_inp[0],"jobs")==0)
		{
			//printf("$$$\n");
			exe_jobs();
		
		}
		else if(strcmp(broke_inp[0],"fg")==0)
		{
			make_fg(broke_inp);
		}
		else if(strcmp(broke_inp[0],"bg")==0)
		{
			make_bg(broke_inp);
		}
		else if(strcmp(broke_inp[0],"kjob")==0)
		{
			exe_kjob(broke_inp);
		}

		else 
		{
			//printf("FORK");
			int pid=fork();
			this_pid=pid;
			int stat1=0;
			// if(pid!=0){
			// 	//printf("Parent");
			// 	waitpid(pid, &stat1, WUNTRACED);
			// }
			char **args;
				args=(char**)malloc(100*sizeof(char*));
				for(int f=0;f<100;f++)
				{
					if(broke_inp[f]!=NULL && broke_inp[f][0]!='\0')
					{
						args[f]=(char*)malloc(100*sizeof(char));
						strcpy(args[f],broke_inp[f]);
					}
					else args[f]=NULL;
				}
			if(pid==0)
			{
				//printf("CHILD");
				//printf("%s\n",args[0] );
				if(execvp(args[0],args)<0)		
					printf("Command not found\n");
				exit(0);
			}
			else {int stat1=0;
				strcpy(proc_list[no_of_proc].proc_name,broke_inp[0]);
			proc_list[no_of_proc].proc_status=1;
			proc_list[no_of_proc].bg_flag=0;
			proc_list[no_of_proc++].proc_id=pid;
		waitpid(pid, &stat1, WUNTRACED);

			}
			//checkChild();
			
		}
}