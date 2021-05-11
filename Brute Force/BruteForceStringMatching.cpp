#include <iostream>
#include <string.h>
using namespace std;

int bruteForceStringMatching(char* a,char* b){
	for(int i=0;i<strlen(a)-strlen(b)+1;i++){
		int flag = 1;
		int k = i;
		for(int j=0;j<strlen(b);j++){
			if(a[k] != b[j]){
				flag = 0;
				break;
			}else{

				k++;
			}
		}
		if(flag != 0)
			return 1;
			
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	char* a = (char*)malloc(sizeof(char)*100);
	gets(a);
	char* b = (char*)malloc(sizeof(char)*100);
	gets(b);
	int c = bruteForceStringMatching(a,b);
	if(c == 1){
		cout<<"Found substring";
	}else{
		cout<<"Substring not found";
	}
	return 0;
}