func fourSum(nums []int, target int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	length := len(nums)

	for k := 0; k < length-3; k++ {
		// 这种剪枝是错误的，这道题目target 是任意值
		// if nums[k] > target {
		//     return result
		// }

		// 去重
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}

		// 剪枝
		if nums[k]+nums[k+1]+nums[k+2]+nums[k+3] > target {
			break
		}

		if nums[k]+nums[length-3]+nums[length-2]+nums[length-1] < target {
			continue
		}

		for i := k + 1; i < length-2; i++ {
			// 正确去重方法
			if i > k+1 && nums[i] == nums[i-1] {
				continue
			}

			if nums[k]+nums[i]+nums[i+1]+nums[i+2] > target {
				break
			}

			if nums[k]+nums[i]+nums[length-2]+nums[length-1] < target {
				continue
			}

			left := i + 1
			right := length - 1

			for right > left {
				currentSum := nums[k] + nums[i] + nums[left] + nums[right]

				if currentSum > target {
					right--
				} else if currentSum < target {
					left++
				} else {
					result = append(result, []int{nums[k], nums[i], nums[left], nums[right]})

					// 去重逻辑应该放在成功找到一个四元组之后
					for right > left && nums[right] == nums[right-1] {
						right--
					}
					for right > left && nums[left] == nums[left+1] {
						left++
					}

					// 找到答案时，双指针同时收缩
					right--
					left++
				}
			}
		}
	}

	return result
}