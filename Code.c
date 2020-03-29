//CPU schedules N processes which arrive at different time intervals and each process is allocated the CPU for a specific user input time unit,
// processes are scheduled using a preemptive round robin scheduling algorithm. 
//Each process must be assigned a numerical priority, with a higher number indicating a higher relative priority.
//In addition to the processes one task has priority 0.
//The length of a time quantum is T units, 
//where T is the custom time considered as time quantum for processing. 
//If a process is preempted by a higher-priority process, 
//the preempted process is placed at the end of the queue.
// Design a scheduler so that the task with priority 0 does not starve for resources and gets the CPU at some time unit to execute.
//Also compute waiting time, turn around.


#include<stdio.h>
#include<stdlib.h>
float avg_waiting_time(int wt[], int n)
{
    float x = 0;
    int i, sum = 0;
    for(i=0; i<n; i++)
    	sum = sum + wt[i];
	x = sum * 1.0;
    x = x / n;
    return x;
}

float avg_turnaround_time(int tat[], int n)
{
    float x = 0;
    int i, sum = 0;
    for(i=0; i<n; i++)
        sum = sum + tat[i];
    x = sum * 1.0;
    x = x / n;
    return x;
}

void rearrange_process_queue(int pq[], int rt[], int pty[], int n, int running_processes)
{
    int i;
    if(pty[0] < pty[1])
    {
	int temp = pq[0];
    for(i=0; i<running_processes; i++)
    {
        pq[i] = pq[i+1];
    }
    pq[running_processes-1] = temp;
    }
    
    if(rt[pq[0]-1] == 0)
    {   
    	int temp = pq[0];
        for(i=0; i<running_processes; i++)
        {
        	pq[i] = pq[i+1];
        }
    pq[running_processes-1] = temp;
	running_processes = running_processes-1;
	}
    
}

void minptyinc(int pty[], int n)
{
	int i, min = pty[0];
	for(i=1; i<n; i++)
	{
		if(min >= pty[i])
		min = pty[i];
	}
	for(i=0; i<n; i++)
	{
		if(pty[i] == min)
		pty[i]++;
	}
	
}

int main()
{
  int count, i, j;
  int time_quantum, n;
  int time = 0;
  
printf("\nEnter Number of Processes : ");
scanf("%d", &n);
printf("Enter Time Quantum : ");
scanf("%d", &time_quantum);

  if(n <= 0 || time_quantum <= 0)
  {
      printf("Invalid data!");
      return 0;
  }
  
printf("\nThe number of processes are set to : %d\nThe time quantum is set to : %d\n" , n, time_quantum);
int at[10], bt[10], rt[10], pq[10], pty[10], pty1[10], pflag[10], tat[10], wt[10];
  for(j=0; j<n; j++)
    {
        pq[j] = 0;
        pflag[j] = 0;
    }
    
  for(count=0; count<n; count++)
  {
      printf("\nEnter Detail for Process : P%d", count+1);
	  printf("\nEnter Arrival time : ");
	  scanf("%d", &at[count]);
	  printf("Enter Burst time : ");
	  scanf("%d", &bt[count]);
      printf("Enter Priority : ");
	  scanf("%d", &pty[count]);
	  rt[count] = bt[count];
	  pty1[count] = pty[count];

      if(at[count] < 0 || bt[count] <= 0)
      {
	  	printf("Invalid Data!");
        return 0;
      }
 }
  	int current = 0;
  	int running_processes = 0;
  	int x=0;
    pq[0] = 1;
    running_processes = 1;
    pflag[0] = 1;
    int flag = 0;

    while(running_processes!=0)
        {
        flag = 0; 
        x++;
        if(rt[pq[0]-1] > time_quantum)
        {   
            rt[pq[0]-1] = rt[pq[0]-1] - time_quantum;
            time = time + time_quantum;
            current = time;
        }

        else
        {   
            time = time + rt[pq[0]-1];
            rt[pq[0]-1] = 0;
            flag = 1;
            current = time;
            tat[pq[0]-1] = time - at[pq[0]-1];
            wt[pq[0]-1] = tat[pq[0]-1] - bt[pq[0]-1];
        }
        
        for(i=0; i<n; i++)
        {
            if(at[i] <= time && pflag[i] == 0)
            {
                pq[running_processes] = i+1;
                running_processes = running_processes + 1;
                pflag[i] = 1;
            }
        }
        
		if(x%2 == 0)
		minptyinc(pty, n);

        rearrange_process_queue(pq, rt, pty, n, running_processes);

        if(flag == 1)
        running_processes = running_processes - 1;
}

printf("\n\nExecution Data\n");

	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|    Priority   |\tTAT\t|\tWT\t|\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
   for(i=0;i<n;i++)
   {
	 printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",i+1,at[i],bt[i],pty1[i],tat[i],wt[i]);
   }
	printf(" -----------------------------------------------------------------------------------------------\n");

	printf("\n\nAverage Waiting Time     :  %f\n", avg_waiting_time(wt,n));
	printf("Average Turnaround Time  :  %f\n", avg_turnaround_time(tat,n));
  
return 0;
}
