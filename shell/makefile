myheader: \
		shell.o \
		background.o \
		cd_com.o \
		cli.o \
		convert.o \
		echo_com.o \
		exe_com.o \
		handlers.o \
		jobs_com.o \
		ls_com.o \
		make_bg.o \
		new_inp.o \
		overkill_com.o \
		pinfo_com.o \
		piping.o \
		pwd_com.o \
		redir.o \
		setenv.o \
		unsetenv.o \

	$(CC) -g -o myheader $^

clean:
	@rm -f *.o myheader

background.o: myheader.h background.c
	$(CC) -g -c background.c

cd_com.o: myheader.h cd_com.c
	$(CC) -g -c cd_com.c

cli_com.o: myheader.h cli_com.c
	$(CC) -g -c cli_com.c

convert.o: myheader.h convert.c
	$(CC) -g -c convert.c
echo_com.o: myheader.h echo_com.c
	$(CC) -g -c echo_com.c

exe_com.o: myheader.h exe_com.c
	$(CC) -g -c exe_com.c

handlers.o: myheader.h handlers.c
	$(CC) -g -c handlers.c

jobs_com.o: myheader.h jobs_com.c
	$(CC) -g -c jobs_com.c

ls_com.o: myheader.h ls_com.c
	$(CC) -g -c ls_com.c

make_bg.o: myheader.h make_bg.c
	$(CC) -g -c make_bg.c

new_inp.o: myheader.h new_inp.c
	$(CC) -g -c new_inp.c

overkill_com.o: myheader.h overkill_com.c
	$(CC) -g -c overkill_com.c

pinfo_com.o: myheader.h pinfo_com.c
	$(CC) -g -c pinfo_com.c

piping.o:myheader.h piping.c
	$(CC) -g -c piping.c

pwd_com.o: myheader.h pwd_com.c
	$(CC) -g -c pwd_com.c

redir.o: myheader.h redir.c
	$(CC) -g -c redir.c

setenv.o: myheader.h setenv.c
	$(CC) -g -c setenv.c

shell.o: myheader.h shell.c
	$(CC) -g -c shell.c

unsetenv.o: myheader.h unsetenv.c
	$(CC) -g -c unsetenv.c

