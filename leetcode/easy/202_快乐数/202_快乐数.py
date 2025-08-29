# 哈希表法
class Solution:
    def getSum(self, n: int) -> int:
        sum_val = 0
        while n:
            n, digit = divmod(n, 10)
            sum_val += digit ** 2
        return sum_val
    
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = self.getSum(n)
        return n == 1