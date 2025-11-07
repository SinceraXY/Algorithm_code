class Solution {
    public:
        string reverseStr(string s, int k) {
            for(int i=0;i<s.size();i+=(2*k))
            {
                //每隔2k个字符的前k个字符进行反转
                //剩余字符小于2k但大于或等于k个，则反转前k个字符
                if(i+k<=s.size())
                {
                    reverse(s.begin()+i,s.begin()+i+k);
                    continue;
                }
                //剩余字符少于k个，则将剩余字符全部反转。
                reverse(s.begin()+i,s.begin()+s.size());
            }
            return s;
        }
    };



class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2*k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};



class Solution {
public:
    void reverse(string& s,int start,int end)
    {
        int offset=(end-start+1)/2;
        for(int i=start,j=end;i<start+offset;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k)
        {
            //每隔2k个字符的前k个字符进行反转
            //剩余字符小于2k但大于或等于k个，则反转前k个字符
            if(i+k<=s.size())
            {
                reverse(s,i,i+k-1);
                continue;
            }
            //剩余字符少于k个，则将剩余字符全部反转。
            reverse(s,i,s.size()-1);
        }
        return s;
    }
};