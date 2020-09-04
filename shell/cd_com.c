#include<stdio.h>
//#include<string>
#include<string.h>
#include<unistd.h>
#include "myheader.h"

void get_cd(char broke_inp[100][100],char home[100])
{
	if(strcmp(broke_inp[1],"")==0||strcmp(broke_inp[1],"~")==0)
	{
		chdir(home);
	}
	else if(strcmp(broke_inp[1],"..")==0)
	{
		chdir("..");
	}
	else if(strcmp(broke_inp[1],".")==0) 
	{
		//no action taken
	}
	else 
	{
		
		
			if(chdir(broke_inp[1])!=0)
			{
				printf("Error\n");
			}
		
		}
	}

	

