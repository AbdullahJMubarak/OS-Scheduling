#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>

  
struct process {
    char *Name;
    int process_id; // Process ID
   int arrival_time;// Burst Time
    int burst_time; 
    int waiting_time;
	int turn_around_time;
    int remaining_time;
    int completion_time;// Arrival Time
};
  
// Function to find the waiting time for all
// processes
void findWaitingTime(process proc[], int n,
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
void findTurnAroundTime(process proc[], int n,
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
  
    // cout << "\nAverage waiting time = "
    //     << (float)total_wt / (float)n;
    // cout << "\nAverage turn around time = "
    //     << (float)total_tat / (float)n;
}
  
// Driver code
int main()
{
   int n,i,j;
    // struct process temp;
	// int bt=0,k=1,tat=0,sum=0,min;
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
		proc[i].burst_time = atoi(token);
	
		proc[i].remaining_time = proc[i].burst_time;
		//    }
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
  
    findavgTime(proc, n);
    return 0;
}