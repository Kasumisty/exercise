#include <stdio.h>
#include <string.h>
#define MAX 1000
struct bigInteger
{
	int digit[MAX];
	int size;
	void init(){
		for(int i=0; i<MAX; i++){
			digit[i]=0;
		}
		size=0;
	}
	void set(char *str){
		init();
		int length = strlen(str);
		for(int i=length-1; i>=0; i-=4){
			int x=0;
			for(int j=3; j>=0; j--){
				if(i-j<0)	continue;
				x = x*10 + (str[i-j] - '0');
			}
			digit[size++]=x;
		}
	}
	void output(){
		for(int i=size-1; i>=0; i--){
			if(i != size-1){
				printf("%04d", digit[i]);
			}
			else	printf("%d", digit[i]);
		}
		printf("\n");
	}
	bigInteger operator + (const bigInteger &a) const{
		bigInteger res;
		res.init();
		int carry=0;
		for(int i=0; i<a.size || i<size; i++){
			int x = digit[i] + a.digit[i] + carry;
			carry = x/10000;
			res.digit[res.size++] = x % 10000;
		}
		if(carry!=0){
			res.digit[res.size++] = carry;
		}
		return res;
	}
}a,b,c;
int main(int argc, char const *argv[])
{
	char str1[1002], str2[1002];
	while(scanf("%s%s", str1, str2) != EOF){
		a.set(str1);
		b.set(str2);
		// a.output();
		// b.output();
		c = a+b;
		c.output();
	}
	return 0;
}