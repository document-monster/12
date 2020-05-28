#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, * PList;

class linkedList
{
public:
    linkedList() ;//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert(int value);//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove(int pos, int& value);
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    LList* head;
    int len;
};
linkedList::linkedList()
{
    len = 0;
    head = NULL;
}
//请在此处补充所有成员函数的实现
linkedList::~linkedList()
{
    LList* p;
    p = head->next;
    while (p != NULL)
    {
        free(head);
        head = p;
        p = head->next;
    }
    free(head);
}
void linkedList::insert(int value)
{
    
    LList* q = new struct node;
    q->next = NULL;
    q->data = value;
    LList* p = head;
    int i;
    for (i = 0;;i++)
    {
        if (p->next == NULL)
        {
            p->next = q;
            break;
        }
        else
            p = p->next;
    }
    len++;
}
int linkedList::Length()
{
    return len;
}
bool linkedList::initiate()
{
    LList* p = new struct node;
   
    p->next = NULL;
    if (p == NULL)
        return false;
    else
    {
        head = p;
        return true;
    }
}
bool linkedList::remove(int pos,int &v)
{
    LList* p = head;
    LList* q = head->next;
    int i=0;
    if (pos > len)
        i = 2;
    if (pos <= 0)
        i = 1;
    switch (i)
    {
    case 2: {cout << "pos > len,failed" << endl;return false;}
    case 1: {cout << "pos <= 0,failed" << endl;return false;}
    default:break;
    }
    for (i = 0;;i++)
    {
        if (i == pos-1)
        {
            v = q->data;
            p->next = q->next;
            free(q);
            break;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    len--;
    return true;
}
bool linkedList::isEmpty()
{
    if (head->next == NULL)
        return true;
    else
        return false;
}

//成员函数print
void linkedList::print()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    linkedList L1;
    int n;
    int val;
    //初始化链表
    if (!L1.initiate())
        return 0;

    cin >> n;//输入链表中数据个数
    for (int i = 0; i < n; i++) //输入n个数，并插入链表
    {
        cin >> val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：";
    L1.print();//打印链表

    cin >> n;//输入需要删除的数据的位置
    if (L1.remove(n, val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout << "Delete the data at position(" << n << "):" << val << endl;
        cout << "New Length：" << L1.Length() << endl;//输出链表长度
        cout << "data：";
        L1.print();//打印链表
    }

    return 0;
}