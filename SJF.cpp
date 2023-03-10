#include<stdio.h>
#include "M.cpp"

void main()
{
    int bt[20],p[20],wTime[20],t[20],k,i,j, total=0,pos,temp;
    float avg_w,avg_t;
    printf("Please enter the number of process:");
    scanf("%d",&k);
printf("\nNow enter the burst time:\n");
    for(i=0;i<k;i++)
    {
        printf("T%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           // This has the process number
    }
   
    for(i=0;i<k;i++)
    {
        pos=i;
        for(j=i+1;j<k;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wTime[0]=0;            //waiting time for first process will be zero
    //calculate waiting time
for(i=1;i<k;i++)
   {
       wTime=aTime[i]-count[i-1];
       if(wTime<=0)
       {
           printf("\nW for process %d: %d",i+1,wTime);
           printf("\nCPU is idle between the process %d and %d",i,i+1);
       }
       else
       {
           printf("\nW for process %d: 0",i+1);
       }
   }
   printf("\nNumber of the context switch: %d\n",k-1);
}