'''
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
'''

class Solution:
    def hammingWeight(self, n: int) -> int:
        '''
        内置函数 自动统计
        '''
        return bin(n).count('1')

    def hammingWeight(self, n: int) -> int:
        '''
        内置函数 手动统计
        '''
        count = 0
        for b in bin(n):
            if b == '1': count += 1
        return count

    def hammingWeight(self, n: int) -> int:
        '''
        余数统计
        '''
        count = 0
        while n:
            if (n & 1):
                count += 1
            n >>= 1
        return count

    def hammingWeight(self, n: int) -> int:
        '''
        位运算
        '''
        count = 0
        while n:
            n &= (n - 1)
            count += 1
        return count

