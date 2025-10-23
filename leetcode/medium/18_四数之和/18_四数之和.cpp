class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int length=nums.size();
        for(int k=0;k<length-3;k++)
        {
            //这种剪枝是错误的，这道题目target 是任意值 
            //if (nums[k] > target) {
            //    return result;
            //}
            //去重
            if(k>0&&nums[k]==nums[k-1])
            {
                continue;
            }
            //剪枝
            if ((long) nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3] > target)
            {
                break;
            }
            if ((long) nums[k] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
            {
                continue;
            }
            for(int i=k+1;i<length-2;i++)
            {
                //正确去重方法
                if(i>k+1&&nums[i]==nums[i-1])
                {
                    continue;
                }
                if ((long) nums[k] + nums[i] + nums[i + 1] + nums[i + 2] > target)
                {
                    break;
                }
                if ((long) nums[k] + nums[i] + nums[length - 2] + nums[length - 1] < target)
                {
                    continue;
                }
                int left=i+1;
                int right=length-1;
                while(right>left)
                {
                    if((long)nums[k]+nums[i]+nums[left]+nums[right]>target)
                    {
                        right--;
                    }
                    else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                        //去重逻辑应该放在成功找到一个四元组之后
                        while(right>left&&nums[right]==nums[right-1])right--;
                        while(right>left&&nums[left]==nums[left+1])left++;
                        //找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};