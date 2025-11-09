func reverseWords(s string) string {
    // 将字符串转换为字节切片
    bytes := []byte(s)
    // 反转整个字符串
    reverse(bytes, 0, len(bytes)-1)
    n := len(bytes)
    idx := 0
    for start := 0; start < n; start++ {
        if bytes[start] != ' ' {
            // 填一个空白字符然后将idx移动到下一个单词的开头位置
            if idx != 0 {
                bytes[idx] = ' '
                idx++
            }
            // 循环遍历至单词的末尾
            end := start
            for end < n && bytes[end] != ' ' {
                bytes[idx] = bytes[end]
                idx++
                end++
            }
            // 反转整个单词
            reverse(bytes, idx-(end-start), idx-1)
            // 更新start，去找下一个单词
            start = end
        }
    }
    // 返回结果字符串
    return string(bytes[:idx])
}

// 辅助函数：反转字节切片的指定范围
func reverse(bytes []byte, left, right int) {
    for left < right {
        bytes[left], bytes[right] = bytes[right], bytes[left]
        left++
        right--
    }
}