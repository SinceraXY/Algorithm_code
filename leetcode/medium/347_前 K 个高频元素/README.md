# 347. 前 K 个高频元素

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/top-k-frequent-elements/description/
- **难度**：Medium
- **标签**：数组、哈希表、分治、桶排序、计数、快速选择、排序、堆（优先队列）

## 题目描述

给你一个整数数组 `nums` 和一个整数 `k`，请你返回其中出现频率前 `k` 高的元素。

你可以按任意顺序返回答案。

## 示例

**示例 1：**
```
输入：nums = [1,1,1,2,2,3], k = 2
输出：[1,2]
```

**示例 2：**
```
输入：nums = [1], k = 1
输出：[1]
```

## 解题思路

### 方法：哈希表 + 小顶堆（优先队列）

**核心思路：**
1. 先用哈希表统计每个元素出现的次数（频率）。
2. 使用一个大小为 `k` 的小顶堆（按“出现次数”排序）：
   - 依次把 `(元素, 频率)` 入堆。
   - 如果堆的大小超过 `k`，就弹出堆顶（频率最小的那个）。
3. 遍历完所有元素后，堆中剩下的就是频率最高的 `k` 个元素。

**为什么用小顶堆且大小为 k：**
- 小顶堆堆顶永远是当前“前 k 个元素”里频率最小的那个。
- 一旦有更高频率的元素出现，就可以把堆顶踢掉，始终把堆大小控制在 `k`，从而把堆操作从 `log N` 降到 `log k`，整体复杂度也从 `O(NlogN)` 降到 `O(Nlogk)`。

## 代码实现

### C++

```cpp
class Solution {
public:
    //小顶堆
    class mycomparison {
        public:
            bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs)
            {
                return lhs.second>rhs.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //要统计元素出现频率
        unordered_map<int, int> map;   //map<nums[i],对应出现的次数>
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        
        //对频率排序
        //定义一个小顶堆，大小为k
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;

        //用固定大小为k的小顶堆，扫面所有频率的数值
        for(unordered_map<int,int>::iterator it=map.begin();it!=map.end();it++)
        {
            pri_que.push(*it);
            if(pri_que.size()>k)  //如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
            {
                pri_que.pop();
            }
        }

        //找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for(int i=k-1;i>=0;i--)
        {
            result[i]=pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
```

### Go

```go
func topKFrequent(nums []int, k int) []int {
    occurrences := map[int]int{}
    for _, num := range nums {
        occurrences[num]++
    }
    h := &IHeap{}
    heap.Init(h)
    for key, value := range occurrences {
        heap.Push(h, [2]int{key, value})
        if h.Len()>k {
            heap.Pop(h)
        }
    }
    ret := make([]int, k)
    for i := 0;i<k;i++ {
        ret[k-i-1]=heap.Pop(h).([2]int)[0]
    }
    return ret
}

type IHeap [][2]int

func (h IHeap) Len() int             { return len(h) }
func (h IHeap) Less(i, j int) bool   { return h[i][1] < h[j][1] }
func (h IHeap) Swap(i, j int)        { h[i], h[j] = h[j], h[i] }

func (h *IHeap) Push(x interface{}) {
    *h = append(*h,x.([2]int))
}

func (h *IHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}
```

### Python

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        def sift_down(arr, root, k):
            """下沉log(k),如果新的根节点>子节点就一直下沉"""
            val = arr[root] #用类似插入排序的赋值交换
            while root<<1 < k:
                child = root << 1
                #选取左右孩子中小的与父节点交换
                if child|1 < k and arr[child|1][1] < arr[child][1]:
                    child |= 1
                #如果子节点<新节点,交换,如果已经有序break
                if arr[child][1] < val[1]:
                    arr[root] = arr[child]
                    root = child
                else:
                    break
            arr[root] = val

        def sift_up(arr, child):
            """上浮log(k),如果新加入的节点<父节点就一直上浮"""
            val = arr[child]
            while child>>1 > 0 and val[1] < arr[child>>1][1]:
                arr[child] = arr[child>>1]
                child >>= 1
            arr[child] = val

        stat = collections.Counter(nums)
        stat = list(stat.items())
        heap = [(0,0)]

        #构建规模为k+1的堆,新元素加入堆尾,上浮
        for i in range(k):
            heap.append(stat[i])
            sift_up(heap, len(heap)-1) 
        #维护规模为k+1的堆,如果新元素大于堆顶,入堆,并下沉
        for i in range(k, len(stat)):
            if stat[i][1] > heap[1][1]:
                heap[1] = stat[i]
                sift_down(heap, 1, k+1) 
        return [item[0] for item in heap[1:]]

```

## 复杂度分析

- **时间复杂度**：O(Nlogk)，其中 N 为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，共需 O(N) 的时间。随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 O(logk) 的时间，共需 O(Nlogk) 的时间。二者之和为 O(Nlogk)。
- **空间复杂度**：O(N)。哈希表的大小为 O(N)，而堆的大小为 O(k)，共计为 O(N)。

## 关键点

1. 堆里存 `(元素, 频率)`，并按“频率”构造小顶堆。
2. 始终把堆大小控制为 `k`，这样堆操作复杂度是 `log k` 而不是 `log N`。
3. 从小顶堆取元素时，弹出顺序是从小到大，若要求保持与示例一致可按需要调整输出顺序（本题不要求顺序）。