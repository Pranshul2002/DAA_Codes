#include<iostream>
using namespace std;

void take_input_1d(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr[i] = temp;
	}
}

void selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int* temp = &arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[j] < *temp){
				temp = &arr[j];
			}
		}
		int temp1 = arr[i];
		arr[i] = *temp;
		*temp = temp1;
	}
}

void display_1d(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	take_input_1d(arr,n);
	selection_sort(arr,n);
	display_1d(arr,n);
	return 0;
}