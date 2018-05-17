#include <stdio.h>
#include <algorithm>
using namespace std;

struct goods
{
	double j, f, s;	//j为重量，f为总价值，s为单价
	bool operator < (const goods &b){
		return s < b.s;
	}
}buf[100];

int main(int argc, char const *argv[])
{
	double m;
	int n;
	while(scanf("%lf%d", &m, &n) != EOF){
		if(m == -1 && n == -1)
			break;
		for(int i=0; i<n; i++){
			scanf("%lf%lf", &buf[i].j, &buf[i].f);
			buf[i].s = buf[i].f / buf[i].j;
		}
		sort(buf, buf+n);

		// for (int i = 0; i < n; ++i)
		// {
		// 	printf("%lf ", buf[i].s);
		// 	/* code */
		// }

		int top=0;
		double ans=0;
		while(m>0 && top<n){
			if(buf[top].f <= m){
				ans += buf[top].j;
				m -= buf[top].f;
				top++;
			}
			else{
				ans += buf[top].j * m / buf[top].f;
				m = 0;
			}
		}
		printf("%lf\n", ans);
	}
	return 0;
}