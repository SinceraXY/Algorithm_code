class Solution {
public:
    void getNext(int* next,const string& s)
    {
        int j=-1;
        next[0]=j;
        for(int i=1;i<s.size();i++)      //注意i从1开始
        {
            while(j>=0&&s[i]!=s[j+1])     //前后缀不相同
            {
                j=next[j];
            }
            if(s[i]==s[j+1])        //找到相同的前后缀
            {
                j++;
            }
            next[i]=j;        //将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
        {
            return 0;
        }
        int next[needle.size()];
        getNext(next,needle);
        int j=-1;     //注意next数组里记录的起始位置为-1
        for(int i=0;i<haystack.size();i++)     //i就从0开始
        {
            while(j>=0&&haystack[i]!=needle[j+1])    //不匹配
            {
                j=next[j];       //j寻找之前匹配的位置
            }
            if(haystack[i]==needle[j+1])    //匹配，j和i同时向后移动
            {
                j++;
            }
            if(j==(needle.size()-1))       //文本串s里出现了模式串t
            {
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
};