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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);//创建dummmy是为了以防删除的是头节点
        //dummy是节点对象而不是指针
        dummy.next=head;
        ListNode* slow=&dummy;
        ListNode* fast=&dummy;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
    return dummy.next;//这里是对象访问自己的成员，所以不是dummy->next
    }
};
