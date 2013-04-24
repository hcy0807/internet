#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>

int main()
{
    int fd[2];
    char buf[4096];
    int n;
    int status;
    pid_t pid;
    const char* hello = "Hello World";
    pipe(fd);
    pid = fork();
    if(pid<0){
	perror("fork failed\n");
	exit(1);
    }
    if(pid==0){
	close(fd[0]);
	write(fd[1],hello,strlen(hello));
	exit(0);
    }
    else{
	close(fd[1]);
	wait(&status);
	n = read(fd[0],buf,strlen(hello));
	buf[n]='\0';
	printf("The buffer is %s\n",buf);
    }
    return 0;
}
