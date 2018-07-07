#include <stdio.h>
int main(int argc, char const *argv[])
{
	int m;
	long long a, b;
	while(scanf("%d", &m) != EOF){
		if(m==0)	break;
		scanf("%d%d", &a, &b);
		a = a+b;
		int ans[50], size=0;
		do{
			ans[size++] = a%m;
			a /= m;
		}while(a>0);
		for(int i=size-1; i>=0; i--){
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}