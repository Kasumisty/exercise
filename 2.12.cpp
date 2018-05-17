#include <stdio.h>
#include <algorithm>
using namespace std;
struct program
{
	int s, e;
	bool operator < (const program &b){
		return e < b.e;
	}
}buf[100];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		for(int i=0; i<n; i++){
			scanf("%d%d", &buf[i].s, &buf[i].e);
		}
		sort(buf, buf+n);

		int ans=0;
		int index=0;
		int end=0;
		while(index<n){
			if(end>buf[index].s) index++;
			else{
				ans++;
				end = buf[index].e;
				index++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}