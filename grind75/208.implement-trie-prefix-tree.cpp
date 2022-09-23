/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    struct Node {
        bool is_word;
        Node* children[26];
        Node()
        {
            is_word = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    int char_index(char c)
    {
        return c - 97;
    }

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        if (search(word))
            return;
        Node* temp = root;
        int i = 0;
        for(; i < word.length(); i++)
        {
            if (temp->children[char_index(word[i])] == nullptr)
                break;
            temp = temp->children[char_index(word[i])];
        }
        for (; i < word.length(); i++)
        {
            Node* new_node = new Node();
            temp->children[char_index(word[i])] = new_node;
            temp = new_node;
        }
        temp->is_word = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[char_index(word[i])] == nullptr)
                return false;
            temp = temp->children[char_index(word[i])];
        }
        if (temp->is_word == false)
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (temp->children[char_index(prefix[i])] == nullptr)
                return false;
            temp = temp->children[char_index(prefix[i])];
        }
        return true;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

