//暴力(超出时间限制)
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result=INT32_MAX;
            int sum=0;
            int length=0;
            for(int i=0;i<nums.size();i++)
            {
              sum=0;
              for(int j=i;j<nums.size();j++)
              {
                sum+=nums[j];
                if(sum>=target)
                {
                  length=j-i+1;
                  result=min(result,length);
                  break;
                }
              }
            }
            return result==INT32_MAX?0:result;
        }
    };

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)



//滑动窗口
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result=INT32_MAX;
            int sum=0;
            int length=0;
            int i=0;
            for(int j=0;j<nums.size();j++)
            {
              sum+=nums[j];
              while(sum>=target)
              {
                length=j-i+1;
                result=min(result,length);
                sum-=nums[i++];
              }
            }
            return result==INT32_MAX?0:result;
        }
    };

// 时间复杂度：O(n)
// 空间复杂度：O(1)