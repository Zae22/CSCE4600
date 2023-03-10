#include<stdio.h>
#include "SJF.cpp"
int main()
{
   int k,i,j;
   printf("\nPlease enter the number of processes: ");
   scanf("%d",&k);
   int aTime[k],bt[k];
   for(i=0;i<k;i++)
   {
       printf("\n Please enter the arrival and the burst time of process T%d :",i+1);
       scanf("%d%d",&aTime[i],&bt[i]);
   }
   int count[k];
   count[0]=aTime[0]+bt[0];
   for(j=1;j<k;j++)
   {
       if(count[j-1]<aTime[j])
       {
           count[j]=aTime[j]+bt[j];
       }
       else
       {
           count[j]=count[j-1]+bt[j];
       }
   }
   printf("\nThe total time is: %d",count[k-1]);
   for(i=0;i<k;i++)
   {
       printf("\nT for process %d is %d: ",i+1,count[i]-aTime[i]);
   }
   printf("\nW for process 1: 0");
   int wTime;
   for(i=1;i<k;i++)
   {
       wTime=aTime[i]-count[i-1];
       if(wTime<=0)