// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// I have mainly used trie data structure as searching and adding of word only takes o(word) size
// of time. But the complex case here is that the words can consists of '.'. Now for
// searching the word we have to explore all the possible outcomes as which can be matched to the word. 
// addWord take time complexity of O(words.size)
// search trie takes time complexity of (26^n) or we can say O(sum of all words size)
// as we are travering all the nodes of the trie.
// Time Complexity - O(26^n), Space Complexity - O(sum of words size)
class WordDictionary {
public:
    struct trie {
        bool isend = false;
        trie *alpha[26];
    };
    
    trie *head;
    
    WordDictionary() {
        head = new trie();
    }
    
    void addWord(string word) {
        trie *temp = head;
        for (int i = 0; i < word.size(); i++) {
            if (temp->alpha[word[i] - 'a'] == NULL)
                temp->alpha[word[i] - 'a'] = new trie();
            temp = temp->alpha[word[i] - 'a'];
        }
        temp->isend = true;
    }
    
    bool searchTrie(trie *top, string word) {
        if (word.size() == 1 && word[0] == '.') {
            for (int i = 0; i < 26; i++)
                if (top->alpha[i] != NULL && top->alpha[i]->isend)
                    return true;
            return false;
        }
        else if (word.size() == 1) {
            if (top->alpha[word[0] - 'a'] != NULL)
                return top->alpha[word[0] - 'a']->isend;
            return false;
        }
        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {
                if (top->alpha[i] != NULL) {
                    if (searchTrie(top->alpha[i], word.substr(1)))
                        return true;
                }
            }
            return false;
        }
        else {
            if (top->alpha[word[0] - 'a'] != NULL)
                return searchTrie(top->alpha[word[0] - 'a'], word.substr(1));
            return false;
        }
    }
    
    bool search(string word) {
        return searchTrie(head, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */