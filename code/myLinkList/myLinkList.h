

class MyLinkedList {
    struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode(int v):val(v), next(nullptr){}
    };
    // 初始化链表
    MyLinkedList():_head(nullptr), _tail(nullptr), _size(0){}

    // 在外部添加元素
    void addTail(int val) {
        _size++;
        LinkNode* newNode = new LinkNode(val);
        if (_tail == nullptr || _head == nullptr){
            _tail = _head = newNode;
            return;
        }
        _tail->next = newNode;
        _tail = _tail->next;
        return;
    }

    // 在头部添加元素
    void addHead(int val) {
        _size++;
        LinkNode* newNode = new LinkNode(val);
        if(_head == nullptr){
            _head = _tail = newNode;
            return;
        }
        newNode->next = _head;
        _head = newNode;
    }

    // 在 index 位置之前插入数据，从0计数
    // 如果index 大于 size 则放弃插入
    // index = 0 则作为头节点
    // index = size 则作为尾节点插入
    void addAtIndex(int index, int val) {
        if (index > _size)return;
        _size++;
        if (index == 0) {
            addHead(val);
            return;
        }
        if (index == _size) {
            addTail(val);
            return;
        }
        LinkNode* dummyNode = new LinkNode(0);
        dummyNode->next = _head;
        LinkNode* curNode = dummyNode;
        
        while(index--)curNode = curNode->next;
        LinkNode* newNode = new LinkNode(val);
        
        newNode->next = curNode->next;
        curNode->next = newNode;
    }

    // 获取 index 位置的节点值
    int get(int index) {
        if (index > _size-1 || index < 0)return -1;
        LinkNode* curNode = _head;
        while(index--){
            curNode = curNode->next;
        }
        return curNode->val;
    }   

    // 删除链表指定位置的节点
    void deleteAtIndex(int index) {
        if (index > _size-1 || index < 0)return;
        _size--;
        if (index == 0){
            LinkNode* delNode = _head;
            _head = _head->next;
            delete delNode;
        }
        if (index == _size - 1) {
            LinkNode* delNode = _head;
            _head = _head->next;
            delete delNode;
        }
        LinkNode* dummyNode = new LinkNode(0);
        dummyNode->next = _head;
        LinkNode* curNode = dummyNode;
        while(index--){
            curNode = curNode->next;
        }
        LinkNode* delNode = curNode->next;
        curNode->next = delNode->next;
        delete delNode;
        _head = dummyNode->next;  
    }

    private:
        int _size;
        LinkNode* _head;
        LinkNode* _tail;

};