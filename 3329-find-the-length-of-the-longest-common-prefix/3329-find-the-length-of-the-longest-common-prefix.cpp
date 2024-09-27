
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool endWord;
    TrieNode *link[10];
};

class Trie
{

public:
    TrieNode *root;

    Trie()
    {

        root = new TrieNode();
    }

    void insert(string word)
    {

        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (curr->link[word[i] - '0'] == nullptr)
            {
                curr->link[word[i] - '0'] = new TrieNode();
                curr = curr->link[word[i] - '0'];
            }else
            {
                curr=curr->link[word[i]-'0'];
            }
          
        }
        curr->endWord = true;
    }

    int  search(string word)
    {
        int len=0;

        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (curr->link[word[i] - '0'] == nullptr)
            {
               
                return len;
            }
            else
            {
                curr = curr->link[word[i] - '0'];
                len++;
            }
        }

        return len;
    }

  
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        Trie* trie=new Trie();




         for(int i=0;i<arr1.size();i++)
         {
                trie->insert(to_string(arr1[i]));
         }

         int ans=0;

         for(int i=0;i<arr2.size();i++)
         {
            ans=max(ans,trie->search(to_string(arr2[i])));

         }

         return ans;

    
       
    }
};
