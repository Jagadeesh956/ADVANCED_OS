#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
   void start_timer();
   float stop_timer();
int main(int argc, char const *argv[])
{   int size=atoi(argv[1]);
	char *buff =calloc(size,1024);
	int cpid;
	start_timer();
	if((cpid=fork())==0){
		for(int i=0;i<=size;i=i+4096){//got a warning with i+4096[no assignment]
			buff[i]='X';
			exit (0);
		}
	}
	else{
		int *status;
		waitpid(cpid,status,0);

	}
	printf("the time taken to create process for size %d K-Bytes is %fsec",size, stop_timer());
	/* code */
	return 0;
}