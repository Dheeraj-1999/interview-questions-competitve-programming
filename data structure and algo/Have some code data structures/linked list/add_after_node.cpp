#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node{
	int data ;
	struct node *next;
};

void display(){
	while(address!=null){
		cout << data;
	}
	
}
void push(struct node * head_ref){
	struct node *b,*a;
	b=head_ref;
	int new_data;
	cout<<"enter the next node value";
	cin>>new_data;
	struct node *NewNode;
	NewNode=(struct node * )(malloc(sizeof(node)));
	NewNode->next=head_ref;
	NewNode->data=new_data;
	a=head_ref;
	head_ref=NewNode;
	
	display(a,b);
	
}

	
int main(){
	int a=1;
	struct node * head;
	head=(struct node * )(malloc(sizeof(node)));
	cout<<"enter the first element";
	
	cin>>head->data;
	head->next=NULL;
	while(a==1){
		push(head);
		cout<<"press 1 to enter the element";
		cin>>a;
	}
	
	
	return 0;	
}

