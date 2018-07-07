#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int a, b;
	char str[40];
	while(scanf("%d%s%d", &a, str, &b) != EOF){
		int dec=0, size = strlen(str);
		for(int i=0; i<size; i++){
			int x;
			if(str[i]>='0' && str[i]<='9')
				x = str[i] - '0';
			else if(str[i]>='a' && str[i]<='z')
				x = str[i] - 'a' + 10;
			else
				x = str[i] - 'A' + 10;
			dec = dec*a + x;
		}
		// printf("%d\n", dec);
		char ans[40];
		size = 0;
		do{
			int x = dec % b;
			ans[size++] = x<10? '0'+x: 'A' + x -10;
			dec /= b;
		}while(dec>0);
		// ans[size++] = '\0';
		for(int i=size-1; i>=0; i--){
			printf("%c", ans[i]);
		}
		printf("\n");

	}
	return 0;
}