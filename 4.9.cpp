#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 1010
using namespace std;
bool mark[MAX]={0};
int prime[MAX]={0};		// 用于存储素数
int primeSize=0;

void init(int max = MAX){	// 求素数
	for(int i=2; i<max; i++){
		if(mark[i] == false){
			prime[primeSize++] = i;
			for(int j = i*i; j<max; j+=i){
				mark[j] = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, a;
	init();
	int cnt1[MAX]={0}, cnt2[MAX]={0};
	while(scanf("%d%d", &n, &a) != EOF){
		for(int i=0; i<primeSize; i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a /= prime[i];
			}
			int t = n;
			while(t){
				cnt1[i] += t/prime[i];
				t /= prime[i];
			}
		}

		int ans = 123456789;
		int x;
		for(int i=0; i<primeSize; i++){
			if(cnt2[i]!=0){
				x = cnt1[i]/cnt2[i];
				ans = x<ans? x: ans;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}