#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#include "myheader.h"
char result[100];
void replaceWord(char* s1,  char* oldW1, char* newW1) 
{ 
    char s[100];
    char oldW[100];
    char newW[100];
    strcpy(s,s1);
    strcpy(newW,newW1);
    strcpy(oldW,oldW1);
    for(int q=0;q<100;q++)
        result[q]='\0';

    int s_ind=-1;
    for(int i=0;i<strlen(s);i++)
    {
        for(int j=i;j<strlen(oldW)&&(i+j)<strlen(s);j++)
        {
           
            if(s[i+j]!=oldW[j])
                {s_ind=-1;break;}
            if(j==strlen(oldW)-1)
                {s_ind=j-strlen(oldW)+1;}
            if(s_ind!=-1)
                break;
        }
        
        if(s_ind!=-1)
            break;
    } 
    
  for(int z=0;z<s_ind;z++)
  {
    result[z]=s[z];
  }
  result[s_ind]='~';
  int i=s_ind+1;
  for(int z=s_ind+strlen(oldW);z<strlen(s);z++)
  {
    result[i++]=s[z];

  }
result[i]='\0';
    
} 
int sub_exists(char *str,char* search)
{
	int count1=strlen(str);
	int count2=strlen(search);
	int flag=0;
	for (int i = 0; i <= count1 - count2; i++)
    {
        for (int j = i; j < i + count2; j++)
        {
            flag = 1;
            if (str[j] != search[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return flag;

}
void print_command_line()
{
   // printf("HERE4\n");
	char *user=getenv("USER");
	printf("%s@",user);
	char host_name[100];
	gethostname(host_name,100);
	printf("%s:",host_name );
	char cwd[100];
	char *my_path=getcwd(cwd,100);
    //printf("***my_path:%s***",my_path);
	char *new_path=(char*)malloc(100*sizeof(char));
	strcpy(new_path,"");
	// printf("\n%s>\n",new_path );
	if(sub_exists(cwd,home))
	{
        char* aa=(char*)malloc(5*sizeof(char));
        replaceWord(cwd,home,aa);
        
        printf("%s>",result );

	}
	else printf("%s>",cwd);

	
	
	
}
