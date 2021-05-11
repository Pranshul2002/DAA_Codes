#include <iostream>
#include <math.h>
using namespace std;

void prime(int* a, int* b,int n){
	int count = 0;
	for(int i=2;i<n;i++){
		int flag = 0;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j == 0){
				flag = 1;
				break;
			}
		}
		if(!flag){
			a[count] = i;
			count++;	
		}
	}
	*b = count;
}

void display_1d(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int count = 0;
	int arr[n];
	prime(arr,&count,n);
	display_1d(arr,count);
}