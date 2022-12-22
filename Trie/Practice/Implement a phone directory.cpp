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
    TrieNode *root;
   public:
    int count;
    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    void printsugges(TrieNode *curr,string prefix,vector<string> &temp)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++)
        {
            TrieNode *next=curr->children[ch-'a'];
            if(next!=0)
            {
                prefix.push_back(ch);
                printsugges(next,prefix,temp);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> suggestions(string &queryStr)
    {
        vector<vector<string>> ans;
        TrieNode *prev=root;
        string prefix="";      
        for(int i=0;i<queryStr.length();i++)
        {
             char lastch=queryStr[i];
            prefix.push_back(lastch);
             TrieNode *curr=prev->children[lastch-'a'];
        if(curr==0)
        {
            break;
        }
        vector<string> temp;
        printsugges(curr,prefix,temp);
        ans.push_back(temp);
        temp.clear();
            prev=curr;
        }     
        return ans;
    }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t=new Trie();
    for(int i=0;i<contactList.size();i++)
        {
            string h=contactList[i];
            t->insertWord(h);
        }
    return t->suggestions(queryStr);
//     string hv="";
//     for(int i=0;i<queryStr.length();i++)
//     {
//         hv.push_back(queryStr[i]);
//         vector<string> shv;
//         TrieNode *hroot=t->search(hv);
//         if(hroot!=0)
//         {
//             t->complete(hroot,hv,"",shv);
//         }
//         v.push_back(shv);
//     }
        
//         else
//         {
//             return ;
//         }
//     return v;
    //    Write your code here.
}
