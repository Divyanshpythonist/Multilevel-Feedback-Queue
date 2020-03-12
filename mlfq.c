//multilevel feedback queue scheduling algorithm

/* asssumption: 1) process must be entered in ascending order according to arrival time
                2) at a time only single process can be executed  
                3) RT : remaining time
                4) BT : burst time
                5) TAT : turnaround time
                6) CT :  completion time
                7)AT : arrival time
                8)tq : quantum time
                
                
                
                
                  */
    



#include<stdio.h>

struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT; 
}Q1[10],Q2[10],Q3[10];/*Three queues*/

int n;



int main()
{
     int i,j,k=0,r=0,time=0,tq1=17,tq2=25,flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nEnter the arrival time and burst time of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].AT,&Q1[i].BT);
         Q1[i].RT=Q1[i].BT;

    }

time=Q1[0].AT;

printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(Q1[i].RT<=tq1)
  {

       time+=Q1[i].RT;
       Q1[i].RT=0;
       Q1[i].WT=time-Q1[i].AT-Q1[i].BT;
       Q1[i].TAT=time-Q1[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);

  }
  else/*process moves to queue 2 */
  {
      Q2[k].WT=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].BT=Q1[i].RT;
      Q2[k].RT=Q2[k].BT;
      Q2[k].name=Q1[i].name;
      k=k+1;
     // flag=1;
   }
}


for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].RT;
       Q2[i].RT=0;
       Q2[i].WT=time-tq1-Q2[i].BT;
       Q2[i].TAT=time-Q2[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    }
    else/*process moves to queue 3 with FCFS*/
    {
      Q3[r].AT=time;
      time+=tq2;
      Q2[i].RT-=tq2;
      Q3[r].BT=Q2[i].RT;
      Q3[r].RT=Q3[r].BT;
      Q3[r].name=Q2[i].name;
      r=r+1;  //count no of processs in queue 3
     
    }
  }



for(i=0;i<r;i++)
{
    if(i==0)
            Q3[i].CT=Q3[i].BT+time-tq1-tq2;
        else
            Q3[i].CT=Q3[i-1].CT+Q3[i].BT;

}

for(i=0;i<r;i++)
    {
        Q3[i].TAT=Q3[i].CT;
        Q3[i].WT=Q3[i].TAT-Q3[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q3[i].name,Q3[i].BT,Q3[i].WT,Q3[i].TAT);

    }

}






