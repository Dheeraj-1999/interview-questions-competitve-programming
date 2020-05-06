#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
	
};
int main(){
	struct Node * n1 = NULL;
	struct Node * n2 = NULL;
	struct Node * n3 = NULL;
	n1=(struct Node * )(malloc(sizeof(Node)));
	n2=(struct Node * )(malloc(sizeof(Node)));
	n3=(struct Node * )(malloc(sizeof(Node)));
	
	n1->data=10;
	n2->data=20;
	
	n3->data=30;
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;
	
	printf("%d\n",n1->data);printf("%d\n",n2->data);printf("%d\n",n3->data);printf("%d\n",n1->next);printf("%d\n",n2);
	printf("%d\n",n2->next);printf("%d\n",n3);printf("%d\n",n3->next);printf("%d\n",*n3);
	
	free(n1);free(n2);free(n3);
	return 0;
}
