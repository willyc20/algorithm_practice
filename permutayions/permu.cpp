#include"permu.h"
void Permu::permutations(char *li, int i, int n){
    int j,temp;
    if(i==n){
        for(j=0;j<n;j++)
            std::cout<<li[j];
        std::cout<<"\n";
    }
    else{
        for(j=i;j<n;j++){
            swp(li[i],li[j],temp);
            permutations(li,i+1,n);
            swp(li[i],li[j],temp);
        }
    }
}
