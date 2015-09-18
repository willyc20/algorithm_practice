#include<iostream>
#include<cstring>
#include<cstdio>
#include"permu.h"
int main(){
    std::string s;
    std::cin>>s;
    char li[s.length()];
    strcpy(li,s.c_str());
    Permu p;
    p.permutations(li,0,s.length());
}
