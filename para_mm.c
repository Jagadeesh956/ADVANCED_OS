#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
void start_timer();
float stop_timer();
static int thread_count=0;
int A[320][320]={1};
	int B[320][320]={1};
	int C[320][320]={1};

void *Matrix_multiply(void* arg){
	long tid= (long)arg;
	printf("the thread count  %d\n",thread_count);
	     int start = (tid-1)*320/thread_count;
		int end = tid*320/thread_count;
	printf("the tid is :%ld\n and length is %d\n",tid,end);
	for(int i=start-1;i<end;i++){
		for(int j=i;j<320;j++){
			 for(int k=start-1;k<end;k++){
			 	C[i][j]+=A[i][k]*B[k][i];
			 }
			 
			 }
	 		 
	}
	printf("finished part %d\n",(int)tid);
	for(int i=start;i<end;i++){
		for(int j=0;j<320;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
 return 0;	
}



int main(int argc, char const *argv[])
{              start_timer();
           thread_count= atoi(argv[1]);
             pthread_t tid[thread_count];
             printf("count is %d",thread_count);
           for(long i=1;i<=thread_count;i++){
		
	  pthread_create(&tid[i],NULL,Matrix_multiply, (void* )i);
	  pthread_join(tid[i],NULL);

		    //printf("created: thread %d",(int )i); 	

	}
	     


          
	printf("time taken to do using %d threads is %f\n",thread_count, stop_timer());
}