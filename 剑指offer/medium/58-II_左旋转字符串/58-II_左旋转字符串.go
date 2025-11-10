func reverseLeftWords(s string, n int) string {
	runes := []rune(s)
	// 翻转前n个字符
	reverse(runes[:n])
	// 翻转剩余字符
	reverse(runes[n:])
	// 翻转整个字符串
	reverse(runes)
	return string(runes)
}

func reverse(arr []rune) {
	left, right := 0, len(arr)-1
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
}