#滑动窗口
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = float('inf')
        sum_val = 0
        length = 0
        i = 0
        for j in range(len(nums)):
            sum_val += nums[j]
            while sum_val >= target:
                length = j - i + 1
                result = min(result, length)
                sum_val -= nums[i]
                i += 1   
        return 0 if result == float('inf') else result