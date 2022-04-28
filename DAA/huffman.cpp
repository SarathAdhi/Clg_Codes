#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct minheapnode
{
    char data;
    unsigned freq;
    minheapnode *left, *right;
    minheapnode(char data, unsigned freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

struct compare
{
    bool operator()(minheapnode* l, minheapnode *r)
    {
        return(l->freq > r->freq);
    }
};

void printcodes(struct minheapnode* root, string str)
{
    if(!root)
        return;
    
    if(root->data != '$')
        cout<< root->data <<"="<<str<<'\n';
    
    printcodes(root->left, str+"0");
    printcodes(root->right, str+"1");
}

void huffmancodes(char data[], int freq[], int size)
{
    struct minheapnode *left, *right, *top;
    priority_queue<minheapnode*, vector<minheapnode*>, compare> minheap;
    
    for(int i=0;i<size;++i)
        minheap.push(new minheapnode(data[i], freq[i]));
    
    while(minheap.size()!=1)
    {
        left=minheap.top();
        minheap.pop();
        
        right=minheap.top();
        minheap.pop();
        
        top=new minheapnode('$', left->freq+right->freq);
        top->left=left;
        top->right=right;
        minheap.push(top);
        
    }
    printcodes(minheap.top(), "");
}

int countfreq(string s, char c)
{
    int res=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==c)
            res++;
    }
    return res;
}

int not_in(string t, char a)
{
    for(int i=0;i<t.length();i++)
    {
        if(t[i]==a)
            return 0;
    }
    return 1;
}

int main()
{
    cout<<"test!!";
    string a;
    cin>>a;
    
    string temp="";
    for(int i=0;i<a.length();i++)
        if(not_in(temp,a[i])==1)
            temp=temp+a[i];
    
    int n=temp.length();
    char arr[n];
    int freq[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
        freq[i]=count(a.begin(),a.end(),arr[i]);
    }
        
    int size=sizeof(arr)/sizeof(arr[0]);
    huffmancodes(arr,freq,size);
    return 0;
}