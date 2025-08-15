#include <bits/stdc++.h>

using namespace std;

class Trie{
    public:
        vector<Trie*> children;
        bool is_end;

        Trie(): children(vector<Trie*>(26)), is_end(false){}

        void insert(const string &w);
        bool search(const string &w);
};

void Trie::insert(const string &w){
    Trie *node = this;

    for(char c: w){
        if(!node->children[c - 'a']){
            node->children[c - 'a'] = new Trie();
        }
        node = node->children[c - 'a'];
    }
    node->is_end = true;
}

bool Trie::search(const string &w){
    Trie *node = this;
    for(char c: w){
        if(!node->children[c - 'a']){
            return false;
        }
        node = node->children[c - 'a'];
    }
    return node->is_end;
}
