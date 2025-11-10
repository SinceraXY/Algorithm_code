class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s_list = list(s)
        # 翻转前n个字符
        s_list[:n] = reversed(s_list[:n])
        # 翻转剩余字符
        s_list[n:] = reversed(s_list[n:])
        # 翻转整个字符串
        s_list.reverse()
        return ''.join(s_list)