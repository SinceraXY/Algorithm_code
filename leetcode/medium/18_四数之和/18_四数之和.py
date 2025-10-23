class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        if not nums or len(nums) < 4:
            return result
        nums.sort()
        length = len(nums)
        
        for k in range(length - 3):
            # 这种剪枝是错误的，这道题目target 是任意值
            # if nums[k] > target:
            #     return result
            
            # 去重
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            
            # 剪枝
            if nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3] > target:
                break
            
            if nums[k] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target:
                continue
            
            for i in range(k + 1, length - 2):
                # 正确去重方法
                if i > k + 1 and nums[i] == nums[i - 1]:
                    continue
                
                if nums[k] + nums[i] + nums[i + 1] + nums[i + 2] > target:
                    break
                
                if nums[k] + nums[i] + nums[length - 2] + nums[length - 1] < target:
                    continue
                
                left = i + 1
                right = length - 1
                
                while right > left:
                    current_sum = nums[k] + nums[i] + nums[left] + nums[right]
                    
                    if current_sum > target:
                        right -= 1
                    elif current_sum < target:
                        left += 1
                    else:
                        result.append([nums[k], nums[i], nums[left], nums[right]])
                        
                        # 去重逻辑应该放在成功找到一个四元组之后
                        while right > left and nums[right] == nums[right - 1]:
                            right -= 1
                        while right > left and nums[left] == nums[left + 1]:
                            left += 1
                        
                        # 找到答案时，双指针同时收缩
                        right -= 1
                        left += 1
        
        return result