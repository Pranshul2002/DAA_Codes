#include <iostream>
using namespace std;
int partition(int arr[],int end,int start){
	int p = start-1;
	int key = arr[end];
	for(int i=start;i<=end;i++){
		if(arr[i] < key){
			p++;
			int temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
		}
	}
	p++;
	int temp = arr[p];
	arr[p] = arr[end];
	arr[end] = temp;
	return p;
}


void quickSort(int arr[],int end,int start){
	if(start < end){
		int p = partition(arr,end,start);
		quickSort(arr,p-1,start);
		quickSort(arr,end,p+1);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quickSort(arr,n-1,0);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}