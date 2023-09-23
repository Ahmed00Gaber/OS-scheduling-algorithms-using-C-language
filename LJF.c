/******************************************************************************
longest job first algorithm
*******************************************************************************/
#include <stdio.h>

int main()
{
    int procs, bst_time[10],ariv_time[10],temp,waiting_time=0,turnaround=0,copy[10],postion[10],count,x=0;
    printf("please enter no of processes: ");
    scanf("%d",&procs);
    
    //ask user to enter  burst time
    printf("please enter burst-time of each processes:\n ");
    for(int i=0 ;i<procs;i++){
    printf("P[%d]: ", i+1);
    scanf("%d",&bst_time[i]);
    copy[i]=bst_time[i];
    }
    printf("\n");
    
    //sorting algorithm for burst-time
    temp=bst_time[0];//smallest number
    for(int i=0 ;i<procs;i++){
        for(int j=0 ;j<procs;j++){
            if(bst_time[i]>bst_time[j]){
                temp=bst_time[i];
                bst_time[i]=bst_time[j];
                bst_time[j]=temp;

            }
        }
    }
    //ordering elements
    for(int i=0 ;i<procs;i++){
        count=0;
        for(int j=0 ;j<procs;j++){
            if(copy[i]==bst_time[j]){
                count=j+1;
                postion[x]=count;
                x++;
            }
        }
    }
    //printing the gantt schart processes
    printf("process    wait_time  \n");
    for(int i=0 ;i<procs;i++){
    turnaround=turnaround+bst_time[postion[i]-1];
    waiting_time=waiting_time+bst_time[i];
    printf("p[%d]:%d      %d  \n",postion[i],bst_time[i],waiting_time);
    }
	printf("\nAv.waiting Time = %f ",(double)waiting_time/(double)procs);
    return 0;
}
