#include<iostream>
using namespace std;
int main()
{
    int n,bt[20],wait_time[20],tat[20];
	float avwt=0,avtat=0;
	int i,j;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
     wait_time[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
        wait_time[i]+=bt[j];
    }
     cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
     //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wait_time[i];
        avwt+=wait_time[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<tat[i];
    }
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
    return 0;
}

