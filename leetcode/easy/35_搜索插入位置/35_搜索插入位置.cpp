//暴力
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>=target)
                {
                    return i;
                }
            }
            return nums.size();
        }
    };



//二分法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;    // 定义target在左闭右闭的区间里，[left, right]
        while(left<=right)    // 当left==right，区间[left, right]依然有效
        {
            int middle=left+((right-left)>>1);   // 防止溢出 等同于(left + right)/2
            if(nums[middle]>target)
            {
                right=middle-1;
            }
            else if(nums[middle]<target)
            {
                left=middle+1;
            }
            else
            {
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right+1;
    }
};