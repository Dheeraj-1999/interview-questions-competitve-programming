#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node{
	int data ;
	struct node *next;
};

void display(int data){
	cout<<data<<"\n";
	
}
void push(struct node * head_ref){
	int new_data;
	cout<<"enter the next node value";
	cin>>new_data;
	struct node *NewNode;
	NewNode=(struct node * )(malloc(sizeof(node)));
	NewNode->next=head_ref;
	NewNode->data=new_data;
	display(NewNode->data);
}

	
int main(){
	struct node * head;
	head=(struct node * )(malloc(sizeof(node)));
	cout<<"enter the first element";
	cin>>head->data;
	display(head->data);
	//head_ref=head->next;
	push(head->next);
	
	
	return 0;	
}

