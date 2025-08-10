from typing import List


def two_sum(nums: List[int], target: int) -> List[int]:
    index_by_value = {}
    for i, x in enumerate(nums):
        complement = target - x
        if complement in index_by_value:
            return [index_by_value[complement], i]
        index_by_value[x] = i
    return []


if __name__ == "__main__":
    example_nums = [2, 7, 11, 15]
    example_target = 9
    print(two_sum(example_nums, example_target))  # Expected: [0, 1] 