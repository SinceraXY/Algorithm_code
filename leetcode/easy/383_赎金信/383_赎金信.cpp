//暴力枚举
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            for(int i=0;i<magazine.length();i++)
            {
                for(int j=0;j<ransomNote.length();j++)
                {
                    if(magazine[i]==ransomNote[j])    //在ransomNote中找到和magazine相同的字符
                    {
                        ransomNote.erase(ransomNote.begin()+j);    //ransomNote删除这个字符
                        break;
                    }
                }
            }
            if(ransomNote.length()==0)
            {
                return true;
            }
            return false;
        }
    };

// 时间复杂度: O(n^2)
// 空间复杂度：O(1)



//哈希
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if(ransomNote.size()>magazine.size())
            {
                return false;
            }
            vector<int> record(26);
            for(int i=0;i<magazine.length();i++)   //通过record数据记录magazine里各个字符出现次数
            {
                record[magazine[i]-'a']++;
            }
            for(int j=0;j<ransomNote.length();j++)
            {
                record[ransomNote[j]-'a']--;
                if(record[ransomNote[j]-'a']<0)    //如果小于零说明ransomNote里出现的字符，magazine里没有
                {
                    return false;
                }
            }
            return true;
        }
    };

// 时间复杂度: O(n)
// 空间复杂度：O(1)