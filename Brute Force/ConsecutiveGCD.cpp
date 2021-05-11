#include<iostream>
using namespace std;

int consecutive(int a,int b){
	int c = a<b?a:b;
	while(c != 0 && (a%c != 0 || b%c != 0)){
		c--;
	}
	return c;
}

int main(){
	int a,b;
	cin>>a>>b;
	int d = consecutive(a,b);
	cout<<d;
	return 0;
}