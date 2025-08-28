# 哈希集合法
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result_set = set()
        nums_set = set(nums1)
        for num in nums2:
            if num in nums_set:
                result_set.add(num)
        return list(result_set)