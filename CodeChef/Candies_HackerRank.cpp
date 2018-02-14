#include <bits/stdc++.h>

using namespace std;

int candies(int n, vector <int> arr) {
    unsigned long long int cand=1, num=1,num2=1, val[n]={};
    //if(n==1)
      //  return 1;
    val[0]=1;
    for(int i=1;i<n;i++ )
    {
        if(arr[i]>arr[i-1]) 
            val[i]=val[i-1]+1;
        else
            val[i]=1;
      //  cout<<val[i]<<" ";
    }
   // cout<<endl;
    unsigned long long int ans =0,temp =0;
    ans = val[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
        {
            temp = val[i+1]+1;
        }
        else
            temp = 1;
        ans+=max(temp,val[i]);
        val[i]=temp;
        //cout<<val[i]<<" ";
    }
   /* for(int i=1;i<n;i++)
    {
        if(i==0)
        {
            if(arr[0]>arr[1])
            {
                cand=2;
            }
            else
            {
                cand=1;
            }
        }
        else if(i==(n-1))
        {
            if(arr[n-1]>arr[n-2])
            {
                num++;
                cand+=num;
            }
            else
            {
                cand++;
            }
        }
        else
        {
            if(arr[i]>arr[i-1])
            {
                num++;
                cand+=num;
            }
            else if(arr[i]>arr[i+1])
            {
                num2++;
                cand+=num2;
            }
            else
            {
                cand++;
                num=1;
                num2=1;
            }
        }
       // cout<<i<<"\t"<<arr[i]<<"\t"<<cand<<endl;
    }*/
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = candies(n, arr);
    cout << result << endl;
    unsigned long long int x = n;
    cout<<(x*(x+1))/2<<endl;
    return 0;
}

