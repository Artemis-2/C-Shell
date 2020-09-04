#include <stdio.h>
#include<string.h>
#include "myheader.h"
void get_echo(char broke_inp[100][100],char inp[100])
{

if(strcmp(broke_inp[1],"")==0)
{
	printf("\n");
}
else
{
	for(int i=0;i<strlen(inp);i++)
	{
		if(inp[i]=='e'&& inp[i+1]=='c'&&inp[i+2]=='h'&& inp[i+3]=='o')
		{
			
			for(int j=i+5;j<strlen(inp);j++)
				printf("%c",inp[j]);
			break;

		}
		printf("\n");
		
	}
	// char arr[100]=inp.substr(i+1,strlen(inp)-1);
	// printf("%s\n",r );
	printf("\n");
}
}