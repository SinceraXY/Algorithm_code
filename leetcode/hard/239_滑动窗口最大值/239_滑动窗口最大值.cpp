//单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>q;
        for(int i=0;i<k;++i)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans={nums[q.front()]};
        for(int i=k;i<n;++i)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while(q.front()<=i-k)
            {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};



//单调队列
class Solution {
private:
    class MyQueue {  //单调队列（从大到小）
    public:
        deque<int> que;  //使用deque来实现单调队列
        //每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        //同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if(!que.empty()&&value==que.front())
            {
                que.pop_front();
            }
        }
        //如果新加入的值大于队列尾部(back)的值，就不断弹出队尾元素，
        //直到新值小于等于队尾元素为止。
        //这样可以保持队列从front到back单调递减。
        void push(int value)
        {
            while(!que.empty()&&value>que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        //查询当前队列里的最大值，直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      MyQueue que;
      vector<int> result;
      for(int i=0;i<k;i++)   //先将前k的元素放进队列
      {
        que.push(nums[i]);
      } 
      result.push_back(que.front());   //result记录前k的元素的最大值
      for(int i=k;i<nums.size();i++)
      {
        que.pop(nums[i-k]);   //滑动窗口移除最前面元素
        que.push(nums[i]);    //滑动窗口前加入最后面的元素
        result.push_back(que.front());   //记录对应的最大值
      }
      return result;
    }
};



//优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>q;
        for(int i =0;i<k;++i)
        {
            q.emplace(nums[i],i);
        }
        vector<int> ans = {q.top().first};
        for(int i=k;i<n;++i)
        {
            q.emplace(nums[i],i);
            while(q.top().second<=i-k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};