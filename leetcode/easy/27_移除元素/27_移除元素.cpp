//暴力
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int size=nums.size();
            for(int i=0;i<size;i++)
            {
                if(nums[i]==val)
                {
                    for(int j=i+1;j<size;j++)
                    {
                        nums[j-1]=nums[j];
                    }
                    i--;   //因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                    size--;   //此时数组的大小-1
                }
            }
            return size;
        }
    };

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)



//双指针法（快慢指针法）
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slowIndex=0;
            for(int fastIndex=0;fastIndex<nums.size();fastIndex++)
            {
                if(nums[fastIndex]!=val)
                {
                    nums[slowIndex++]=nums[fastIndex];
                }
            }
            return slowIndex;
        }
    };

// 时间复杂度：O(n)
// 空间复杂度：O(1)