class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());        // 反转整个字符串
        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';
                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];
                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};



class Solution {
public:
    void reverse(string& s, int start, int end)   //反转字符串s中左闭右闭的区间
    {
        for(int i=start, j=end;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
    void removeExtraSpaces(string& s)      //使用双指针移除冗余空格
    {
        int slowIndex=0,fastIndex=0;
        while(s.size()>0&&fastIndex<s.size()&&s[fastIndex]==' ')    //去掉字符串前面的空格
        {
            fastIndex++;
        }
        for(;fastIndex<s.size();fastIndex++)
        {
            if(fastIndex-1>0&&s[fastIndex-1]==s[fastIndex]&&s[fastIndex]==' ')  //去掉字符串中间部分的冗余空格
            {
                continue;
            }
            else
            {
                s[slowIndex++]=s[fastIndex];
            }
        }
        if(slowIndex-1>0&&s[slowIndex-1]==' ')     //去掉字符串末尾的空格
        {
            s.resize(slowIndex-1);
        }
        else
        {
            s.resize(slowIndex);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);      //将字符串全部反转
        int start=0;       //反转的单词在字符串里起始位置
        int end=0;         //反转的单词在字符串里终止位置
        bool entry=false;  //标记枚举字符串的过程中是否已经进入了单词区间
        for(int i=0;i<s.size();i++)
        {
            if((!entry)||(i>0 && s[i]!=' ' && s[i-1]==' '))
            {
                start=i;      //确定单词起始位置
                entry=true;
            }
            //单词后面有空格的情况，空格就是分词符
            if(entry&&s[i]==' '&&s[i-1]!=' ')
            {
                end=i-1;      //确定单词终止位置
                entry=false;
                reverse(s,start,end);
            }
            //最后一个结尾单词之后没有空格的情况
            if(entry&&(i==(s.size()-1))&&s[i]!=' ')
            {
                end=i;
                entry=false;
                reverse(s,start,end);
            }
        }
        return s;
    }
};



//双端队列
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;

        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                // 将单词 push 到队列的头部
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));
        
        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};