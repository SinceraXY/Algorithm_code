class Solution {
  public:
      int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
          unordered_map<int, int> umap;   //key:a+b的数值，value:a+b数值出现的次数
          for(int a:nums1)
          {
              for(int b:nums2)
              {
                  umap[a+b]++;
              }
          }
          int count=0;
          //在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
          for(int c:nums3)
          {
              for(int d:nums4)
              {
                  if(umap.find(0-(c+d))!=umap.end())
                  {
                      count+=umap[0-(c+d)];
                  }
              }
          }
          return count;
      }
  };