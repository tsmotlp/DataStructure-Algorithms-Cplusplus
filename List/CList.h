#pragma once
typedef int ELEMTYPE;

//������
struct LNode {
	ELEMTYPE data;
	LNode* pNext, *pPrev;
};


class CList
{
private:
	int m_Length;	//������
	LNode* m_pHead, * m_pTail;	//ͷ����β���
public:
	CList();	//Ĭ�ϵĹ��캯��
	~CList();	//��������

	LNode* Next(LNode* curr);
	LNode* Previous(LNode* curr);
	
	//��ȡ������Ϣ
	int GetLength() const;	//��ȡ������
	LNode* GetHead() const;	//��ȡͷ���
	LNode* GetTail() const;	//��ȡβ���
	LNode* GetPosPointer(int pos);	//��ȡ��pos������ָ��

	//����Ԫ��
	void HeadInsert(ELEMTYPE data);	//����ͷ������һ��Ԫ��
	void TailInsert(ELEMTYPE data);	//����β������һ��Ԫ��
	void InsertAt(int pos, ELEMTYPE data);	//����λ��pos������һ��Ԫ��

	//ɾ��Ԫ��
	void RemoveAt(int pos);	//ɾ������λ��pos���Ľ��
	void RemoveAll();			//ɾ�������е�����Ԫ�أ�����ѿռ䣬������������

	//����
	int FindElemPosition(ELEMTYPE data);	//����ֵdata�������е�λ��
	LNode* FindElemPointer(ELEMTYPE data);	//����data�������еĽ��ָ��

	//�޸�Ԫ��
	void Modify(int pos, ELEMTYPE data);	//�޸�������λ��pos����Ԫ��ֵΪdata

	//����
	void PreOrderTraversal();		//ǰ�����
	void PostOrderTraversal();	//�������
};
