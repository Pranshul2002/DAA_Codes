#include <iostream>
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

int middleschool(int a, int b){
	int arr[b];
	sieve(arr,b);
	int gcd = 1;
	for(int i=2;i<b;i++){
		if(!arr[i])
			continue;
		while(!(a%arr[i]) && !(b%arr[i])){
			gcd *= arr[i];
			a /= arr[i];
			b /= arr[i];
		}
	}
	return gcd;
}
int main(){
	int a,b;
	cin>>a>>b;
	int c = middleschool(a,b);
	cout<<c;
	return 0;
}