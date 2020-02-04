'''
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
'''

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        temp_tree = self.tree
        for sym in word :
            if sym not in temp_tree :
                temp_tree[sym] = {}
            temp_tree = temp_tree[sym]
        temp_tree["#"] = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        temp_tree = self.tree
        for sym in word :
            if sym not in temp_tree :
                return False
            temp_tree = temp_tree[sym]
        if "#" in temp_tree :
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        temp_tree = self.tree
        for sym in prefix :
            if sym not in temp_tree :
                return False
            temp_tree = temp_tree[sym]
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
