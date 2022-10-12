#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#include<pthread.h>


  static double elapsed_sec;//use of global variable hiding information.
 
struct timeval start;
struct timezone tz;
struct timeval stop;
 void start_timer(){
  
 	gettimeofday(&start, &tz);
  elapsed_sec=+start.tv_sec+1.0E-6*(start.tv_usec);
  
      //  printf("start time is %lf\n",elapsed_sec );

     
   //printf ("start time is sec, milliseconds: %d.%06d\n", (int)start.tv_sec, (int)start.tv_usec);
} 
float stop_timer(){
	gettimeofday(&stop, &tz);
   //printf (" stop time is : %d.%06d\n", (int)stop.tv_sec, (int)stop.tv_usec);
	    double new_time=stop.tv_sec+1.0E-6*(stop.tv_usec);//CONVERTING TIME IN MICROSECONDS TO SECONDS

     new_time-=elapsed_sec;
         //printf("the new_time converted is %lf\n ",new_time);

return (float)new_time;
	
}
//int main(){
 //start_timer();
//printf("time taken%f\n ",stop_timer());
//}





 
  
