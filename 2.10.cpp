// 查找学生信息
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student{
	char no[20];
	char name[20];
	char sex[5];
	int age;
	bool operator < (const Student &b) const{
		return strcmp(no, b.no)<0;
	}
}buf[1000];

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n)==1){
		for(int i=0; i<n; i++){
			scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
		}
		sort(buf, buf+n);
		// for(int i=0; i<n; i++){
		// 	printf("%s\n", buf[i].no);
		// }

		int t;
		scanf("%d", &t);
		while(t-- != 0){
			char search[20];
			scanf("%s", search);
			int ans=-1, base=0, top=n-1;
			int mid;
			while(base<=top){
				mid = (base+top)/2;
				int tmp = strcmp(search, buf[mid].no);
				if(tmp == 0){
					ans = mid;
					break;
				}
				else if(tmp < 0){
					top = mid-1;
				}
				else{
					base = mid+1;
				}
			}
			if(ans == -1){
				printf("%s", "No Answer!");
			}
			else{
				printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
			}
		}
	}
	return 0;
}