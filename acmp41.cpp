#include <stdio.h>
#include <iostream>
#include<map>
using namespace std;
int a,b,c; 
map<int,int>mp;
int main(){
  scanf("%d",&a);
for(int i=0;i<a;i++){
    scanf("%d",&b);
    if(mp[b]>=1)
        mp[b]++;
        else
    mp[b]=1;
}
for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
  printf("%d%c",it->first,' ');
        if(it->second>1){
            for(int i=it->second-2;i>=0;i--)
                printf("%d%c",it->first, ' ');
        }   
}
    return 0;
}
