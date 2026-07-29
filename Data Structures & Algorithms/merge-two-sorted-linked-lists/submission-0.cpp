/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next; curr是这个 是指针
 *     ListNode() : val(0), next(nullptr) {} dummy是这个，是链表节点对象，而不是指针
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                curr->next=list1;
                list1=list1->next;
                curr=curr->next;//注意链表这里连接上的逻辑
            }else{
                curr->next=list2;
                list2=list2->next;
                curr=curr->next;
            }
        }
        if(list1!=nullptr){
            curr->next=list1;
        }else{
            curr->next=list2;
        }
    return dummy.next;
    }
};
