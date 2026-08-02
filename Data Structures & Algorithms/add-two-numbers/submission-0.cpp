/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     //指针用->
 *     //下面的是对象，用. 
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,num=0;
        ListNode dummy(0);
        ListNode* curr = &dummy;//创建起始的辅助节点，后面每次计算都新建节点
        while(l1 || l2 || carry){
            int x = l1 != nullptr ? l1->val : 0;//如果l1不是nullptr那就x=l1->val 如果l1是nullptr那就x=0
            int y = l2 != nullptr ? l2->val : 0;
            int sum=x+y+carry;
            carry=sum/10;
            num=sum%10;
            curr->next = new ListNode(num);
            curr=curr->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
