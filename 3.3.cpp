#include <queue>
#include <stdio.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	priority_queue< int, vector<int>, greater<int> > Q;	// 编译器会将>>视为一个运算符
	while(scanf("%d", &n) != EOF){
		while(!Q.empty()) Q.pop();
		for (int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			Q.push(x);
			/* code */
		}
		int ans=0;
		for (int i = 1; i <= n-1; ++i)
		{
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a+b;
			Q.push(a+b);
			/* code */
		}
		printf("%d\n", ans);
	}
	
	

	return 0;
}