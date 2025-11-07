class Solution:
    def replaceSpace(self, s: str) -> str:
        count = 0       #统计空格的个数
        old_size = len(s)
        
        #统计空格数量
        for c in s:
            if c == ' ':
                count += 1
        
        #扩充列表大小
        res = list(s)
        res.extend([' '] * (count * 2))
        new_size = len(res)
        
        #从后向前将空格替换为"%20"
        i = new_size - 1
        j = old_size - 1
        
        while j < i:
            if s[j] != ' ':
                res[i] = s[j]
            else:
                res[i] = '0'
                res[i - 1] = '2'
                res[i - 2] = '%'
                i -= 2
            i -= 1
            j -= 1
        
        return ''.join(res)