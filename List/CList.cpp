#include "CList.h"
#include<iostream>
using namespace std;
CList::CList()
{
	m_Length = 0;
	m_pHead = m_pTail = nullptr;
}

CList::~CList()
{
	RemoveAll();
}

LNode* CList::Next(LNode* curr) {
	return curr->pNext;
}

LNode* CList::Previous(LNode* curr) {
	return curr->pPrev;
}

int CList::GetLength() const {
	return m_Length;
}

LNode* CList::GetHead() const {
	return m_pHead;
}

LNode* CList::GetTail() const {
	return m_pTail;
}

void CList::HeadInsert(ELEMTYPE data) {
	LNode* pNewNode = new LNode;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead;
	pNewNode->pPrev = nullptr;
	if (m_pHead)	//如果头指针不为空
		m_pHead->pPrev = pNewNode;
	else
		m_pTail = pNewNode;
	m_pHead = pNewNode;
	m_Length++;
}

void CList::TailInsert(ELEMTYPE data) {
	LNode* pNewNode = new LNode;
	pNewNode->data = data;
	pNewNode->pPrev = m_pTail;
	pNewNode->pNext = nullptr;
	if (m_pTail)
		m_pTail->pNext = pNewNode;
	else
		m_pHead = pNewNode;
	m_pTail = pNewNode;
	m_Length++;
}

void CList::InsertAt(int pos, ELEMTYPE data) {
	if (pos == m_Length) {
		TailInsert(data);
	}
	else if(pos == 0){
		HeadInsert(data);
	}
	else {
		LNode* pInsert = GetPosPointer(pos);
		LNode* pNewNode = new LNode;
		pNewNode->data = data;
		pNewNode->pNext = pInsert;
		pNewNode->pPrev = pInsert->pPrev;
		pInsert->pPrev->pNext = pNewNode;
		pInsert->pPrev = pNewNode;
		m_Length++;
	}
}


LNode* CList::GetPosPointer(int pos){
	if (pos < 0 || pos > m_Length-1) {
		cout << "Position Error!" << endl;
		return nullptr;
	}
	else {
		LNode* tmp;
		if (pos < m_Length / 2) {	//在前半段
			tmp = GetHead();
			for (int i = 0; i < pos; i++) {
				tmp = Next(tmp);
			}
		}
		else {	//在后半段
			tmp = GetTail();
			for (int j = m_Length - 1; j > pos; j--) {
				tmp = Previous(tmp);
			}
		}
		return tmp;
	}
}

void CList::RemoveAt(int pos) {
	if (pos == 0) {	//如果删除的是头结点
		LNode* tmp = m_pHead;
		m_pHead->pNext->pPrev = nullptr;
		m_pHead = m_pHead->pNext;
		delete tmp;
		m_Length--;
	}
	else if (pos == m_Length - 1) {	//如果删除的是尾结点
		LNode* tmp = m_pTail;
		m_pTail->pPrev->pNext = nullptr;
		m_pTail = m_pTail->pPrev;
		delete tmp;
		m_Length--;
	}
	else {
		LNode* pRemove = GetPosPointer(pos);
		pRemove->pPrev->pNext = pRemove->pNext;
		pRemove->pNext->pPrev = pRemove->pPrev;
		delete pRemove;
		m_Length--;
	}
}


int CList::FindElemPosition(ELEMTYPE data) {
	LNode* pPre = GetHead();
	LNode* pPost = GetTail();
	int pre = 0;
	int post = m_Length - 1;
	while (pPre->data != data && pPost->data != data && pre < post) {
		pPre = Next(pPre);
		pPost = Previous(pPost);
		pre++;
		post--;
	}
	if (pPre->data == data)
		return pre;
	else if (pPost->data == data)
		return post;
	else {
		cout << data << " is not FOUND!" << endl;
		return -1;
	}
}

LNode* CList::FindElemPointer(ELEMTYPE data) {
	LNode* pPre = GetHead();
	LNode* pPost = GetTail();
	while (pPre->data != data && pPost->data != data && pPre != pPost && Next(pPre) != pPost) {
		pPre = Next(pPre);
		pPost = Previous(pPost);
	}
	if (pPre->data == data)
		return pPre;
	else if (pPost->data == data)
		return pPost;
	else {
		cout << data << " is not FOUND!" << endl;
		return nullptr;
	}

}

void CList::Modify(int pos, ELEMTYPE data){
	LNode* pModify = GetPosPointer(pos);
	pModify->data = data;
}

void CList::PreOrderTraversal() {
	LNode* tmp = GetHead();
	while (tmp) {
		cout << tmp->data << endl;
		tmp = tmp->pNext;
	}
}

void CList::PostOrderTraversal() {
	LNode* tmp = GetTail();
	while (tmp) {
		cout << tmp->data << endl;
		tmp = tmp->pPrev;
	}
}


void CList::RemoveAll() {
	LNode* p = m_pHead, *q;
	while (p) {
		q = p;
		p = p->pNext;
		delete q;
	}
	m_pHead = m_pTail = nullptr;
	m_Length = 0;
	
}