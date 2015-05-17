class TrieNode:
    # Initialize your data structure here.
    def __init__(self, c = None):
        self.c = c
        self.children = []

    def getChild(self, n):
        for node in self.children:
            if node.c == n:
                return node
        else:
            return None
        
    def add(self, ato):
        if ato:
            n = ato[0]
            child = self.getChild(n)
            if child:
                child.add(ato[1:])
            else:
                self.children.append(TrieNode(n))
                self.children[-1].add(ato[1:])

    def has(self, word):
        if word:
            n = word[0]
            if self.c != n:
                return False
            ato = word[1:]
            for child in self.children:
                if child.has(ato):
                    return True
            return False
        return True

    def isprefix(self, word):
        if word:
            n = word[0]
            if self.c != n:
                return False
            ato = word[1:]
            if ato:
                for child in self.children:
                    if child.isprefix(ato):
                        return True
                return False
            else:
                return False
        return True

class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        self.root.add(word)           


    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        for child in self.root.children:
            if child.has(word):
                return True
        return False

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        for child in self.root.children:
            if child.isprefix(prefix):
                return True
        return False

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("todo")
# trie.insert("togo")
# trie.insert("doing")
# print trie.search("key")
# print trie.search("togo")
# print trie.startsWith("to")
# print trie.startsWith("doing")
# print trie.startsWith("sd")
