#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABETSIZE = 26;
 
struct Node{
    Node* children[ALPHABETSIZE];
    int cntWords;
    int cntPrefs;
    Node(){
        memset(children,NULL,sizeof children);
        cntWords = 0;
        cntPrefs = 0;
    }
};
Node* root;
 
void add(const string& a){
    Node* cur = root;
    for (char c:a){
        int i = c-'a';
        cur->cntPrefs++;
        if(!cur->children[i])cur->children[i] = new Node();
        cur = cur->children[i];
    }
    cur->cntPrefs++;
    cur->cntWords++;
}
int find(const string& a){
    Node* cur = root;
    for (char c:a){
        int i = c-'a';
        if(!cur->children[i])return 0;
        cur = cur->children[i];
    }
    return cur->cntWords;
}
void del(const string& a){
///TODO
}
 
int main(){
    root = new Node();
    add("Hello");
    add("World");
    add("Hello");
    add("aab");
    add("aabc");
    add("aba");
    cout << find("Hello") << endl;
    cout << find("aab") << endl;
    cout << find("aabc") << endl;
    cout << find("a") << endl;
    return 0;
}
 

//// binary trie ;



#include<bits/stdc++.h>
using namespace std;

struct node {
    node* child[2];
    int num;

    node() {
        memset(child, NULL, sizeof child);
        num = 0;
    }

};

node *root;

void add(int x) {
    node *current = root;
    for (int i = 31; i >= 0; i--) {
        int index = 1 & (x >> i);
        if (!current->child[index]) {
            current->child[index] = new node();
        }
        current = current->child[index];
        current->num++;
    }
}

int find(int x) {
    node *current = root;
    int y = 0;
    for (int i = 31; i >= 0; i--) {
        int index = (x >> i)&1;
        index ^= 1;
        if (!current->child[index] || current->child[index]->num <= 0) {
            index ^= 1;
        }
        y = y | (index << i);

        current = current->child[index];
    }
    return y^x;
}

void del(int x) {
    node *current = root;
    for (int i = 31; i >= 0; i--) {
        int index = 1 & (x >> i);
        current = current->child[index];
        current->num--;
    }
}

int main() {
    root = new node();
    add(0);
    int q;
    cin>>q;
    while (q--) {
        char op;
        int num;
        cin >> op>>num;
        if (op == '+')add(num);
        if (op == '-') {
            del(num);
            add(0);
        }
        if (op == '?')cout << find(num) << endl;
    }
}