/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//做出深拷贝，完全复制不同地址的新链表，内容和原链表一样
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        unordered_map<Node*, Node*> oldToNew;//<key 旧节点指针 ,value 新节点指针>
        //创建好所有节点
        Node* curr=head;
        while(curr){
            oldToNew[curr]=new Node(curr->val);
            //new Node(```)  创建节点并返回 Node* 指针
            //Node(```)      创建 Node 对象
            curr=curr->next;
        }
        //连接新节点的next和random
        curr=head;
        while(curr){
            oldToNew[curr]->next = curr->next == nullptr ? nullptr : oldToNew[curr->next];
                                //如果下一个节点为空 新节点next也为空 否则找到旧节点下一个节点对应的新节点
            oldToNew[curr]->random = curr->random == nullptr ? nullptr : oldToNew[curr->random];
            curr=curr->next;
        }
    return oldToNew[head];
    }
};
/*
假设原节点地址：

O0(3)：地址 1000
O1(7)：地址 2000
O2(4)：地址 3000
O3(5)：地址 4000

新节点地址：

N0(3)：地址 5000
N1(7)：地址 6000
N2(4)：地址 7000
N3(5)：地址 8000

第一遍创建节点后，oldToNew 可以理解为：

oldToNew[1000] = 5000
oldToNew[2000] = 6000
oldToNew[3000] = 7000
oldToNew[4000] = 8000
*/