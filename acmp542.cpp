#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int B(int m)
{
    string str;
    while (m!=0)
    {
        if (m%2==0) str='0'+str;
        else str='1'+str;
        m/=2;
    }
    int s=0;
    for (int i=0;i<str.length();i++)
    {
        if (str[i]=='1')
        {
            s+=pow(2.0,i);
        }
    }
    return s;
}
int main()
{
    int m;
	cin>>m;
    cout<<B(m);
    return 0;
}
