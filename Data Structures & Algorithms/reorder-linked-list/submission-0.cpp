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
    void reorderList(ListNode* head) {
        //如果空链表或只有一个节点，无需重排。
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        //是为了slow走到中点
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //后半段起点
        ListNode* second = slow->next;
        slow->next=nullptr;//分成前后两段链表
        ListNode* prev = nullptr;
        //后半段倒序
        while(second){
            ListNode* nextNode=second->next;
            second->next=prev;
            prev=second;
            second=nextNode;
        }
        second=prev;//有这一步才真正反转完
        //连在一起
        ListNode* first = head;
        while(first && second){
            ListNode* nxt = first->next;
            ListNode* temp = second->next;
            first->next=second;
            first=nxt;
            second->next=nxt;
            second=temp;
        }
        return ;//void类型无需返回，这里已经直接修改了原链表
    }
};
