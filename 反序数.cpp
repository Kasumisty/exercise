// 反序数 p67
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n = 1000;
	for (; n < 1112; ++n){
		int temp = n;
		int reverse = 0;
		while(temp>0){
			reverse = reverse*10 + (temp % 10);	// 注意不是 +=
			temp /= 10;
		}
		if(reverse == n*9){
			printf("%d\n", n);
		}
	}
	return 0;
}