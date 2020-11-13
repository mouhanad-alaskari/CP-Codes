#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* children[30];
    int cntWords;
    int cntPrefs;
    Node()
    {
        memset(children,NULL,sizeof children);
        cntWords = 0;
        cntPrefs = 0;
    }
};

Node* root;

void add(const string& s)
{
    Node* cur = root;
    for(char c:s)
    {
        int x = c -'0';
        /// int x= c - 'a';
        cur->cntPrefs++;
        if(!cur->children[x])
        {
            cur->children[x] = new Node();
        }
        cur = cur->children[x];
    }
    cur->cntPrefs++;
    cur->cntWords++;
}


int find(const string& s)
{
    int ans=0;
    int l=s.length();
    Node* cur = root;
    for(int i=0 ; i<s.length() ; i++)
    {
        int x = s[i]-'0';
        /// int x = s[i]-'a';
        if(cur->children[x] && cur->children[x]->cntPrefs)
        {
            cur = cur->children[x];
            /// ans+=(x)*(1<<(l-i-1));
        }

        else
        {
            cur = cur->children[!x];
            /// ans+=(!x)*(1<<(l-i-1));
        }
    }

    return ans;
}

void del(const string& s)
{
    Node* cur = root;
    for (char c:s)
    {
        int x = c-'0';
        /// int x = c-'a';
        cur->cntPrefs--;
        if(!cur->cntPrefs)
            return ;

        cur = cur->children[x];
    }
    cur->cntPrefs--;
    cur->cntWords--;
}

int main()
{
    root = new Node();

}
