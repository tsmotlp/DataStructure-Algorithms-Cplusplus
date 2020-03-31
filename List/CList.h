#pragma once
typedef int ELEMTYPE;

//定义结点
struct LNode {
	ELEMTYPE data;
	LNode* pNext, *pPrev;
};


class CList
{
private:
	int m_Length;	//链表长度
	LNode* m_pHead, * m_pTail;	//头结点和尾结点
public:
	CList();	//默认的构造函数
	~CList();	//析构函数

	LNode* Next(LNode* curr);
	LNode* Previous(LNode* curr);
	
	//获取链表信息
	int GetLength() const;	//获取链表长度
	LNode* GetHead() const;	//获取头结点
	LNode* GetTail() const;	//获取尾结点
	LNode* GetPosPointer(int pos);	//获取第pos个结点的指针

	//增加元素
	void HeadInsert(ELEMTYPE data);	//链表头部插入一个元素
	void TailInsert(ELEMTYPE data);	//链表尾部插入一个元素
	void InsertAt(int pos, ELEMTYPE data);	//链表位置pos处插入一个元素

	//删除元素
	void RemoveAt(int pos);	//删除链表位置pos处的结点
	void RemoveAll();			//删除链表中的所有元素，清除堆空间，析构函数调用

	//查找
	int FindElemPosition(ELEMTYPE data);	//查找值data在链表中的位置
	LNode* FindElemPointer(ELEMTYPE data);	//查找data在链表中的结点指针

	//修改元素
	void Modify(int pos, ELEMTYPE data);	//修改链表中位置pos处的元素值为data

	//遍历
	void PreOrderTraversal();		//前向遍历
	void PostOrderTraversal();	//后向遍历
};
