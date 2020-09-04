#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
#include "myheader.h"
void setenv_com(char broke_inp[100][100], int no_of_words)
{
	int w=0;
	while(strlen(broke_inp[w++])!=0)
		no_of_words++;
	if(no_of_words!=3)
		printf("Wrong number of arguments for this command\n");
	else
	{

		char* name1=(char*)malloc(100*sizeof(char));
		strcpy(name1,broke_inp[1]);
		char* name2=(char*)malloc(100*sizeof(char));
		strcpy(name2,broke_inp[2]);
		printf("%s    %s\n",name1,name2 );

		if(setenv(name1,name2,1)!=0)
			printf("An error occured\n");
	}

}