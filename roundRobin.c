#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	char *Name;
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
	int completion_time;
};
// struct process
// {
// 	int process_id;
// 	int arrival_time;
// 	int burst_time;
// 	int waiting_time;
// 	int turn_around_time;
// 	int completion_time;
// };
int queue[N];
int front = 0, rear = 0;
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

int main()
{
	char *token;
	int i, n, metN, period, q;
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
// 	for (int i = 0; i < n; i++)
// {

//   printf(" \n process no %d name : %s ",i , proc[i].Name);
// //  printf(" \n process no %d name : %s ",i , in[i]);
//    printf(" \n process no %d arrive : %d ", i,proc[i].arrival_time);
//     printf(" \n process no %d brust : %d",i , proc[i].burst_time);
// }

	// printf("\nOutside the tokens");
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
    printf("\n");
}