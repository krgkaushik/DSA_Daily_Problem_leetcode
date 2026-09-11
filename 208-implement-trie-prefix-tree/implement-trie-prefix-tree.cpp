class Node{
    public:
    unordered_map<char , Node*>childeren;
    bool enOfword;

    Node(){
        enOfword = false;
    }
};

class Trie {
public:
    Node*root;
    Trie() {
        root = new Node();
        
    }
    
    void insert(string word) {
        Node*temp = root;
        for( int i = 0 ; i<word.size(); i++ ){
            char ch = word[i];

            if( temp->childeren.count(ch) == 0 ){
                temp->childeren[ch] = new Node;
            }
            
                temp = temp -> childeren[ch];
            
        }

        temp -> enOfword = true;
        
    }
    
    bool search(string word) {
        Node*temp = root;

        for( int i = 0; i<word.size(); i++ ){
            char ch = word[i];

            if( temp -> childeren.count(ch) == 0 ){
                  return false;
            }

            temp = temp -> childeren[ch];
        }

        return temp->enOfword;
        
    }
    
    bool startsWith(string prefix) {

        Node*temp = root;

        for( int i = 0; i<prefix.size(); i++ ){
            char ch = prefix[i];
            if( temp -> childeren.count(ch) == 0 ){
                return false;
            }

            temp = temp -> childeren[ch];
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