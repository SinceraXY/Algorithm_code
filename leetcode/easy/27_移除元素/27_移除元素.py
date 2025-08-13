#双指针法（快慢指针法）
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slowIndex = 0
        for fastIndex in range(len(nums)):
            if nums[fastIndex] != val:
                nums[slowIndex] = nums[fastIndex]
                slowIndex += 1
        return slowIndex