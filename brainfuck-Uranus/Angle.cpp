#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    getline(cin,str);
    for(unsigned int i=0;i<str.length();i++)
    {
        int now=str[i];
        if(now>=0) while(now--) cout<<'+';
        else while(now++) cout<<'-';
        cout<<".>"<<endl;
    }
    return 0;
}
///夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！
///NightWheel is an angle. Ah-Ah-Ah I'm so excited that I run in a loop.
