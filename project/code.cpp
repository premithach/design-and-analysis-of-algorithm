#include<iostream>

using namespace std;
int main()//driver code
{
      int n//no of process
	  ,temp,tt=0//total time
	  ,min,d,i,j;
      float atat=0,awt=0,stat=0//sum of total turn around time 
	  ,swt=0;// sum of total waiting time;

      cout<<"Enter no of process"<<endl;
      cin>>n;
      int a[n],b[n],e[n],tat[n],wt[n];
  
      for(i=0;i<n;i++)
      {
            cout<<"Enter arival time ";       //input from user arrival time
            cin>>a[i];
      }
      for(i=0;i<n;i++)
      {
            cout<<"Enter burst time ";      //input from user the burst time
            cin>>b[i];
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)//selection sort
          {
                if(b[i]>b[j])//sort the processes according to burst time
                {
                      temp=a[i];//sort arrival time
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];//sort burst time
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];//in min ,we are storing the minimum arrival time
                  d=i;//store the index of the process with minimum arrival time
            }
      }
      tt=min;//total time we are storing the arrival time
      e[d]=tt+b[d];//we are calculating the total time i.e. arrival time+ burst time
      tt=e[d];//storing the total time in tt

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)//if a[i] is not the process with minimum arrival time
            {
                  e[i]=b[i]+tt;//calculate the total time
                  tt=e[i];//store the total time in tt 
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];//turn around time is total time -arrival time
            stat=stat+tat[i];//sum of turn around time
            wt[i]=tat[i]-b[i];//wating time is turn around time - burst time
            swt=swt+wt[i];//sum of waiting time
      }
      atat=stat/n;//average turn around time
      awt=swt/n;//average waiting time
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time
}
