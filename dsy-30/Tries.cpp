#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isterminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};
class trie
{
public:
    trie()
    {
        root = new TrieNode('\0');
    }
    TrieNode *root;
    void insertutic(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertutic(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertutic(root, word);
    }


    bool serch(string word){
        return serchutil(root,word);
    }


    bool serchutil(TrieNode *root, string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index = word[0]-'A';
        TrieNode* child;
        if(root->children[index]!= NULL){
            child=root->children[index];

        }else{
            return false;
        }
        return serchutil(child,word.substr(1));
    }


     bool prefix(string word){
        return prafixserch(root,word);
    }
     bool prafixserch(TrieNode *root, string word){
        if(word.length()==0){
            return true;
        }
        int index = word[0]-'A';
        TrieNode* child;
        if(root->children[index]!= NULL){
            child=root->children[index];

        }else{
            return false;
        }
        return prafixserch(child,word.substr(1));
    }
    
    string longestCommonPrefix() {
        string prefix = "";
        TrieNode* curr = root;

        while (true) {
            int count = 0;
            TrieNode* next = NULL;

            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != NULL) {
                    count++;
                    next = curr->children[i];
                }
            }

            if (count == 1 && !curr->isterminal) {
                prefix += next->data;
                curr = next;
            } else {
                break;
            }
        }

        return prefix;
    }
};

int main()
{
    trie *t = new trie();
    t->insertword("CANDY");
    t->insertword("CADMIAM");
    t->insertword("CAW");
    t->insertword("CAPITAL");
    t->insertword("CAPTAIN");
  cout << t->serch("CADMIAM") <<endl;
  cout<< t->prefix("CAD") <<endl;
  cout << t->longestCommonPrefix()<<endl;

}