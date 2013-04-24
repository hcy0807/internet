#include<stdio.h>
#include<unistd.h>
//#include<cerrno>
#include<string.h>
#include<stdlib.h>

//using namespace std;

int main(void)
{
    int fd[2];
    char buf[4096];
    int n;
    const char* hello = "Hello World";
    pipe(fd);
    n = write(fd[1],hello,strlen(hello));
    if(n < 0){
	perror("write error");
	exit(1);}
    n = read(fd[0],buf,strlen(hello));
    if(n < 0){
	perror("read error");
	exit(1);}
    buf[n] = '\n';
    printf("%s\n",hello);
    return 0;
}
