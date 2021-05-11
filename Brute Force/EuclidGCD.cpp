#include<iostream>
using namespace std;

int euclid(int a,int b){
	int r = a%b;
	while(r != 0){
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int main(){
	int a,b;
	cin>>a>>b;
	int c = euclid(a,b);
	cout<<c;
	return 0;
}