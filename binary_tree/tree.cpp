#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct node{
	int data;
	int index;
	node *l;
	node *r;
};
node *new_node(int data, int ind){
  node *ptr = (node*)malloc(sizeof(node));
  ptr->l = ptr->r = NULL;
  ptr->data = data;
  ptr->index = ind;
  return ptr;
}
void insert(node* node, int tar, int ind){
	if(tar<=node->data){
		if(node->l==NULL){
			node->l=new_node(tar,ind);
		}
		else
			insert(node->l,tar,ind);
	}
	else{
		if(node->r==NULL){
			node->r=new_node(tar,ind);
		}
		else
			insert(node->r,tar,ind);
	}
}
void search(node * node, int tar){
	if(tar==node->data){
		printf("%d\n",node->index);
	}
	else if(tar<node->data){
		if(node->l==NULL)
			printf("Not found.\n");
		else
			search(node->l,tar);
	}
	else{
		if(node->r==NULL)
			printf("Not found.\n");
		else
			search(node->r,tar);
	}
}
int main(){
	int t,n,d;
	scanf("%d",&n);
	scanf("%d",&d);
	node* root=new_node(d,0);
	for(int i=1;i<n;i++){
		scanf("%d",&d);
		insert(root,d,i);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&d);
		search(root,d);
	}
}