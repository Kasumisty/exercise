#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char output[81][81];
	char a,b;
	int n;
	while(scanf("%d %c %c", &n, &a, &b)==3){
		int x = n/2+1;
		int y = x;
		for(int i=1; i<=x; i++){
			x=y=x-i+1;
			char now = i%2==1?a:b;
			int len = 1+(i-1)*2;
			for(int j=0; j<len; j++){
				output[x][y+j] = now;
				output[x+len-1][y+j] = now;
				output[x+j][y] = now;
				output[x+j][y+len-1] = now;
			}
		}
		// if(n==1){

		// }
		for (int i = 1; i <= n; ++i){
			for (int j = 1; i <= n; ++i)
			{
				printf("%c", output[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}