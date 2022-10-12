#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
void start_timer();
float stop_timer();

void *child(char* arr[]){
     char *buff = *(char**)arr;
    int size= sizeof(&arr);
    for(int i=0;i<=size;i=i+4096){//got a warning with i+4096[no assignment]
			 buff[i]='X';
			exit (0);
		}
    	return 0;
}
int main(int argc, char const *argv[]){  

	int size=atoi(argv[1]);
	char *buff =calloc(size,1024);
             
	
	      
	start_timer();
	pthread_t th;
	//printf("thread created");
		if(pthread_create(&th,NULL,(void*)child,buff)!=0){
		pthread_join(th,NULL);

	}
		printf("the time taken to create thread for size %d K-Bytes is %f",size, stop_timer());

}

