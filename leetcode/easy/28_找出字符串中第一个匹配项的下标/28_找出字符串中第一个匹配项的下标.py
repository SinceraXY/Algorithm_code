class Solution:
    def getNext(self, next, s):
        j = -1
        next[0] = j
        for i in range(1, len(s)):  # 注意i从1开始
            while j >= 0 and s[i] != s[j + 1]:  # 前后缀不相同
                j = next[j]
            if s[i] == s[j + 1]:  # 找到相同的前后缀
                j += 1
            next[i] = j  # 将j（前缀的长度）赋给next[i]
    
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        next = [0] * len(needle)
        self.getNext(next, needle)
        j = -1  # 注意next数组里记录的起始位置为-1
        for i in range(len(haystack)):  # i就从0开始
            while j >= 0 and haystack[i] != needle[j + 1]:  # 不匹配
                j = next[j]  # j寻找之前匹配的位置
            if haystack[i] == needle[j + 1]:  # 匹配，j和i同时向后移动
                j += 1
            if j == len(needle) - 1:  # 文本串s里出现了模式串t
                return i - len(needle) + 1
        return -1