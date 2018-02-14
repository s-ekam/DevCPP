#include <iostream>
using namespace std;
int findMin(int arr[],int n,int low,int high){
    if(low<0 || high >=n)
        return -1;
    int mid = low +(high-low)/2;
//    cout<< "MID"<<mid<<endl;
    if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
        return mid;
    if(mid == 0||mid ==1)
		return -1;
    else if(arr[mid]<arr[high]){        // Check left
//        cout<<mid<<high<<"Left\n";
		return findMin(arr,n,low,mid);  
    }
    else                                // Check Right Side;
        return findMin(arr,n,mid,high);
    
}
int main() {
	int t;
//	cout<<"Enter T";
	cin>>t;
	while(t--){
	    int n;
//	    cout<<"Enter n";
	    cin>>n;
	    int arr[n];
//	    cout<<"Enter Arr";
		for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int ind = findMin(arr,n,0,n-1);
	    cout<<ind<<endl;
	}
	return 0;
}


//1
//5
//4 5 1 2 3
