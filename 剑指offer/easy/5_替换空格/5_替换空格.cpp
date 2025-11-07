class Solution {
public:
    string replaceSpace(string s)
    {
        int count = 0;     //统计空格的个数
        int OldSize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        //扩充字符串s的大小
        s.resize(s.size() + count * 2);
        int NewSize = s.size();
        //从后先前将空格替换为"%20"
        for (int i = NewSize - 1, j = OldSize - 1; j < i; i--, j--)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            } 
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};