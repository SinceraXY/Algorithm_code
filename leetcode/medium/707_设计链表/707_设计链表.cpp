class MyLinkedList {
    public:
        // 定义链表节点结构体
        struct LinkedNode{
            int val;
            LinkedNode* next;
            LinkedNode(int val):val(val),next(nullptr){}
        };
    
        MyLinkedList() {
            _dummyHead=new LinkedNode(0);   //这里定义的头结点是一个虚拟头结点，注意不是真正的链表头结点
            _size=0;
        }
        //注意index是从0开始的，第0个节点就是头结点
        int get(int index) {
            if(index>=_size||index<0)
            {
                return -1;
            }
            LinkedNode* cur=_dummyHead->next;
            while(index--)   //注意：如果--index会陷入死循环
            {
                cur=cur->next;
            }
            return cur->val;
        }
        
        void addAtHead(int val) {
            LinkedNode* newNode=new LinkedNode(val);
            newNode->next=_dummyHead->next;
            _dummyHead->next=newNode;
            _size++;
        }
        
        void addAtTail(int val) {
            LinkedNode* newNode=new LinkedNode(val);
            LinkedNode* cur=_dummyHead;
            while(cur->next!=nullptr)
            {
                cur=cur->next;
            }
            cur->next=newNode;
            _size++;
        }
        
        void addAtIndex(int index, int val) {
            if(index>_size)
            {
                return;
            }
            LinkedNode* newNode=new LinkedNode(val);
            LinkedNode* cur =_dummyHead;
            while(index--)
            {
                cur=cur->next;
            }
            newNode->next=cur->next;
            cur->next=newNode;
            _size++;
        }
        //注意index是从0开始的
        void deleteAtIndex(int index) {
            if(index>=_size||index<0)
            {
                return;
            }
            LinkedNode* cur=_dummyHead;
            while(index--)
            {
                cur=cur->next;
            }
            LinkedNode* tmp=cur->next;
            cur->next=cur->next->next;
            delete tmp;
            _size--;
        }
    private:
        int _size;
        LinkedNode* _dummyHead;
    };
    
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
*/