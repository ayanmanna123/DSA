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

    bool serch(string word)
    {
        return serchutil(root, word);
    }

    bool serchutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return serchutil(child, word.substr(1));
    }

    bool prefix(string word)
    {
        return prafixserch(root, word);
    }
    bool prafixserch(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return prafixserch(child, word.substr(1));
    }

    string longestCommonPrefix()
    {
        string prefix = "";
        TrieNode *curr = root;

        while (true)
        {
            int count = 0;
            TrieNode *next = NULL;

            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != NULL)
                {
                    count++;
                    next = curr->children[i];
                }
            }

            if (count == 1 && !curr->isterminal)
            {
                prefix += next->data;
                curr = next;
            }
            else
            {
                break;
            }
        }

        return prefix;
    }
    void suggestWords(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int index = c - 'A';
            if (node->children[index] == NULL)
            {
                cout << "No suggestions found for prefix: " << prefix << endl;
                return;
            }
            node = node->children[index];
        }

        vector<string> suggestions;
        collectAllWords(node, prefix, suggestions);

        if (suggestions.empty())
        {
            cout << "No suggestions found for prefix: " << prefix << endl;
        }
        else
        {
            cout << "Suggestions for \"" << prefix << "\":" << endl;
            for (string word : suggestions)
            {
                cout << "- " << word << endl;
            }
        }
    }

    // Helper to collect all words from a given node
    void collectAllWords(TrieNode *node, string currentWord, vector<string> &result)
    {
        if (node->isterminal)
        {
            result.push_back(currentWord);
        }
        for (int i = 0; i < 26; ++i)
        {
            if (node->children[i])
            {
                char nextChar = 'A' + i;
                collectAllWords(node->children[i], currentWord + nextChar, result);
            }
        }
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

    cout << t->serch("CADMIAM") << endl;   
    cout << t->prefix("CAD") << endl;     
    cout << t->longestCommonPrefix() << endl;  

    t->suggestWords("CA");  
    t->suggestWords("CAP");  
    t->suggestWords("CAT");  

}