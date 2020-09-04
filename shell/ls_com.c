#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<pwd.h>
#include <grp.h>
#include <strings.h>
#include <string.h>
#include "myheader.h"

int isSubstring(const char s1[100], const char s2[100]) 
{ 
    int M = strlen(s1); 
    int N = strlen(s2); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M;i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 


void get_ls(char inp[100],char broke_inp[100][100])
{
  
  int flag_l=0;int flag_a=0;
  //printf("hjchdfg\n");
  for(int x=1;x<100;x++)
  {
    if(strcmp(broke_inp[x],"-l")==0)
      flag_l=1;
    if(strcmp(broke_inp[x],"-a")==0)
      flag_a=1;
    if(strcmp(broke_inp[x],"-la")==0)
      flag_l=1,flag_a=1;
    if(strcmp(broke_inp[x],"-al")==0)
      flag_l=1,flag_a=1;
   // printf("hii\n");

  }
  
 //printf("kjfgdsjkgf\n");
  struct passwd *pw;
  struct group *gp;
  DIR *mydir;
  char *c;
  int i;
  struct dirent *myfile;
  struct stat fileStat;
  int take_from=0;
  char arr_path[100]={0};
  for(int x=1;x<100;x++)
  {
    if(broke_inp[x][0]=='\0')break;
    if(strcmp(broke_inp[x],"-l")!=0&&strcmp(broke_inp[x],"-a")!=0&&strcmp(broke_inp[x],"-la")!=0&&
      strcmp(broke_inp[x],"-al")!=0&&strcmp(broke_inp[x],"&")!=0&&strcmp(broke_inp[x],"")!=0)
    {  //printf("YAY");
      strcpy(arr_path,broke_inp[x]);
      take_from=1;
      break;
    }
    //printf("gfeg\n");


  }
 // printf("%s\n",arr_path );
  //printf("take_from:%d",take_from);
  if(take_from==1)
    mydir=opendir(arr_path);
  else
  mydir=opendir(".");
  stat(".",&fileStat);
  //printf("Flags:%d  %d\n",flag_l,flag_a);
if(!mydir)perror("opendir");
  while((myfile=readdir(mydir))!=NULL)
  {
    //printf("@@@\n"); 
    
    stat(myfile->d_name,&fileStat); 
    //printf("@@@\n"); 
    if(flag_l==1)
    {
      if((flag_a==1&&myfile->d_name[0]=='.')||myfile->d_name[0]!='.')
      {
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-"); 
    printf(" ");

    printf("%lu ",fileStat.st_nlink);
    pw=getpwuid(fileStat.st_uid);
    printf("%s ",pw->pw_name);
    gp=getgrgid(fileStat.st_gid);
    printf("%s ",gp->gr_name);
    printf("%4d ",fileStat.st_size);
    c=ctime(&fileStat.st_mtime);
    for(i=4;i<=15;i++)
      printf("%c",c[i]);
    printf(" ");
  }
  }
  if((flag_a==1&&myfile->d_name[0]=='.')||myfile->d_name[0]!='.')
    printf("%s\n",myfile->d_name);

  }
  closedir(mydir);  
  
}