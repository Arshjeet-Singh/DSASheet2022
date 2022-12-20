/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
// class TrieNode{
//     public:
//     char data;
//     TrieNode *children[26];
//     bool isTerminal;
//     TrieNode(char ch)
//     {
//         data=ch;
//         for(int i=0;i<26;i++)
//         {
//             children[i]=NULL;
//         }
//         isTerminal=false;
//     }
// };
// class Trie {
// public:
//     TrieNode *root;
//     /** Initialize your data structure here. */
//     Trie() {
//         root=new TrieNode('\0');
//     }

//     void insertutil(TrieNode *root,string word)
//     {
//         if(word.length()==0)
//         {
//             root->isTerminal=true;
//             return;
//         }
//          int index=word[0]-'a';
//         TrieNode *child;
//         if(root->children[index]!=0)
//         {
//             child=root->children[index];
//         }
//         else
//         {
//             child=new TrieNode(word[0]);
//             root->children[index]=child;
//         }
//         insertutil(child,word.substr(1));
//     }
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         insertutil(root,word);
//     }

//     /** Returns if the word is in the trie. */
//     bool searchutil(TrieNode *root,string word)
//     {
//         if(word.length()==0)
//         {
//             return root->isTerminal;
//         }
//         int index=word[0]-'a';
//         TrieNode *child;
//         if(root->children[index]!=0)
//         {
//             child=root->children[index];
//         }
//         else
//         {
//             return false;
//         }
//         return searchutil(child,word.substr(1));
//     }
//     bool search(string word) {
//         searchutil(root,word);
//     }
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
   public:
     TrieNode *root;
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insert(string word) { 
        insertWord(root, word); 
    }

    bool search(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if(root->isTerminal==true)
            {
                return true;
            }
            return false;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL && root->children[index]->data==word[0]) {
            child = root->children[index];
            return search(child, word.substr(1));
            
        } else {
            return false;
        }

        // Recursive call
    }
     bool search(string word)
     {
         return search(root,word);
     }
    bool prefixutil(TrieNode *root,string word)
    {
        if(word.length()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=0)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return prefixutil(child,word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    
    bool startsWith(string prefix) {
    return prefixutil(root,prefix);
    }
};
    
// };
