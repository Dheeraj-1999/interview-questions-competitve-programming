#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
	int value;
	struct node *next;
};
struct node * createNode(){
	struct node *temp;
	temp=new node;
	return temp;
}
struct node * insertNode(struct node *start){
	int value;
	struct node *t1,*temp2;
	t1=temp2=NULL;
	temp2=createNode();
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
		return start;
}
struct node * merge(struct node *llist1 , struct node *llist2){
	struct node *p,*q,*s,*new_head;
	p=llist1;
	q=llist2;
	if(p&&q){
		if(p->value<q->value){
			s=p;
			p=s->next;
		}
		else{
			s=q;
			q=s->next;
		}
		new_head=s;
	}
	while(q&&p){
		if(p->value<q->value){
			s->next=p;
			s=p;
			p=s->next;
			
		}
		else{
			s->next=q;
			s=q;
			q=s->next;
		}
	}
	if(q==NULL){
		s->next=p;
	}
	else{
		s->next=q;
	}
	return new_head;
}
void print(struct node *start){
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
struct node * createlist(){
	int i,n;
	struct node *head=NULL;
	cout<<"enter the length of a list";
	cin>>n;
	for(i=0;i<n;i++){
		head=insertNode(head);
	}
	cout<<"\nlist is created\n";
	return head;
}
int main(){
	struct node *llist1,*llist2,*t1;
	cout<<"\nenter the elements for first list\n";
	llist1=createlist();
	cout<<"\nenter the elements for second list\n";
	llist2=createlist();
	t1=merge(llist1,llist2);
	print(t1);
	delete llist1;
	delete llist2;
	return 0;
}
