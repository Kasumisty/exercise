// p64练习题1，%的运用
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int a, b, k;
	while(scanf("%d%d", &a, &b)!=EOF && a!=0 && b!=0){
		scanf("%d", &k);
		int div = pow(10, k);
		int a_ = a % div;
		int b_ = b % div;
		if(a_ == b_){
			printf("-1\n");
		}
		else{
			printf("%d\n", a+b);
		}
	}
	return 0;
}