#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 100
#define MAXFILTER 1000000000LL
using namespace std;
void radixsort(int *arr){
	int temp[MAXN][MAXN]={};
	int index[MAXN]={0};
	int n=1;
	while(n<=MAXFILTER){
		for(int i=0;i<MAXN;i++){
			int lsd=(arr[i]/n)%10;
			temp[lsd][index[lsd]]=arr[i];
			index[lsd]++;
		}
		int k=0;
		for(int i=0;i<10;i++){
			if(index[i]>0){
				for(int j=0;j<index[i];j++){
					arr[k]=temp[i][j];
					k++;
				}
			}
			index[i]=0;
		}
		n*=10;
	}
}
int main(){
	int arr[MAXN];
	for(int i=0;i<MAXN;i++){
		arr[i]=rand();
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	radixsort(arr);
	for(int i=0;i<MAXN;i++){
		//arr[i]=rand();
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}