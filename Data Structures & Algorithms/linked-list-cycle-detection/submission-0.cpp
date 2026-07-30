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
    bool hasCycle(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=nullptr && fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;//需要保证fast->next->next也是可以访问的
            if(slow==fast){
                return true;
            }
        }
    return false;
    }
};//快慢指针占用空间更少
/*用unordered_set （哈希表）来记录节点是否被访问过
unordered_set<ListNode*> visited;
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;

        while (curr != nullptr) {
            // 如果当前节点以前访问过，说明有环
            if (visited.count(curr) > 0) {
                return true;
            }

            // 记录当前节点
            visited.insert(curr);

            // 移动到下一个节点
            curr = curr->next;
        }

        // 能走到 nullptr，说明没有环
        return false;
    }
};
*/