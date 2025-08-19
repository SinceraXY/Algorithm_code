class Solution {
  public:
      vector<vector<int>> generateMatrix(int n) {
          vector<vector<int>> res(n, vector<int>(n,0));
          int num=1;
          int up=0, down=n-1, left=0, right=n-1;
          while(num<=n*n)
          {
            for(int i=left;i<=right;i++)
            {
              res[up][i]=num++;
            }
            up++;
            for(int i=up;i<=down;i++)
            {
              res[i][right]=num++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
              res[down][i]=num++;
            }
            down--;
            for(int i=down;i>=up;i--)
            {
              res[i][left]=num++;
            }
            left++;
          }
          return res;
      }
  };