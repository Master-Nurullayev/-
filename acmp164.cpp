#include <bits/stdc++.h>
using namespace std;
int gg(int h){
    int a=0;
    while(h!=0){
        a+=h%10;
        h=h/10;
    };
    if(a<10)
    return a;
    else {
        gg(a);
    }
}
int main(){
	string a;
	getline(cin,a);
	int k=1,l=0,r=0;
	while(k!=a.size()){
		for(int i=0;i<k;i++){
			l+=(int)a[i]-48;
		}
		for(int i=k;i<a.size();i++){
			r+=(int)a[i]-48;
		}
		//cout<<l<<' '<<r<<endl;
		
		if(gg(l)==gg(r)){
			cout<<"YES";
			return 0;
		}
		else{
			k++;
			r=0;
			l=0;
		}
	}
	cout<<"NO";
	return 0;
}
