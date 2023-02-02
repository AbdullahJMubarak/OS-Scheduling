#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct process
{    char *Name;
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int completion_time;
};
int main()
{
	// int n,i;
	// printf("Enter number of processes: ");
	// scanf("%d",&n);
	// struct process proc[n];
	// for(i=0;i<n;i++)
	// { 	printf("\n");
	// 	printf("Enter process name: ");
	// 	scanf("%s",proc[i].Name);
	// 	printf("\n");
	// 	printf("Enter arrival time for process%d: ",i+1);
	// 	scanf("%d",&proc[i].arrival_time);
	// 	printf("Enter burst time for process%d: ",i+1);
	// 	scanf("%d",&proc[i].burst_time);
	// 	proc[i].process_id = i+1;
	// }
	char *token;
int i,n,metN,period,q;
char pt[20] ,c2[20];
scanf("%s",pt);
// printf("\n  the printing way :%s",pt);
scanf("%d",&metN);
if(metN == 2){
	scanf("%d",&q);
	q=q*-1;
	printf("the quantam : %d \n",q);
}
// printf("\n the method :%d",metN);

scanf("%d",&period);    /* code */

// printf("\n the period %d",period);
scanf("%d",&n);    /* code */

// printf(" \n the no of processes :%d",n);
struct process proc[n];
scanf("%s",c2);
char s[2] = ",";
token = strtok(c2, s);
// printf("\n");
char in[n][n];
for (int i = 0; i < n; i++)
{

 proc[i].Name= (char*) malloc(20*sizeof(char));



// while( token != NULL ) {
    //  printf( " name :%s\n", token );
     strcpy(in[i],token);
    proc[i].Name=in[i];
      token = strtok(NULL, s);
        //    printf( " %s\n", token );

    proc[i].arrival_time= atoi (token);
     token = strtok(NULL, s);
    //   printf( " %s\n", token );
    proc[i].burst_time= atoi (token);
//    }
if(i != (n-1)) {
   scanf("%s",c2);
 token = strtok(c2, s);
 }else {
 
    break;}
    
}
// printf("\n out of loop");
// for (int i = 0; i < n; i++)
// {

//   printf(" \n process no %d name : %s ",i , proc1[i].c);
// //  printf(" \n process no %d name : %s ",i , in[i]);
//    printf(" \n process no %d arrive : %d ", i,proc1[i].x);
//     printf(" \n process no %d brust : %d",i , proc1[i].y);
// }


// if( metN ==1){

	int service_time[n];
	service_time[0]=0;
	proc[0].waiting_time=0;	

	for(i=1;i<n;i++)
	{
		service_time[i]=service_time[i-1]+proc[i-1].burst_time;
		proc[i].waiting_time = service_time[i]-proc[i].arrival_time;

		if(proc[i].waiting_time<0)
			proc[i].waiting_time=0;
	}

	for(i=0;i<n;i++)
	{
		proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
	}
	// printf("\n\n");
	// printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
	int total_waiting_time=0,total_turn_around_time=0;
	for(i=0;i<n;i++)
	{
		total_waiting_time+=proc[i].waiting_time;
		total_turn_around_time+=proc[i].turn_around_time;

		proc[i].completion_time=proc[i].turn_around_time + proc[i].arrival_time;

		// printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].process_id,proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time,proc[i].turn_around_time,completion_time);
	}
	printf("FCFS\n");
	// printf("Average waiting time: %f\n", (float)total_waiting_time/n);
	// printf("Average turn around time: %f\n",(float)total_turn_around_time/n);
	printf("Process    |");

	for(i=0;i<n;i++)
	{
		printf("  %s  |",proc[i].Name);
	}
	printf("\n");
	printf("Arrival    |");
	
	for(i=0;i<n;i++)
	{
		printf(" %2d  |",proc[i].arrival_time);
	}
	printf("\n");
	printf("Service    |");
	for(i=0;i<n;i++)
	{
		printf(" %2d  |",proc[i].burst_time);
	}
	printf(" Mean|");
	printf("\n");
	printf("Finish     |");
	for(i=0;i<n;i++)
	{
		printf(" %2d  |",proc[i].completion_time);
	}
	printf("-----|");
	printf("\n");
	printf("Turnaround |");
	float meant;
	meant=0;
	for(i=0;i<n;i++)
	{
		printf(" %2d  |",proc[i].turn_around_time);
        meant+=proc[i].turn_around_time;
	}
	meant=(meant)/((float) n);
    printf(" %.2f|",meant);
	printf("\n");
    printf("NormTurn   |");
		float meanN,temp;
		meanN=0;
	for(i=0;i<n;i++)
	{
	
		
		temp =    ((float) proc[i].turn_around_time) / ((float) proc[i].burst_time);
		meanN+=temp;
		printf(" %.2f|",temp);
	}
	meanN=(meanN)/((float) n);
    printf(" %.2f|",meanN);
	//jjkkhjj
    printf("\n");
	// else {







		
	// }
}