#include<iostream>
using namespace std;
   
int main()
{
   float x,y;
  int years = 1;
  cin>>x>>y;
  while (0.02+x<y) {
    x *= 1.15;
    years++;
  }
  cout<<years;
}
