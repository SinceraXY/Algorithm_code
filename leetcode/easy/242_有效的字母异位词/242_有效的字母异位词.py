# 哈希表法
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = [0] * 26
        for char in s:
            record[ord(char) - ord('a')] += 1
        for char in t:
            record[ord(char) - ord('a')] -= 1
        for count in record:
            if count != 0:
                return False
        return True



#使用Counter
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)