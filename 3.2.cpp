#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
using namespace std;

stack<int> op;
stack<double> in;

char str[220];
int matrix[][5]{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
// int matrix2[][5]{
// 	1,0,0,0,0,
// 	1,1,1,0,0,
// 	1,1,1,0,0,
// 	1,1,1,1,1,
// 	1,1,1,1,1,
// };

void getOp(bool &retop, int retnum, int idx){
	
}

int main(){
	while(gets(str)){
		if(str[0]=='0' && str[0]=='\0')	break;
		bool retop;
		int retnum;
		int idx=0;
		while(!op.empty())	op.pop();
		while(!in.empty())	in.pop();
		while(true){

		}
	}
}