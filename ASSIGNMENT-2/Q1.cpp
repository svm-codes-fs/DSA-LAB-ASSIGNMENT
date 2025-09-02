#include<iostream>
using namespace std;
    int binary_search(int arr[],int size,int target){
    	int start =0;
    	int end = size-1;
    	while(start<=end)
		{
    		int mid = start+(end-start)/2;
    		if(arr[mid] == target)
			{
    			return mid;
			}
			if(arr[mid]>target){
				end=mid-1;
			}
			else
			start = mid+1;
		}
		return -1;
	}




int main(){
	int array[]={1,2,3,4,5,6,7,8,9,10};
    int n =10;
	int key = 10;
	int result = binary_search(array,n,key);
	
	if(result!=-1){
		cout<<"Element found at index "<<result<<" of Array";
	}
	else
	{
		cout<<"Element Not Found in Array.";
	}
	return 0;
}
