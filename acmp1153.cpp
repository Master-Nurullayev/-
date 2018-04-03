#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
        string a;
        getline(cin,a);
        int k=0,l,ans=0;
         
    for(int i=0;i<a.size();i++){
       if(a[i]!='a'&&a[i]!='u'&&a[i]!='i'&&a[i]!='o'&&a[i]!='e'&&a[i]!='y'){
            ans++;
            if(ans>2){
                k++;
                 ans=1;
            }
        }else{
            ans=0;
        } 
    }
    ans=0;
    for(int i=0;i<a.size();i++){
         
        if(a[i]=='a'||a[i]=='u'||a[i]=='i'||a[i]=='o'||a[i]=='e'||a[i]=='y'){
            ans++;
            if(ans>2){
                k++;
                ans=1;
            }
        }else{
            ans=0;
        } 
    }
        cout<<k;
    return 0;
}
