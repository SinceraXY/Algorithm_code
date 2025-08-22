//双指针法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* temp;   //保存cur的下一个节点
            ListNode* cur=head;
            ListNode* pre=NULL;
            while(cur)
            {
                temp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=temp;
            }
            return pre;
        }
    };



//递归法
class Solution {
    public:
        ListNode* reverse(ListNode* pre,ListNode* cur){
            if(cur==NULL)
            {
                return pre;
            }
            ListNode* temp=cur->next;
            cur->next=pre;
            //和双指针法进行对比，其实就是做了如下两步
            //pre = cur;
            //cur = temp;
            return reverse(cur,temp);
        }
        ListNode* reverseList(ListNode* head) {
            //和双指针法初始化是一样的逻辑
            //ListNode* cur = head;
            //ListNode* pre = NULL;
            return reverse(NULL,head);
        }
    };