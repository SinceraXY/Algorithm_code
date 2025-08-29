//哈希表法
class Solution {
    public:
        int getSum(int n)
        {
            int sum=0;
            while(n)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            return sum;
        }
        bool isHappy(int n) {
            unordered_set<int>set;
            while(1)
            {
                int sum=getSum(n);
                if(sum==1)
                {
                    return true;
                }
                if(set.find(sum)!=set.end())
                {
                    return false;
                }
                else
                {
                    set.insert(sum);
                }
                n=sum;
            }        
        }
    };