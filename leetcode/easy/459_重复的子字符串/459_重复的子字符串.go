func getNext(s string) []int {
	n := len(s)
	next := make([]int, n)
	for i := 0; i < n; i++ {
		next[i] = -1
	}
	j := -1
	for i := 1; i < n; i++ {
		for j >= 0 && s[i] != s[j+1] {
			j = next[j]
		}
		if s[i] == s[j+1] {
			j++
		}
		next[i] = j
	}
	return next
}

func repeatedSubstringPattern(s string) bool {
	if len(s) == 0 {
		return false
	}
	next := getNext(s)
	length := len(s)
	if next[length-1] != -1 && length%(length-(next[length-1]+1)) == 0 {
		return true
	}
	return false
}