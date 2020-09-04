	#include<stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h> 
	#include <sys/stat.h>
	#include <math.h>
	#include<fcntl.h> 
	#include<errno.h>
	#include "myheader.h"
    char* trim1(char str[100])
    {	
    	char* tstr=(char *)malloc(100*sizeof(char));
    	char* fstr=(char *)malloc(100*sizeof(char));
    	int flag1=0;int q=0;
    	for(int i=0;i<strlen(str);i++)
    	{
    		if(str[i]!=' ')
    			{flag1=i;break;}

    	}
    	int flag2=0;int r=0;
    	for(int i=strlen(str)-1;i>=0;i--)
    	{
    		if(str[i]!=' ')
    			{flag2=i;break;}

    	}
    	//printf("%d    %d\n",flag1,flag2 );
    	for(int i=flag1;i<=flag2;i++)
    		fstr[q++]=str[i];
    	return fstr;

    }

	void redir_com(char inp[100], int flag)
	{
		printf("%s\n" ,inp);
		int i;
		int rptr=0; int rptr2=0;
		int case1=0;//filename<comd
		int case2=0;//comd>filename
		int case3=0;//command<inp>outp
		int d1=0;//<< is present
		int d2=0;//>> is present
		if(flag==1)
		{
			for( i=0;i<strlen(inp);i++)
			{
				if(inp[i]=='>')
				{
					rptr=i;
					case2=1;
					if(inp[i+1]=='>')
						d2=1;
					if(case1==1)
					{
						case1=case2=0;case3=1;
						rptr2=i;
					}
					
				}
				if(inp[i]=='<')
				{
					case1=1;
					rptr=i;
					if(inp[i+1]=='<')
						d1=1;
				}


			}
			if(case2==1)
			{
				//printf("HERE\n");
				char file_to_write[100];char com[100];int q=0;
				for(int k=rptr+1;k<strlen(inp);k++)
				{
					while(inp[k]=='>')
						k++;
					file_to_write[q++]=inp[k];
				}
				q=0;
				for(int k=0;k<rptr;k++)
				{
					if(inp[k]=='>')
						break;
					com[q++]=inp[k];
				}

				
				int saved_stdout=dup(1);

				char* temp=(char *)malloc(100*sizeof(char));
				// temp=trim1(file_to_write);
				// strcpy(file_to_write,temp);
				// temp=trim1(com);
				// strcpy(com,temp);
				// if(strlen(com)==0)
				// 	strcpy(com,"echo");
				int fd_to_write;
				if(d2==0)
				fd_to_write=open(file_to_write,O_WRONLY|O_CREAT|O_TRUNC, 0644);
				else
					fd_to_write=open(file_to_write,O_WRONLY|O_CREAT|O_APPEND, 0644);

				//printf("$$$$\n");
				dup2(fd_to_write, 1) ;
				//printf("zzzz\n");
				get_newcmd(1,com);
				//printf("****\n");

				//send the command to input to be executed
				
				close(fd_to_write);
				dup2(saved_stdout, 1) ;
				//dup(1);
			//	printf("hiii\n");
			}
			else if(case1==1)
			{
				int saved_stdout=dup(1);
				//printf("****\n");
				
				char file_to_write[100];char com[100];int q=0;
				for(int k=0;k<rptr;k++)
				{
					if(inp[k]=='<')
						break;
					file_to_write[q++]=inp[k];
				}
				q=0;
				for(int k=rptr+1;k<strlen(inp);k++)
				{
					if(inp[k]=='<')
						k++;
					com[q++]=inp[k];
				}
				//printf("%s\n",file_to_write);
				//printf("%s\n",com );
				char* temp=(char *)malloc(100*sizeof(char));
				// temp=trim1(file_to_write);
				// strcpy(file_to_write,temp);
				// temp=trim1(com);
				// strcpy(com,temp);
				// if(strlen(com)==0)
				// 	strcpy(com,"echo");
				/**printf("%s\n",file_to_write);
				printf("%s\n",com );
				printf("%d\n",d1 );**/
				int fd_to_write;
				if(d1==0)
				fd_to_write=open(file_to_write,O_WRONLY|O_CREAT|O_TRUNC, 0644);
				else
					fd_to_write=open(file_to_write,O_WRONLY|O_CREAT|O_APPEND, 0644);
				dup2(fd_to_write, 1) ;
				//send the command to input to be executed
				get_newcmd(1,com);
				close(fd_to_write);
				dup2(saved_stdout, 1) ;


			}
			else if(case3==1)
			{
			//	printf("(&&&&)\n" );
				char com[100];int q=0;int k;
				for( k=0;;k++)
					{
						if(inp[k]=='<')
							break;
						com[q++]=inp[k];
						
					}
					k++;
					if(d1==1)
						k++;
				char inpfile_name[100];q=0;
				for(;k;k++)
				{
					if(inp[k]=='>')
						break;
					inpfile_name[q++]=inp[k];
					
				}
				if(d2==1)
					k++;
				k++;
				char* temp=(char *)malloc(100*sizeof(char));
				temp=trim1(inpfile_name);
				strcpy(inpfile_name,temp);
				char outfile_name[100];q=0;
				for(;k<strlen(inp);k++)
					{outfile_name[q++]=inp[k];}
				//printf("%s\n",temp );
				temp=trim1(outfile_name);
				//printf("%s\n",temp );
				strcpy(outfile_name,temp);
				//printf("(%s)\n",com );
				//printf("%s\n",inpfile_name );
				//printf("%s\n",outfile_name );


				int fd_to_read=open(inpfile_name,O_RDONLY,0644);
				int fd_to_write;
				if(d2==0)
					fd_to_write=open(outfile_name,O_WRONLY|O_CREAT|O_TRUNC, 0644);
				else
					fd_to_write=open(inpfile_name,O_WRONLY|O_CREAT, 0644);
				int saved_stdin=dup(0);
				int saved_stdout=dup(1);
				dup2(fd_to_read,0);
				dup2(fd_to_write,1);
				get_newcmd(1,com);
				close(fd_to_read);
				close(fd_to_write);
				dup2(saved_stdin,0);
				dup2(saved_stdout,1);

				

			}

		}
	
	
	}