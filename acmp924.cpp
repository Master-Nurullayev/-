#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
	string s[5];
	cin>>s[0];
	cin>>s[1];
	cin>>s[2];
	cin>>s[3];
	
	for(int i=0;i<3;i++){
		for(int k=0;k<3;k++){
			if(s[i][k]=='B'){
				if(s[i][k+1]=='B'&&s[i+1][k+1]=='B'&&s[i+1][k]=='B'){
					cout<<"No";
					return 0;
				}
			}
			else{
				if(s[i][k+1]=='W'&&s[i+1][k+1]=='W'&&s[i+1][k]=='W'){
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes";
	return 0;
}
