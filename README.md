# multilevel-feedback-queue
C program to simulate multilevel feedback queue scheduler

This Scheduling is like Multilevel Queue(MLQ) Scheduling but in this process can move between the queues. Multilevel Feedback Queue Scheduling (MLFQ) keep analyzing the behavior (time of execution) of processes and according to which it changes its priority.Now, look at the diagram and explanation below to understand it properly.

Now let us suppose that queue 1 and 2 follow round robin with time quantum 4 and 8 respectively and queue 3 follow FCFS.One implementation of MFQS is given below –

When a process starts executing then it first enters queue 1.
In queue 1 process executes for 4 unit and if it completes in this 4 unit or it gives CPU for I/O operation in this 4 unit than the priority of this process does not change and if it again comes in the ready queue than it again starts its execution in Queue 1.
If a process in queue 1 does not complete in 4 unit then its priority gets reduced and it shifted to queue 2.
Above points 2 and 3 are also true for queue 2 processes but the time quantum is 8 unit.In a general case if a process does not complete in a time quantum than it is shifted to the lower priority queue.
In the last queue, processes are scheduled in FCFS manner.
A process in lower priority queue can only execute only when higher priority queues are empty.
A process running in the lower priority queue is interrupted by a process arriving in the higher priority queue.
Well, above implementation may differ for example the last queue can also follow Round-robin Scheduling.

Problems in the above implementation – A process in the lower priority queue can suffer from starvation due to some short processes taking all the CPU time.
Solution – A simple solution can be to boost the priority of all the process after regular intervals and place them all in the highest priority queue.

OUTPUT: The remaining time of processes in each queue level, total waiting time and total turnaround time are displayed.
