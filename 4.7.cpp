#include <stdio.h>
#include <iostream>
using namespace std;
bool mark[10000]={false};	// true表示是合数，false表示不是合数是素数
void init(int n=10000){
	for (int i = 2; i < n; ++i)
	{
		if(mark[i]==false){
			for(int j = i*i; j<n; j+=i){	//直接从j=i开始标记起，这是因为j=1~i-1已经被标记过
				mark[j] = true;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	init();
	int n;
	while(scanf("%d", &n) != EOF){
		bool isOutput = false;
		for(int i=1; i*10+1<n; i++){
			if(mark[i*10+1] == false){
				if(isOutput==false){
					cout<<i*10+1;
					isOutput=true;
				}
				else{
					cout<<" "<<i*10+1;
				}
			}
		}
		if(isOutput==false){
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}