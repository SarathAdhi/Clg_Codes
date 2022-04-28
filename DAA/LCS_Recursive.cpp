#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string LCS(string s1, string s2, int m, int n, auto &lu)
{
    if(m==0 || n==0)
        return string("");
    if(s1[m-1]==s2[n-1])
        return s1[m-1]+LCS(s1,s2,m-1,n-1,lu);
    if(lu[m-1][n] > lu[m][n-1])
        return LCS(s1,s2,m-1,n,lu);
        
    else
    {
        return LCS(s1,s2,m,n-1,lu);
    }
}

void LCSlen(string s1, string s2, int m, int n,auto &lu)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                lu[i][j]=lu[i-1][j-1]+1;
            else
                lu[i][j]=max(lu[i-1][j],lu[i][j-1]);
        }
    }
}

string LCS(string s1, string s2)
{
    int m=s1.length(), n=s2.length();
    vector<vector<int>> lu(m+1, vector<int>(n+1));
    LCSlen(s1,s2,m,n,lu);
    return LCS(s1,s2,m,n,lu);
}

int main()
{
    string s1,s2; 
    cin>>s1;
    cin>>s2;
    string s3=LCS(s1,s2);
    int len=s3.length();
    cout<<len<<"\n";
    reverse(s3.begin(),s3.end());
    cout<<s3;
}