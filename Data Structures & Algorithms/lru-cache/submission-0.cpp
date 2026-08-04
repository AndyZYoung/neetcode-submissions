class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v):key(k),value(v),prev(nullptr),next(nullptr){}//构造函数
    };
    int capacity;
    unordered_map<int,Node*> cache;//key value
    Node* head;
    Node* tail;
    void removeNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;
        before->next=after;
        after->prev=before;
    }
    void addToFront(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;//这里capacity是LRUCache对象自己的成员变量，它需要一直存在。
        //this->capacity就是当前对象的成员变量
        //把构造函数收到的容量，保存到当前缓存对象的成员变量中。
        head = new Node(0,0);
        //new Node(0,0)包含创建节点，然后把节点的地址赋值给head，所以这里的head是指针
        //如果是Node head(0,0)那head则是一个Node对象而不是指针
        tail = new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {//先查询key是否存在
        auto it=cache.find(key);//auto的类型是一个哈希表迭代器，unordered_map<int, Node*>::iterator
        if(it==cache.end())return -1;
        Node* node = it->second;//不能直接写Node* node = cache[key]; 因为对于unordered_map会创建新的键值对
        removeNode(node);
        addToFront(node);
        return node->value;
    }
    void put(int key, int value) {
        auto it=cache.find(key);
        if(it==cache.end()){
            //情况一 key不存在，需要创建新的节点
            Node* node=new Node(key,value);
            addToFront(node);
            cache[key] = node;//要创建这个键值对，后面才能查找,注意这里是node不是value
            //判断capacity，超过就删除tail前面那个节点，没超过就直接添加
            if(cache.size()>capacity){
                Node* lstNode=tail->prev;
                removeNode(lstNode);
                cache.erase(lstNode->key);// 从哈希表中删除
                delete lstNode;// 释放节点内存
            }
        }else{
            //情况二 key已经存在，不用创建新的节点
            Node* node = it->second;
            node->value=value;
            removeNode(node);
            addToFront(node);
            return ;
        }
    }
};