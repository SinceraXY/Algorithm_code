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



class Solution {
public:
    static bool cmp(pair<int,int>& m,pair<int,int>& n) {
        return m.second>n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occurrences;
        for(auto& v : nums) {
            occurrences[v]++;
        }
        //pair的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);
        for(auto& [num,count] : occurrences) {
            if(q.size()==k){
                if(q.top().second<count) {
                    q.pop();
                    q.emplace(num, count);
                }
            }
            else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while(!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};