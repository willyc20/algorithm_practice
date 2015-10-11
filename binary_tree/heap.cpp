#include<iostream>
#define MAXN 1000
using namespace std;
int heap[MAXN];//use array instead of ptr
int size=0;
void push(int x){
	int i=size++;
	while(i>0){
		int p=(i-1)/2;
		if(heap[p]<=x)break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i]=x;
}
int top(){
	return heap[0];
}
void pop(){
	int x=heap[--size];
	int i=0;
	while(i*2+1<size){
		int l=i*2+1;
		int r=i*2+2;
		if(r<size&&heap[r]<heap[l])l=r;
		if(heap[l]>=x)break;
		heap[i]=heap[l];
		i=l;
	}
	heap[i]=x;
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		push(n);
	}
	while(size>0){
		cout<<top()<<"\n";
		pop();
	}
}