func replaceSpace(s string) string {
	count := 0 //统计空格的个数
	oldSize := len(s)

	//统计空格数量
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			count++
		}
	}

	//扩充字符串的大小
	newSize := oldSize + count*2
	result := make([]byte, newSize)

	//从后向前将空格替换为"%20"
	i := newSize - 1
	j := oldSize - 1

	for j < i {
		if s[j] != ' ' {
			result[i] = s[j]
		} else {
			result[i] = '0'
			result[i-1] = '2'
			result[i-2] = '%'
			i -= 2
		}
		i--
		j--
	}

	return string(result)
}