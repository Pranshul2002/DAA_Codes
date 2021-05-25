#include <iostream>
using namespace std;
void mergeSort(int arr[], int start, int end){
	if(start == end)
		return;
	if(start == end-1){
		if(arr[start] > arr[start + 1]){
			int temp = arr[start];
			arr[start] = arr[start+1];
			arr[start+1] = temp;
		}
		return;
	}
	int mid = (end - start)/2;
	mergeSort(arr,start,mid+start);
	mergeSort(arr,start+mid+1,end);
	int i = start;
	int k = start;
	while(i<mid+start+1 && k<end+1){
		if(arr[i] > arr[k+mid+1]){
			int temp = arr[i];
			arr[i] = arr[k+mid+1];
			arr[k+mid+1] = temp;
		k++;
		}
		i++;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}