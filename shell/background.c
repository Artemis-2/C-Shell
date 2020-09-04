#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "myheader.h"

// extern int no_of_proc;
// typedef struct{
//   int proc_id;
//   char proc_name[100];
//   int proc_status;
//   int bg_flag;
// }my_proc;

// extern my_proc proc_list[1024];


void checkChild()
{
  // This function checks if the child process is still alive or not
  int st;
  int *status;
  pid_t a;
  status = &st;
  //FILE* statusf;
  //char path[70];
  //char processName[100];
  a= waitpid(-1, status, WNOHANG);
  if(a>0)
  {
    fprintf(stderr,"pid %d exicted Normally\n",a);
  //  printf("%d\n", a);
    for(int j=0;j<no_of_proc;j++)
    {
    //   printf("%d\n", proc_list[j].proc_id);
      if(proc_list[j].proc_id==a)
        proc_list[j].proc_status=0;
    }
    a= waitpid(-1, status, WNOHANG);
  
  }
}