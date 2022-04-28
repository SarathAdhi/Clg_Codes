#include <iostream>
#include<string.h>

using namespace std;

int CheckString(string s1, string s2) {
        
        if(s2.size() > s1.size())
            return -1;
        if(s1.size()==0 && s2.size()==0)
            return 0;
        if(s1.size()==0)
            return -1;
        
        for(int i=0,j=0;i<s1.size()-s2.size()+1;i++)
        {
            while(s1[i+j]==s2[j] && j<s2.size())
            {
                j++;
            }
            if(j==s2.size())
                return i;
            else
            {
                j=0;
            }
        }
        return -1;
    }

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int x = CheckString(s1, s2);
    if(x == -1) {
        cout<<"no string matching";
    } else {
        cout<<x;
    }
}
