#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Trie
{
    struct Cmp
    {
        Cmp(string lc) : prefix(lc), n(lc.length()) {}
        bool operator()(const std::string &s) const
        {
            if (s.length() < prefix.length())
                return false;
            for (int i = 0; i < n; ++i)
                if (s[i] != prefix[i])
                    return false;
            return true;
        }
        string prefix;
        int n;
    };

    set<string> container;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        container = set<string>();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        container.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return container.find(word) != container.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.empty())
            return true;
        auto iter = container.lower_bound(prefix.substr(0, 1));
        auto range = find_if(iter, container.end(), Cmp(prefix));
        return range != container.end();
    }
};

class Trie2
{
private:
    vector<Trie2 *> children;
    bool isEnd;

    Trie2 *searchPrefix(string prefix)
    {
        Trie2 *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie2() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie2 *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie2();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie2 *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{

    return 0;
}