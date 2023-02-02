#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>
#define N 100
struct process {
  int process_id;
    char *Name;
    int arrival_time, burst_time, ct, waiting_time, turn_around_time;
    int completed;
    int completion_time;
    int remaining_time;
    float ntt;
	// Arrival Time
};
int queue[N];
int front = 0, rear = 0;
 int n;
struct process proc[N];
void push(int process_id)
{
	queue[rear] = process_id;
	rear = (rear + 1) % N;
}

int pop()
{
	if (front == rear)
		return -1;

	int return_position = queue[front];
	front = (front + 1) % N;
	return return_position;
} 
void findWaitingTime( process proc[], int n,
                                int wt[])
{
    int rt[n];
      
    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].burst_time;
  
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
  
    // Process until all processes gets
    // completed
    while (complete != n) {
  
        // Find process with minimum
        // remaining time among the
        // processes that arrives till the
        // current time`
        for (int j = 0; j < n; j++) {
            if ((proc[j].arrival_time <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
  
        if (check == false) {
            t++;
            continue;
        }
  
        // Reduce remaining time by one
        rt[shortest]--;
  
        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
  
        // If a process gets completely
        // executed
        if (rt[shortest] == 0) {
  
            // Increment complete
            complete++;
            check = false;
  
            // Find finish time of current
            // process
            finish_time = t + 1;
  
            // Calculate waiting time
            wt[shortest] = finish_time -
                        proc[shortest].burst_time -
                        proc[shortest].arrival_time;
  
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        // Increment time
        t++;
    }
}
  
// Function to calculate turn around time
void findTurnAroundTime(struct process proc[], int n,
                        int wt[], int tat[])
{
    // calculating turnaround time by adding
    // burst_time[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].burst_time + wt[i];
}
  
// Function to calculate average time
void findavgTime(process proc[], int n)
{
    int wt[n], tat1[n], total_wt = 0,
                    total_tat = 0;
  
    // Function to find waiting time of all
    // processes
    findWaitingTime(proc, n, wt);
  
    // Function to find turn around time for
    // all processes
    findTurnAroundTime(proc, n, wt, tat1);
  
    // Display processes along with all
    // details
//   printf(  " P\t\t"
//         "BT\t\t"
//         "WT\t\t"
//     "TAT\t\t\n");
  
    // Calculate total waiting time and
    // total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat1[i];
        // printf(" %d \t\t %d \t\t %d \t\t %d\n",proc[i].process_id,proc[i].burst_time,wt[i],tat[i]);
        // cout << " " << proc[i].pid << "\t\t"
        //     << proc[i].burst_time << "\t\t " << wt[i]
        //     << "\t\t " << tat[i] << endl;
    }
    	int i;
        int bt=0,k=1,sum=0,min;
	proc[0].waiting_time=0;
	int wait_time_total=0;
	int turn_around_time_total=0;
	for(i=1;i<n;i++)
	{
		sum+=proc[i-1].burst_time;
		proc[i].waiting_time = sum-proc[i].arrival_time;
		wait_time_total += proc[i].waiting_time;
	}
	// for(i=0;i<n;i++)
	// {
	// 	tat+=proc[i].burst_time;
	// 	proc[i].turn_around_time = tat - proc[i].arrival_time;
	// 	turn_around_time_total+=proc[i].turn_around_time;
	// }
	for(i=0;i<n;i++)
	{
		proc[i].turn_around_time = proc[i].burst_time + wt[i];
        proc[i].completion_time=proc[i].turn_around_time + proc[i].arrival_time;
	}

     struct process str[100], chTemp;
     for(i=0;i<n;i++){
        str[i]=proc[i];

     }// printf("\n");
printf("SRT\n");
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
		printf(" %2d  |",tat1[i]);
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
  return ;
    // cout << "\nAverage waiting time = "
    //     << (float)total_wt / (float)n;
    // cout << "\nAverage turn around time = "
    //     << (float)total_tat / (float)n;
}
  
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
	float avgwt = 0, avgtt = 0, sum_bt = 0;
	   char c;
	char *token;
	int i, metN, period, q,j, t;
    int bt=0,k=1,tat=0,sum=0,min;
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
	struct process proc[n];
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
		        proc[i].completed = 0;
        //  sum_bt += proc[i].burst_time;
		proc[i].burst_time = atoi(token);
		proc[i].process_id = i+1;
		proc[i].remaining_time = proc[i].burst_time;
		//    }
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
// printf("\n out of loop");
// for (int i = 0; i < n; i++)
// {

//   printf(" \n process no %d name : %s ",i , proc1[i].c);
// //  printf(" \n process no %d name : %s ",i , in[i]);
//    printf(" \n process no %d arrive : %d ", i,proc1[i].x);
//     printf(" \n process no %d brust : %d",i , proc1[i].y);
// }


if( metN ==1){

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
	} else if ( metN ==2 ) {
//  printf("ANOTHER METHOD");

     float wait_time_total = 0.0, tat = 0.0;
	int time_quantum;
	 time_quantum = q;
	// printf("Enter the number of processes: ");
	// scanf("%d", &n);

	// for(int i=0; i<n; i++)
	// {
	// 	printf("Enter the arrival time for the process%d: ",i+1);
	// 	scanf("%d", &proc[i].arrival_time);
	// 	printf("Enter the burst time for the process%d: ",i+1);
	// 	scanf("%d", &proc[i].burst_time);
	// 	proc[i].process_id = i+1;
	// 	proc[i].remaining_time = proc[i].burst_time;
	// }
	// printf("Enter time quantum: ");
	// scanf("%d",&time_quantum);

	int time = 0;
	int processes_left = n;
	int position = -1;
	int local_time = 0;

	for (int j = 0; j < n; j++)
		if (proc[j].arrival_time == time)
			push(j);

	while (processes_left)
	{
		if (local_time == 0)
		{
			if (position != -1)
				push(position);

			position = pop();
		}

		for (int i = 0; i < n; i++)
		{
			if (proc[i].arrival_time > time)
				continue;
			if (i == position)
				continue;
			if (proc[i].remaining_time == 0)
				continue;

			proc[i].waiting_time++;
			proc[i].turn_around_time++;
		}

		if (position != -1)
		{
			proc[position].remaining_time--;
			proc[position].turn_around_time++;

			if (proc[position].remaining_time == 0)
			{
				processes_left--;
				local_time = -1;
				position = -1;
			}
		}
		else
			local_time = -1;

		time++;
		local_time = (local_time + 1) % time_quantum;
		for (int j = 0; j < n; j++)
			if (proc[j].arrival_time == time)
				push(j);
	}

// 
	int service_time[n];
	service_time[0]=0;
	proc[0].waiting_time=1;	

	// for(i=1;i<n;i++)
	// {
	// 	service_time[i]=service_time[i-1]+proc[i-1].burst_time;
	// 	proc[i].waiting_time = service_time[i]-proc[i].arrival_time;

	// 	if(proc[i].waiting_time<0)
	// 		proc[i].waiting_time=0;
	// }
for(i=0;i<n;i++){ 
	//   printf("%d ",proc[i].turn_around_time);
		proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
		proc[i].completion_time=proc[i].turn_around_time + proc[i].arrival_time;
	}

	// printf("\n");
printf("RR-%d\n",q);
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
	if(meant < 10){
    printf(" %.2f|",meant);}
	else {
		printf("%.2f|",meant);
	}
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
    // printf("\n");
		
	}else if ( metN ==3 ){
        struct process temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].arrival_time < proc[j].arrival_time)
			{
				temp = proc[j];
				proc[j] = proc[i];
				proc[i] = temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		bt+=proc[i].burst_time;
		min = proc[k].burst_time;
		for(j=k;j<n;j++)
		{
			if(bt>=proc[j].arrival_time && proc[j].burst_time<min)
			{
				temp=proc[k];
				proc[k]=proc[j];
				proc[j]=temp;
			}
		}
		k++;
	}
	proc[0].waiting_time=0;
	int wait_time_total=0;
	int turn_around_time_total=0;
	for(i=1;i<n;i++)
	{
		sum+=proc[i-1].burst_time;
		proc[i].waiting_time = sum-proc[i].arrival_time;
		wait_time_total += proc[i].waiting_time;
	}
	for(i=0;i<n;i++)
	{
		tat+=proc[i].burst_time;
		proc[i].turn_around_time = tat - proc[i].arrival_time;
		turn_around_time_total+=proc[i].turn_around_time;
	}
	for(i=0;i<n;i++)
	{
		proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
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


	// printf("\n");
printf("SPN\n");
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
    } else if ( metN ==4 ) {

     findavgTime(proc, n);

    } else if ( metN ==5 ){
   int i, j, t, sum_bt = 0;
    char c;
    float avgwt = 0, avgtt = 0;
    
   
    // int n,i,j;
    struct process temp;
	int bt=0,k=1,tat=0,sum=0,min;
    	char *token;
	int metN, period, q;
	char pt[20], c2[20];
	
	for ( i = 0; i < n; i++)
	{
		sum_bt += proc[i].burst_time;
		 proc[i].completed = 0;
		 proc[i].process_id = i+1;
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
 printf("HRRN\n");
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
	}
    printf("\n");
	return 0;
}