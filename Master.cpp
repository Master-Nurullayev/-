#include <stdio.h>
#include <map>
using namespace std;
int a,b,c;    

map< int,int>mp;int i=0;
map< int,int>::iterator it;

int main(){
    	scanf("%d%d",&a,&b);
for(i;i<a;i++){
    scanf("%d",&c);
    mp[c]=1;
    
}
for(i=0;i<b;i++){
    scanf("%d",&c);
    if(mp[c]>=1)
      mp[c]++;
    else mp[c]=0;
    
}
for(it=mp.begin();it!=mp.end();it++){
        if(it->second>1){       
               printf("%d%c",it->first,' ');                
        }   
}
    return 0;
}
