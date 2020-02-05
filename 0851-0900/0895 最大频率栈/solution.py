'''
实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。


提示：

对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。
 
'''
import collections

class FreqStack:

    def __init__(self):
        self.freq = collections.Counter()
        self.group = collections.defaultdict(list)
        self.maxfreq = 0

    def push(self, x: int) -> None:
        self.freq[x] += 1
        f = self.freq[x]
        if f > self.maxfreq :
            self.maxfreq = f
        self.group[f].append(x)

    def pop(self) -> int:
        x = self.group[self.maxfreq].pop()
        self.freq[x] -= 1
        if not self.group[self.maxfreq] :
            self.maxfreq -= 1
        return x

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
