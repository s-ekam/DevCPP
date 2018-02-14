#include<iostream.h>
void main()
{
 int n,m,need[10][10],i,j,k;
 cout<<"Enter no. of processes:";
 cin>>n;
 cout<<"Enter no. of resources:";
 cin>>m;
 int alloc[n][m],max[n][m],avail[10],finish[10],work[n],SSeq[n];
       // cout<<"Enter allocation matrix:";
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   cout<<"\nEnter no. of instances of "<<j+1<<"allocated to "<<i+1<<":" ;
   cin>>alloc[i][j];
  }
 }
       // cout<<"\nEnter max matrix";
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   cout<<"\nEnter maximum instances of"<<j+1<<"allocated to"<<i+1<<":";
   cin>>max[i][j];
  }
 }

 for(i=0;i<m;i++)
 {
  cout<<"\nEnter available instances of"<<i+1;
  cin>>avail[i];
 }
 //calculate need matrix
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   need[i][j]=max[i][j]-alloc[i][j];
  }
 }
 cout<<"\nAllocation matrix is:";
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   cout<<alloc[i][j]<<"\t";
  }
  cout<<endl;
 }
 cout<<"\nMax matrix is:";
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   cout<<max[i][j]<<"\t";
  }
  cout<<endl;
 }
 cout<<"\nNeed matrix is:";
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   cout<<need[i][j]<<"\t";
  }
  cout<<endl;
 }
 //initialize work and finish
 for(i=0;i<n;i++)
 work[i]=avail[i];
 k=0;
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   if(finish[i]==0 && need[i][j]<=work[j])
   {
    SSeq[k]=i+1;
    k++;
    work[i]=work[i]+alloc[i][j];
   }
  }
 }
 cout<<"safe sequence is:";
 for(i=0;i<k;i++)
 cout<<SSeq[i]<<",";
 if(k==n)
 cout<<"\nThe system is safe.\n";
 else
 cout<<"\nDeadlock occurence!!\n";
}
