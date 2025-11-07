class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        n = len(s)
        for i in range(0, n, 2*k):
            s[i:min(i+k, n)] = reversed(s[i:min(i+k, n)])
        return ''.join(s)