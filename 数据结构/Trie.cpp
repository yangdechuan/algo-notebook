/*
Trie(we pronounce 'try')，也叫前缀树。
参考：LeetCode 208. Implement Trie (Prefix Tree)
 */
#include<cstring>
#include<string>

using namespace std;


struct TrieNode {
    int isEnd;
    TrieNode* links[26];
    TrieNode() {
        isEnd = 0;
        memset(links, NULL, sizeof(links));
    }
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            int idx = ch - 'a';
            if((cur->links)[idx] == NULL){
                (cur->links)[idx] = new TrieNode();
            }
            cur = (cur->links)[idx];
        }
        cur->isEnd = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            int idx = ch - 'a';
            cur = (cur->links)[idx];
            if(cur == NULL) return false;
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            cur = (cur->links)[idx];
            if(cur == NULL) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */