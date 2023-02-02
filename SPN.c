
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct process
{   char *Name;
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
    int remaining_time;
    int completion_time;
};
int main()
{
	int n,i,j;
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
	// printf("Enter number of processes: ");
	// scanf("%d",&n);
	// struct process proc[n],temp;
	// for(i=0;i<n;i++)
	// {
	// 	printf("\n");
	// 	printf("Enter arrival time for process%d: ",i+1);
	// 	scanf("%d",&proc[i].arrival_time);
	// 	printf("Enter burst time for process%d: ",i+1);
	// 	scanf("%d",&proc[i].burst_time);
	// 	proc[i].process_id = i+1;
	// }

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
}