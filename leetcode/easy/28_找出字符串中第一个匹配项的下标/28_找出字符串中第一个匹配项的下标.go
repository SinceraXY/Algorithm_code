func getNext(next []int, s string) {
	j := -1
	next[0] = j
	for i := 1; i < len(s); i++ { // 注意i从1开始
		for j >= 0 && s[i] != s[j+1] { // 前后缀不相同
			j = next[j]
		}
		if s[i] == s[j+1] { // 找到相同的前后缀
			j++
		}
		next[i] = j // 将j（前缀的长度）赋给next[i]
	}
}

func strStr(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}
	next := make([]int, len(needle))
	getNext(next, needle)
	j := -1 // 注意next数组里记录的起始位置为-1
	for i := 0; i < len(haystack); i++ { // i就从0开始
		for j >= 0 && haystack[i] != needle[j+1] { // 不匹配
			j = next[j] // j寻找之前匹配的位置
		}
		if haystack[i] == needle[j+1] { // 匹配，j和i同时向后移动
			j++
		}
		if j == len(needle)-1 { // 文本串s里出现了模式串t
			return i - len(needle) + 1
		}
	}
	return -1
}