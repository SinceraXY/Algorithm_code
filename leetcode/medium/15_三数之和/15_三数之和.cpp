//哈希法
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>>result;
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>0)    //排序之后如果第一个元素已经大于零，那么不可能凑成三元组
              {
                  continue;
              }
              if(i>0&&nums[i]==nums[i-1])    //三元组元素a去重
              {
                  continue;
              }
              unordered_set<int>set;
              for(int j=i+1;j<nums.size();j++)
              {
                  if(j>i+2
                      &&nums[j]==nums[j-1]
                      &&nums[j-1]==nums[j-2])   //三元组元素b去重
                      {
                          continue;
                      }
                      int c=0-(nums[i]+nums[j]);
                      if(set.find(c)!=set.end())
                      {
                          result.push_back({nums[i],nums[j],c});
                          set.erase(c);       //三元组元素c去重
                      }
                      else
                      {
                          set.insert(nums[j]);
                      }
              }
          }
          return result;
      }
  };



//双指针法
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> result;
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>0)   //排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
              {
                  return result;
              }
              //错误去重方法，将会漏掉-1,-1,2这种情况
              /*
              if(nums[i]==nums[i+1])
              {
                  continue;
              }
              */
              //正确去重方法
              if(i>0&&nums[i]==nums[i-1])
              {
                  continue;
              }
              int left=i+1;
              int right=nums.size()-1;
              while(right>left)
              {
                  //去重复逻辑如果放在这里，0，0，0的情况，可能直接导致right<=left了，从而漏掉了0,0,0这种三元组
                  /*
                  while (right > left && nums[right] == nums[right - 1]) right--;
                  while (right > left && nums[left] == nums[left + 1]) left++;
                  */
                  if(nums[i]+nums[left]+nums[right]>0)
                  {
                      right--;
                  }
                  else if(nums[i]+nums[left]+nums[right]<0)
                  {
                      left++;
                  }
                  else
                  {
                      result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                      //去重逻辑应该放在找到一个三元组之后
                      while(right>left&&nums[right]==nums[right-1])
                      {
                          right--;
                      }
                      while(right>left&&nums[left]==nums[left+1])
                      {
                          left++;
                      }
                      //找到答案时，双指针同时收缩
                      right--;
                      left++;
                  }
              }
          }
          return result;
      }
  };