//哈希表法
func isAnagram(s string, t string) bool {
    record := [26]int{}
    for _, char := range s {
        record[char-'a']++
    }
    for _, char := range t {
        record[char-'a']--
    }
    for i := 0; i < 26; i++ {
        if record[i] != 0 {
            return false
        }
    }
    return true
}