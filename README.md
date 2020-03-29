# arshadsiddiqui36-gmail.com
CPU schedules N processes which arrive at different time intervals and each process is allocated the CPU for a specific user input time unit, processes are scheduled using a preemptive round robin scheduling algorithm. Each process must be assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes one task has priority 0. The length of a time quantum is T units, where T is the custom time considered as time quantum for processing. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue. Design a scheduler so that the task with priority 0 does not starve for resources and gets the CPU at some time unit to execute. Also compute waiting time and turn around.

•	Round robin is a pre-emptive algorithm
•	A fixed time is allotted to each process, which is called time quantum/time slice, for execution.
•	Once a process is executed for given time period that process is preemptied and other process executes for given time period.
•	Context switching is used to save states of preemptied processes.
•	The CPU is shifted to the next process after fixed interval time, 
•	The process that is preempted is added to the end of the queue.
•	Round robin is a hybrid model which is clock-driven
•	Time slice should be minimum, which is assigned for a specific task that needs to be processed. However, it may differ OS to OS.
•	It is a real time algorithm which responds to the event within a specific time limit.
•	Round robin is one of the oldest, fairest, and easiest algorithm.
•	Widely used scheduling method in traditional OS.
•	It doesn't face the issues of starvation or convoy effect.
•	All the jobs get a fair allocation of CPU.
•	It deals with all process without any priority
•	If you know the total number of processes on the run queue, then you can also assume the worst-case response time for the same process.
•	This scheduling method does not depend upon burst time. That's why it is easily implementable on the system.
•	Once a process is executed for a specific set of the period, the process is preempted, and another process executes for that given time period.
•	Allows OS to use the Context switching method to save states of preempted processes.
•	It gives the best performance in terms of average response time.
