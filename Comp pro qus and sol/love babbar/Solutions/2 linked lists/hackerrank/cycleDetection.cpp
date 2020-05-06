#include<iostream>
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

bool cycleDetection(struct node * start){
	struct node *hare,*tortoise,*temp;
	hare=start;
	tortoise=start;
	temp=start->next;
	tortoise=tortoise->next;
	hare=temp->next;
	cout<<"\n"<<hare<<"\n"<<tortoise<<"\n";
	while(hare!=tortoise||hare==NULL){
		tortoise=tortoise->next;
		hare=temp->next;
		if (hare!=NULL) temp=hare->next;
	}
	cout<<"\n"<<hare<<"\n"<<tortoise<<"\n";
	if(hare==tortoise){
		return 1;
	}
	else if(hare==NULL)
		return 0;
	
}
int main(){
	struct node *llist1;bool t1;
	cout<<"\nenter the elements for first list\n";
	llist1=createlist();
	t1=cycleDetection(llist1);
	if(t1==1){
		cout<<"cycle detected";
	}
	else cout<<"no cycle detected";
	delete llist1;
	return 0;
}
