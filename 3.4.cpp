#include <stdio.h>
#include <string.h>

struct Node{
	Node *lc;
	Node *rc;
	char c;
}Tree[50];

int loc=0;
 Node* create(){
 	Tree[loc].lc = Tree[loc].rc = NULL;
 	return &Tree[loc++];
 }

 char str1[30], str2[30];

 Node *build(int s1, int e1, int s2, int e2){	// e1, e2为越界地址
 	Node* root = create();
 	root->c = str1[s1];
 	int index;
 	for (int i = s2; i < e2; ++i)
 	{
 		if (str2[i] == str1[s1])
 		{
 			index = i;
 			break;
 		}
  	}
  	if (index!=s2){
  		root->lc = build(s1+1, s1+1+(index-s2), s2, index);
  	}
  	if(index!=e2-1){
  		root->rc = build(s1+1+(index-s2), e1, index+1, e2);
  	}
  	return root;
 }

void postorder(Node *t){
	if(t->lc !=NULL){
		postorder(t->lc);
	}
	if(t->rc != NULL){
		postorder(t->rc);
	}
	printf("%c", t->c);
}

 int main(int argc, char const *argv[])
 {
 	while(scanf("%s", str1) != EOF){
 		scanf("%s", str2);
 		loc = 0;
 		int l1 = strlen(str1);
 		int l2 = strlen(str2);
 		Node *T = build(0, l1, 0, l2);
 		postorder(T);
 		printf("\n");
 	}

 	return 0;
 }