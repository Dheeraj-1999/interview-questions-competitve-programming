#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;

};
int main(){
	struct Node *n1=NULL;
	struct Node *n2=NULL;
	struct Node *n3=NULL;
	n1=(struct Node * )(malloc(sizeof(Node)));
	n2=(struct Node * )(malloc(sizeof(Node)));
	n3=(struct Node * )(malloc(sizeof(Node)));
	
	n1->data=10;n1->next=n2;
	n2->data=20;n2->next=n3;
	n3->data=30;n3->next=NULL;
	
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",n1,n2,n3);
	return 0;
}
