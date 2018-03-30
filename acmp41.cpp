#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b,c;
    cin>>a;
map<int,int>mp;
for(int i=0;i<a;i++){
    scanf("%d",&b);
    if(mp[b]>=1)
        mp[b]++;
        else
    mp[b]=1;
}
for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
    cout<<it->first<<' ';
        if(it->second>1){
            for(int i=it->second-2;i>=0;i--)
                printf("%d ",it->first);
        }   
}
 
 
     
    return 0;
}
