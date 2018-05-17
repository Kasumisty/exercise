#include <stdio.h>
#include <algorithm>
using namespace std;

int p[100];

int main(){
	int c, n, V, W;
	scanf("%d", &c);
	while(c--){
		scanf("%d%d%d", &n, &V, &W);
		for(int i=0; i<n; i++){
			scanf("%d", &p[i]);
			// printf("%d ",p[i] );
		}
		sort(p, p+n);

		int index=0;
		int ans=0;
		double pure=0;
		while(index<n && pure<W){
			double now_p = (ans*pure +p[index]) / (ans+1);
			if(now_p < W){
				pure = now_p;
				index++;
				ans++;
			}
			else
				break;
		}
		if(ans == 0){
			printf("0 0.00\n");
		}
		else{
			printf("%d %.2lf\n", ans*V, pure/100);
		}
	}

}