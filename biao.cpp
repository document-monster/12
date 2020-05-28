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
    linkedList() ;//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert(int value);//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove(int pos, int& value);
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList* head;
    int len;
};
linkedList::linkedList()
{
    len = 0;
    head = NULL;
}
//���ڴ˴��������г�Ա������ʵ��
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

//��Ա����print
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
    //��ʼ������
    if (!L1.initiate())
        return 0;

    cin >> n;//�������������ݸ���
    for (int i = 0; i < n; i++) //����n����������������
    {
        cin >> val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��";
    L1.print();//��ӡ����

    cin >> n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n, val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout << "Delete the data at position(" << n << "):" << val << endl;
        cout << "New Length��" << L1.Length() << endl;//���������
        cout << "data��";
        L1.print();//��ӡ����
    }

    return 0;
}