class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for(char ch : s)
        {
            if(!stk.empty()&&stk.back()==ch)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};



// class Solution {
// public:
//     string removeDuplicates(string S) {
//         stack<char> st;
//         for(char s: S)
//         {
//             if(st.empty()||s!=st.top())
//             {
//                 st.push(s);
//             }
//             else
//             {
//                 st.pop();  //s与st.top()相等的情况
//             }
//         }
//         string result="";
//         while(!st.empty())   //将栈中元素放到result字符串汇总
//         {
//             result+=st.top();
//             st.pop();
//         }
//         reverse(result.begin(),result.end());    //此时字符串需要反转一下
//         return result;
//     }
// };