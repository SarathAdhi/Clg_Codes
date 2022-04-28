#include<iostream>
#include<cstring>

using namespace std;

void lcs(char *s1, char *s2, int m, int n)
{
    int lt[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                lt[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                lt[i][j]=1+lt[i-1][j-1];
            else
                lt[i][j]=max(lt[i-1][j], lt[i][j-1]);
        }
    }
    
    int ind=lt[m][n];
    char lmat[ind+1];
    lmat[ind]='\0';
    
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lmat[ind-1]=s1[i-1];
            j--;
            i--;
            ind--;
        }
        
        else if(lt[i-1][j]>lt[i][j-1])
            i--;
        else
            j--;
    }
    cout<<strlen(lmat)<<"\n";
    cout<<lmat<<"\n";
}

int main()
{
    char s1[100];
    char s2[100];
    cin>>s1;
    cin>>s2;
    int m=strlen(s1);
    int n=strlen(s2);
    lcs(s1,s2,m,n);
}