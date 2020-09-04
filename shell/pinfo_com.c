#include<stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <string>
#include<stdio.h>
#include "myheader.h"
// typedef struct myproc
// {
//    int pid_no;
//    char proc_name[100];
// }MYPROC;
// MYPROC tryproc[100];
//int curr_proc=0;
//int child_pid=0;
// char result[100];
// void replaceWord(char* s,  char* oldW, char* newW) 
// { 
    
//     int i, cnt = 0; 
//     int newWlen = strlen(newW); 
//     int oldWlen = strlen(oldW); 
  
//     // Counting the number of times old word 
//     // occur in the string 
//     for (i = 0; s[i] != '\0'; i++) 
//     { 
//         if (strstr(&s[i], oldW) == &s[i]) 
//         { 
//             cnt++; 
  
//             // Jumping to index after the old word. 
//             i += oldWlen - 1; 
//         } 
//     } 
  
//     // Making new string of enough length 
//     // result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
//     i = 0; 
//     while (*s) 
//     { 
//         // compare the substring with the result 
//         if (strstr(s, oldW) == s) 
//         { 
//             strcpy(&result[i], newW); 
//             i += newWlen; 
//             s += oldWlen; 
//         } 
//         else
//             result[i++] = *s++; 
//     } 
  
//     result[i] = '\0'; 
    
// } 

void get_pinfo(int pid)
{		
	  
		char path[100];
		sprintf(path,"/proc/%d/status",pid);

		FILE * filepointer = fopen(path,"r");
		if(filepointer==NULL)
		{
			printf("Unable to open status File, No Process of given pid %d\n",pid);
			return;
		}
		char procInfo[100];
		while(fgets(procInfo,sizeof(procInfo), (FILE*)filepointer)!=NULL)
		{
			if(strncmp("VmRSS:",procInfo,strlen("VmRSS"))==0)
				break;
		}
		printf("pid -- %d\n",pid);
		printf("%s","Process Status -- {R/S/S+/Z}\n" );
   		char* token = strtok(procInfo, " \n");
        token = strtok(NULL, " \n");
        printf("Memory-- %s {Virtual Memory}\n", token);
   		fclose(filepointer);
   		char exePath[200];
      printf("Executable path--");
   		sprintf(path,"/proc/%d/exe",pid);
   		readlink(path,exePath,sizeof(exePath));
   		char currentWD[200];
   		getcwd(currentWD,sizeof(currentWD));
   		char* exePath1 = exePath;
         char* mycon=(char*)malloc(100*sizeof(char));
         strcpy(mycon,"~");
   		// if(strncmp(currentWD,exePath,strlen(currentWD))==0)
   		// replaceWord(exePath,currentWD,mycon);
     //  exePath1=result;

   		printf("%s\n\n",exePath1);
      

   	}
   	