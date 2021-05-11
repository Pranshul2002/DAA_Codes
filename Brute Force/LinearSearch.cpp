#include<iostream>
using namespace std;

void take_input_1d(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr[i] = temp;
	}
}

int linear_search(int arr[],int n,int element){
	for(int i=0;i<n;i++){
		if(arr[i] == element)
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	take_input_1d(arr,n);
	int element;
	cin>>element;
	int out = linear_search(arr,n,element);
	out == 1?cout<<"Element Found":cout<<"Element not Found";
	return 0;
}