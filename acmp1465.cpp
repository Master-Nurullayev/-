#include <stdio.h>
#include<iostream>
long long int  l=1,r=1000000000;
long long int mid=(l+r)/2;
using namespace std;
int main(){
    char a;
 
do{ 
        cout<<mid<<endl;
        cout.flush();
        cin>>a; 
        if(a=='>'){
            l=mid+1;
            mid=(l+r)/2;
        }
        if(a=='<'){
            r=mid-1;
            mid=(l+r)/2;
        }
        if(a=='=') break;
    }while(a!='=');
    return 0;
}
