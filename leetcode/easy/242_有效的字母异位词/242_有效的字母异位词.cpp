//哈希表
class Solution {
    public:
        bool isAnagram(string s, string t) {
            int record[26]={0};
            for(int i=0;i<s.size();i++)
            {
                record[s[i]-'a']++;
            }
            for(int i=0;i<t.size();i++)
            {
                record[t[i]-'a']--;
            }
            for(int i=0;i<26;i++)
            {
                if(record[i]!=0)
                {
                    return false;
                }
            }
            return true;
        }
    };

// 时间复杂度：O(n)
// 空间复杂度：O(1)