#include <iostream>
#include <math.h>
using namespace std;

void sieve(int arr[], int n){
	for(int i=0;i<n;i++){
		arr[i] = i;
	}
	for(int i=2;i<n;i++){
		if(!arr[i])
			continue;
		int j = i*i;
		while(j<n){
			arr[j] = 0;
			j += i;
		}
	}
}

void display_1d_prime(int arr[],int n){
	for(int i=2;i<n;i++){
		if(arr[i] != 0)
			cout<<arr[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	sieve(arr,n);
	display_1d_prime(arr,n);
	return 0;
}