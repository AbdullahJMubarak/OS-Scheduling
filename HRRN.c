#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Defining process details
struct process {
    int process_id;
    char *Name;
    int arrival_time, burst_time, ct, waiting_time, turn_around_time;
    int completed;
    int completion_time;
    int remaining_time;
    float ntt;
} proc[10];
 
 int n;
 
// Sorting Processes by Arrival Time
void sortByArrival()
{
    struct process  temp;
    int i, j;
 
    // Selection Sort applied
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
 
            // Check for lesser arrival time
            if (proc[i].arrival_time > proc[j].arrival_time) {
 
                // Swap earlier process to front
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}
 
void main()
{
    int i, j, t, sum_bt = 0;
    char c;
    float avgwt = 0, avgtt = 0;
    
   
    // int n,i,j;
    struct process temp;
	int bt=0,k=1,tat=0,sum=0,min;
    	char *token;
	int metN, period, q;
	char pt[20], c2[20];
	scanf("%s", pt);
	// printf("\n  the printing way :%s", pt);
	scanf("%d", &metN);
	if (metN == 2)
	{
		scanf("%d", &q);
		q = q * -1;
		// printf("\nthe quantam : %d \n", q);
	}
	// printf("\n the method :%d", metN);

	scanf("%d", &period); /* code */

	// printf("\n the period %d", period);
	scanf("%d", &n); /* code */

	// printf(" \n the no of processes :%d", n);
	// struct process proc[n];
	scanf("%s", c2);
	char s[2] = ",";
	token = strtok(c2, s);
	// printf("\n");
	char in[n][n];
	for (i = 0; i < n; i++)
	{

		proc[i].Name = (char *)malloc(20 * sizeof(char));

		// while( token != NULL ) {
		// printf(" name :%s\n", token);
		strcpy(in[i], token);
		proc[i].Name = in[i];
		token = strtok(NULL, s);
		// printf(" %s\n", token);

		proc[i].arrival_time = atoi(token);
		token = strtok(NULL, s);
		// printf(" %s\n", token);
		proc[i].burst_time = atoi(token);
	
		proc[i].remaining_time = proc[i].burst_time;
		//    }
        proc[i].completed = 0;
         sum_bt += proc[i].burst_time;
        proc[i].process_id = i+1;
		if (i != (n - 1))
		{
			scanf("%s", c2);
			token = strtok(c2, s);
		}
		else
		{
			// printf("break");
			break;
		}
	}
    // n = 5;
 
    // predefined arrival times
    // int arriv[] = { 0, 2, 4, 6, 8 };
 
    // // predefined burst times
    // int burst[] = { 3, 6, 4, 5, 2 };
 
    // // Initializing the structure variables
    // for (i = 0, c = 'A'; i < n; i++, c++) {
    //     proc[i].Name = "c";
    //     proc[i].arrival_time = arriv[i];
    //     proc[i].burst_time = burst[i];
 
    //     // Variable for Completion status
        // Pending = 0
        // Completed = 1
        // proc[i].completed = 0;
 
        // Variable for sum of all Burst Times
        // sum_bt += proc[i].burst_time;
    // }
 printf("SPN\n");
    // Sorting the structure by arrival times
    sortByArrival();
    // printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
    // printf("\tTurnAround Time\t Normalized TT");
    for (t = proc[0].arrival_time; t < sum_bt;) {
 
        // Set lower limit to response ratio
        float hrr = -9999;
 for(i=0;i<n;i++)
	{
		// proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
        proc[i].completion_time=proc[i].turn_around_time + proc[i].arrival_time;
	}
     struct process str[100], chTemp;
     for(i=0;i<n;i++){
        str[i]=proc[i];

     }
     int  len;
     len=n;
    // printf("Enter any string: ");
    // scanf("%s",str);
    // len = strlen(str);
    for(i=0; i<len; i++)
    {
        for(j=0; j<(len-1); j++)
        {
            if(str[j].Name[0]>str[j+1].Name[0])
            {
                chTemp = str[j];
                str[j] = str[j+1];
                str[j+1] = chTemp;
            }
        }
    }
  
    for(i=0;i<n;i++){
        proc[i]=str[i];

     }

        // Response Ratio Variable
        float temp;
  
        // Variable to store next process selected
        int loc;
        for (i = 0; i < n; i++) {
 
            // Checking if process has arrived and is Incomplete
            if (proc[i].arrival_time <= t && proc[i].completed != 1) {
 
                // Calculating Response Ratio
                temp = (proc[i].burst_time + (t - proc[i].arrival_time)) / proc[i].burst_time;
 
                // Checking for Highest Response Ratio
                if (hrr < temp) {
 
                    // Storing Response Ratio
                    hrr = temp;
 
                    // Storing Location
                    loc = i;
                }
            }
        }
 
        // Updating time value
        t += proc[loc].burst_time;
 
        // Calculation of waiting time
        proc[loc].waiting_time = t - proc[loc].arrival_time - proc[loc].burst_time;
 
        // Calculation of Turn Around Time
        proc[loc].turn_around_time = t - proc[loc].arrival_time;
 
        // Sum Turn Around Time for average
        avgtt += proc[loc].turn_around_time;
 
        // Calculation of Normalized Turn Around Time
        proc[loc].ntt = ((float)proc[loc].turn_around_time / proc[loc].burst_time);
 
        // Updating Completion Status
        proc[loc].completed = 1;
 
        // Sum Waiting Time for average
        avgwt += proc[loc].waiting_time;
        // printf("\n%c\t\t%d\t\t", proc[loc].Name, proc[loc].arrival_time);
        // printf("%d\t\t%d\t\t", proc[loc].burst_time, proc[loc].waiting_time);
        // printf("%d\t\t%f", proc[loc].turn_around_time, proc[loc].ntt);
    }
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
	if(meant < 10){
    printf(" %.2f|",meant);}
	else {
		printf("%.2f|",meant);
	}
	printf("\n");
    printf("NormTurn   |");
		float meanN,temp1;
		meanN=0;
	for(i=0;i<n;i++)
	{
	
		
		temp1 =    ((float) proc[i].turn_around_time) / ((float) proc[i].burst_time);
		meanN+=temp1;
		printf(" %.2f|",temp1);
	}
	meanN=(meanN)/((float) n);
    printf(" %.2f|",meanN);
	//jjkkhjj
    printf("\n");
    // printf("\nAverage waiting time:%f\n", avgwt / n);
    // printf("Average Turn Around time:%f\n", avgtt / n);
}