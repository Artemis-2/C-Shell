int no_of_proc;

typedef struct{
	int proc_id;
	char proc_name[100];
	int proc_status;
	int bg_flag;
}my_proc;

my_proc proc_list[1024];
int root_pid;
int this_pid;

char home[100];

void exe_jobs();
void checkChild();
void get_cd(char broke_inp[100][100],char home[100]);
void redir_com(char inp[100], int flag);
void replaceWord(char* s,  char* oldW, char* newW) ;
void get_echo(char broke_inp[100][100],char inp[100]);
void send_com(int bg_flag, char inp[100], char broke_inp[100][100]);
void get_newcmd(int sub_cmds,char main_inp[100]);
int isSubstring(const char s1[100], const char s2[100]) ;
void get_ls(char inp[100],char broke_inp[100][100]);
// extern int curr_proc2;
void get_to_bg(int is_a_bg,char inp[100],char broke_inp[100][100]);
void get_newcmd(int sub_cmds,char main_inp[100]);
void exe_overkill();
void get_pinfo(int pid);
void get_pwd();
void setenv_com(char broke_inp[100][100], int no_of_words);
void swap(char*s1,char*s2);
void reverseStr(char str[200]); 
void unsetenv_com(char broke_inp[100][100], int no_of_words);
void print_command_line( );
void interruptc();
void interruptz();
void make_fg(char broke_inp[100][100]);
void make_bg(char broke_inp[100][100]);
void exe_kjob(char broke_inp[100][100]);
void piping_com(char inp[100]);
void pipe_handler(char inp[100]);




