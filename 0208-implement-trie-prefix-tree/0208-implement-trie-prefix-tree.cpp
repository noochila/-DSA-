
struct TrieNode{

    bool isEnd;
   TrieNode* link[26];
   
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        

        TrieNode*curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(curr->link[word[i]-'a']==nullptr)
            {
                curr->link[word[i]-'a']=new TrieNode();
               
            }
            curr= curr->link[word[i]-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
          TrieNode*curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(curr->link[word[i]-'a']==nullptr)
            {
               return false;
               
            }
            curr= curr->link[word[i]-'a'];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(string word) {
         TrieNode*curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(curr->link[word[i]-'a']==nullptr)
            {
               return false;
               
            }
            curr= curr->link[word[i]-'a'];
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