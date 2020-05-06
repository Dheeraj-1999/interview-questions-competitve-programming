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
	temp=(node*)malloc(sizeof(node));
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

struct node* merge(struct node *headA, struct node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
  node *temp = NULL, *head_;
  int cnt = 0;
  while (headA && headB){
      if (headA->value > headB->value){
          if (temp == NULL){
              head_ = headB;
              temp = headB;
          }
          else temp->next = headB;
          headB = headB->next;
      }
      else if (headA->value < headB->value){
          if (temp == NULL){
              head_ = headA;
              temp = headA;
          }
          else temp->next = headA;
          headA = headA->next;
      }
      else {
          if (temp == NULL){
              head_ = headB;
              temp = headB;
              headB = headB->next;
              temp->next = headA;
              headA = headA->next;
              cnt++;
          }
          else {
              temp->next = headB;
              headB = headB->next;
              temp = temp->next;
              temp->next = headA;
              headA = headA->next;
          }
      }
      if (cnt)
          temp = temp->next;
      cnt++;
  }
    
  while (headA){
    if (temp == NULL){
        head_ = headA;
        temp = headA;
        headA = headA->next;
    }
      else{
        temp->next = headA;
          headA = headA->next;
        temp = temp->next;
      }
  }
    
  while (headB){
    if (temp == NULL){
        head_ = headB;
        temp = headB;
        headB = headB->next;
    }
      else{
        temp->next = headB;
        headB = headB->next;
        temp = temp->next;
      }
  }    
  return head_;
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

int main(){
	struct node *llist1,*llist2,*t1;
	cout<<"\nenter the elements for first list\n";
	llist1=createlist();
	cout<<"\nenter the elements for second list\n";
	llist2=createlist();
	t1=merge(llist1,llist2);
	print(t1);
	return 0;
}
