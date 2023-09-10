#pragma once

#include "Data.h"
#include "Node.h"


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
template <class T>
class List
{
public:
	/*************************************************************
	* Function:	List() : mpHead(nullptr) {};
	* Description: The function sets mpHead to null
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	List() : mpHead(nullptr) {};

	~List()
	{
		// Traverse the list and delete all nodes
		while (mpHead != nullptr)
		{
			Node<T>* pTemp = mpHead;
			mpHead = mpHead->getNextPtr();
			delete pTemp; // Delete the node
		}
	}
	/*************************************************************
	* Function:	Node<T>* getHeadPtr() const;
	* Description: The function gets the head ptr
	* Input parameters: none
	* Returns: mpHead
	* Preconditions: none
	* Postconditions: returns mpHead
	*************************************************************/
	Node<T>* getHeadPtr() const;
	/*************************************************************
	* Function: void insert(T data);
	* Description: The function inserts a node into the list
	* Input parameters: T data
	* Returns: none
	* Preconditions: T data
	* Postconditions: none
	*************************************************************/
	void insertAtFront(T data);
	/*************************************************************
	* Function:	void setHeadPtr(Node<T>* pNewNext);
	* Description: The function sets the head ptr
	* Input parameters: Node<T>* pNewNext
	* Returns: none
	* Preconditions: Node<T>* pNewNext
	* Postconditions: none
	*************************************************************/
	void setHeadPtr(Node<T>* pNewNext);
	/*************************************************************
	* Function: void updateA(T& data);
	* Description: The function updates the absent member by 1
	* Input parameters: T& data
	* Returns: none
	* Preconditions: T& data
	* Postconditions: none
	*************************************************************/
	void removeNode(Node<T>* newnode);
private:
	Node<T>* mpHead;
};

template <class T>
Node<T>* List<T>::getHeadPtr() const
{
	return mpHead;
}

template <class T>
void List<T>::setHeadPtr(Node<T>* pNewHead)
{
	mpHead = pNewHead;
}

template<class T>
void List<T>::insertAtFront(T data)
{
	Node<T>* pMem = new Node<T>(data);
	if (mpHead == nullptr)
	{
		mpHead = pMem;
	}
	else
	{
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}
}

template <class T>
void List<T>::removeNode(Node<T>* newnode)
{
	Node<T>* pTemp = newnode;
	Node<T>* pPre = nullptr;
	if (pTemp == mpHead)
	{
		pTemp = mpHead;
		mpHead = mpHead->getNextPtr();
	}
	delete pTemp;

}
