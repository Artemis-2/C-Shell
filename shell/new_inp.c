#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
//#include "exe_com.c"
#include "myheader.h"
void get_newcmd(int sub_cmds,char main_inp[100])
{
	
	int cmd_start=0;
	int lctr=0;
	while(lctr<sub_cmds)
			{
				char inp[100]={0};
				
				int cpyptr=0;
				//printf("@@@\n");
				//printf("^^^%d\n",lctr);
				while(main_inp[cmd_start]!=';'&& cmd_start<strlen(main_inp))
				{
					inp[cpyptr++]=main_inp[cmd_start++];



				}
				cmd_start++;

				//printf("here###%s\n",inp );

			char broke_inp[100][100]; 
			int bg_flag=0; 
			int flagp=0;
			int flagr=0;

			 for(int v=0;v<100;v++)
			 {
			 	for(int c=0;c<100;c++)
			 		broke_inp[v][c]='\0';
			 }
		int ptr=0;int ctr=0;
		for(int s=0;s<strlen(inp);s+=0)
		{
			if(inp[s]=='>'||inp[s]=='<')
						flagr=1;
					if(inp[s]=='|')
						flagp=1;
			if(inp[s]!=' ')
			{
				broke_inp[ctr][ptr]=inp[s];
				ptr++;
				s++;
			}
			else
			{
				
				while(inp[s]==' ')
				{
					s++;
				}
				//broke_inp[ctr][ptr]='\0';
				if(strcmp(broke_inp[ctr],"&")==0)
					bg_flag=1;
			//	printf("***%s\n", broke_inp[ctr]);
				ctr++;
				ptr=0;

			}
		}

		broke_inp[ctr][ptr]='\0';
		if(strcmp(broke_inp[ctr],"&")==0)
					bg_flag=1;
		//TAKEN FROM HERE!!!!
				//printf("%d\n",flagr);
				if(flagp==1)
					pipe_handler(inp);
				else if(flagr==1)
					redir_com(inp,flagr);
				else
		send_com(bg_flag,inp, broke_inp);
		
			lctr++;
		}
	}