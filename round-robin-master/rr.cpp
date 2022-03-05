#include<iostream>
using namespace std;
int main()
{

  int i,j,n,t,r,f=0,tq;
  int wt=0,tat=0,a_t[10],bt[10],rt[10];
  cout<<"round robin is preemptive already non preemptive not possible \n";
  cout<<"Enter Total Process: ";
  cin>>n;
  r=n;
  cout<<"Enter Arrival Time and Burst Time for Process:";
  for(i=0;i<n;i++)
  {
    cin>>a_t[i];
    cin>>bt[i];
    rt[i]=bt[i];
  }
  cout<<"Enter Time Quantum: ";
  cin>>tq;
  cout<<"\n\nProcess\t Turnaround Time Waiting Time\n";
  for(t=0,i=0;r!=0;)
  {
    if(rt[i]<=tq && rt[i]>0)
    {
      t+=rt[i];
      rt[i]=0;
      f=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=tq;
      t+=tq;
    }
    if(rt[i]==0 && f==1)
    {
      r--;
      cout<<"P"<<i+1<<"\t \t"<<t-a_t[i]<<"\t \t"<<t-a_t[i]-bt[i]<<"\n";
      wt+=t-a_t[i]-bt[i];
      tat+=t-a_t[i];
      f=0;
    }
    if(i==n-1)
      i=0;
    else if(a_t[i+1]<=t)
      i++;
    else
      i=0;
  }
  cout<<"\nAverage Waiting Time= "<<wt/n<<"\n";
  cout<<"Avg Turnaround Time = "<<tat/n;

  return 0;
}
