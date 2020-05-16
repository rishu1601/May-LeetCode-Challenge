"""
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
"""

class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.children = {}
        
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, pruned: str) -> None:
        currNode = self.root
        for alpha in pruned:
            if alpha not in currNode.children:
                currNode.children[alpha] = TrieNode()
            currNode = currNode.children[alpha]
        currNode.isEnd = True
        

    def search(self, pruned: str) -> bool:
        currNode = self.root
        for alpha in pruned:
            if alpha not in currNode.children:
                return False
            currNode = currNode.children[alpha]
        return currNode.isEnd

    def startsWith(self, pruned: str) -> bool:
        currNode = self.root
        for alpha in pruned:
            if alpha not in currNode.children:
                return False
            currNode = currNode.children[alpha]
        return True
        
