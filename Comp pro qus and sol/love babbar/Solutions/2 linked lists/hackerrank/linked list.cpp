#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
	int value;
	struct node *next;
};
struct node *s=NULL;
struct node *start=NULL;
struct node * createNode(){
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}
void insertNode(){
	int value;
	struct node *t1,*temp2;
	temp2=createNode();
	cout<<"\n";
	cout<<"enter the node";
	cin>>temp2->value;
	temp2->next=NULL;
		t1=start;
		if (start==NULL){
			start=temp2;
		}
		else{
		
			while(t1->next!=NULL){
				t1=t1->next;
			}
			t1->next=temp2;
		}
	cout<<"\nnode inserted\n";
	
}
void deleteNodeEnd(){
	cout<<"\n";
	if(start==NULL){
		cout<<"\nempty list"<<endl;
	}
	else{
		
		struct node *t1,*t2,*t3;
		t1=t3=start;
		t2=start->next;
		while(t2!=NULL){
			t3=t2;
			t2=t2->next;
			if(t2!=NULL){
				t1=t3;
			}
			
		}	
		if(t1->next!=NULL){
			t1->next=NULL;
		}
		else{
			start=start->next;
		}
		cout<<"\nLast node deleted\n";
	}
}
void DeleteFront(){
	if(start==NULL){
		cout<<"\nempty list"<<endl;
	}
	else{
		start=start->next;
		cout<<"\nfront element deleted\n";
	}
}
void insertFront(){
	struct node *temp;
	temp=createNode();
	cout<<"\nenter the node which should be inserted at front\n";
	cin>>temp->value;
	temp->next=start;
	start=temp;
	cout<<"\nnode inserted at the front"<<endl;
}
void deleteAll(){
	start=NULL;
	cout<<"\nall elments deleted"<<endl<<"list empty\n";
	
}
void insertNodeBetween(){
	int value,pos;
	int count=0;
	pos=0;
	struct node *t1,*temp2,*t2;
	temp2=createNode();
	cout<<"\n";
	cout<<"enter the node";
	cin>>temp2->value;
	cout<<"\nenter the position after which node should be enterd:"<<endl;
	cin>>pos;
	temp2->next=NULL;
		t1=start;
		if (start==NULL){
			start=temp2;
		}
		else{
		
			while(t1->next!=NULL){
				count=count+1;
				t1=t1->next;
				if(count==pos){
					t2=t1->next;
					t1->next=temp2;
					temp2->next=t2;
					break;
				}
			}
		}
	cout<<"\nnode inserted\n";
	
}
void deleteNodeBetween(){
	struct node **store_start_address;
	int count=0;int pos=0;
	cout<<"\nenter the positon of node to be deleted \n";
	cin>>pos;
	if(start==NULL){
		cout<<"\nempty list"<<endl;
	}
	else{
		struct node *t1,*t2;
		t1=start;
		t2=start->next;
		if(pos==0){
			start=t2;
		}
		else{
		
			while(t2!=NULL){
				count=count+1;
				if(count==pos){
					t1->next=t2->next;
					break;
				}
				else{
					t2=t2->next;
					t1=t1->next;
				}
			}
		}
			cout<<"\nnode deleted";
	}
}
void reverseList(){
	struct node *t1,*t2;
	t1=t2=NULL;
	while(start!=NULL){
		t2=start->next;
		start->next=t1;
		t1=start;
		start=t2;
	}	
	start=t1;
	cout<<"\nlinked list reversed\n";
}
bool cycleDetection(struct node * start){
	struct node *hare,*tortoise,*temp;
	hare=start;
	tortoise=start;
	temp=hare->next;
	while(hare!=tortoise||hare==NULL){
		tortoise=tortoise->next;
		hare=temp->next;
		temp=hare->next;
	}
	if(hare==tortoise){
		return 1;
	}
	else if(hare==NULL)
		return 0;
	
}
void print(){
	cout<<"\n";
	if(start==NULL){
		cout<<"\nempty list"<<endl;
	}
	else{
		
		struct node *t,*t2,*temp;
		t=start;
		while(t!=NULL){
			cout<<t->value<<" ";
			t=t->next;
		}
		cout<<"\n";
	}
}
int menu(){
	int i;
	cout<<"\n1. insert the node at the end";
	cout<<"\n2. delete the front node";
	cout<<"\n3. insert the node at front";
	cout<<"\n4. delete the node at the end";
	cout<<"\n5. print the node";
	cout<<"\n6. delete all the nodes";
	cout<<"\n7. insert the node in between";
	cout<<"\n8. delete the node in between";
	cout<<"\n9.Reverse a linked list";
	cout<<"\n10.exit\n";
	cin>>i;
	return i;
}
int main(){
	while(1){
		
		switch(menu()){
			case 1:
				insertNode();
				break;
			case 2:
				DeleteFront();
				break;
			case 3 :
				insertFront();
				break;
			case 4:
				deleteNodeEnd();
				break;
			case 5:
				print();
				break;
			case 6:
				deleteAll();
				break;	
			case 7 :
				insertNodeBetween();
				break;
			case 8 :
				deleteNodeBetween();
				break;
			case 9 :
				reverseList();
				break;		
			case 10 :
				comparelist();
				break;		
			case 11:
				exit(0);
		}
	}
	return 0;
}
