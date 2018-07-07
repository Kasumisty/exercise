#include <stdio.h>
#include <iostream>
#define MAX 10000
using namespace std;
bool mark[MAX]={false};	// true为合数，false为非合数即质数
int prime[MAX];	// 用来保存所有素数
int primeSize=0;	// 用来保存素数的个数

void init(int max=MAX){
	for (int i = 2; i < max; ++i){
		if(mark[i]==false){
			prime[primeSize++] = i;
			for(int j=i*i; j<max; j+=i){
				mark[j] = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	int n;
	while(scanf("%d", &n)!=EOF){
		int ansPrime[30];	// 用于存储质因数
		int ansSize=0;		// 用于存储质因数个数
		int ansNum[30]={0};		// 用于存储不同质因数的指数
		for (int i = 0; i < primeSize; ++i){
			if(n%prime[i] == 0){
				ansPrime[ansSize] = prime[i];
				while(n%prime[i]==0){
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if(n == 1)	break;
			}
		}
		if(n!=1){
			ansPrime[ansSize]=n;
			ansNum[ansSize++]=1;
		}

		int ans=0;
		for (int i = 0; i < ansSize; ++i)
		{
			ans += ansNum[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}