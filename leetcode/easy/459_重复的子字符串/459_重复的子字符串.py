class Solution:
    def getNext(self, s: str) -> list:
        n = len(s)
        next_arr = [-1] * n
        j = -1
        for i in range(1, n):
            while j >= 0 and s[i] != s[j + 1]:
                j = next_arr[j]
            if s[i] == s[j + 1]:
                j += 1
            next_arr[i] = j
        return next_arr
    
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) == 0:
            return False
        next_arr = self.getNext(s)
        length = len(s)
        if next_arr[-1] != -1 and length % (length - (next_arr[-1] + 1)) == 0:
            return True
        return False