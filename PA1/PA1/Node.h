#pragma once

#include "Data.h"
#include "List.h"


template <class T>
class Node
{
public:
	/*************************************************************
	* Function:	Node(T newData) : mpNext(nullptr)
	* Description: The function sets mpNext and sets mpData to the data
	* Input parameters: T newData
	* Returns: none
	* Preconditions: T newData
	* Postconditions: none
	*************************************************************/
	Node(T newData) : mpNext(nullptr)
	{
		mpData = newData;
	}
	/*************************************************************
	* Function:	T& getData();
	* Description: The function gets the data
	* Input parameters: none
	* Returns: mpData
	* Preconditions: none
	* Postconditions: returns mpData
	*************************************************************/
	T& getData();
	/*************************************************************
	* Function:	void setData(const T& newData);
	* Description: The function sets the data
	* Input parameters:const T& newData
	* Returns: none
	* Preconditions:const T& newData
	* Postconditions: none
	*************************************************************/
	void setData(const T& newData);
	/*************************************************************
	* Function:	Node<T>* getNextPtr() const;
	* Description: The function gets the Next ptr
	* Input parameters: none
	* Returns: mpNext
	* Preconditions: none
	* Postconditions: returns mpNext
	*************************************************************/
	Node<T>* getNextPtr() const;
	/*************************************************************
	* Function:	void setNextPtr(Node<T>* pNewNext);
	* Description: The function sets the Next ptr
	* Input parameters: Node<T>* pNewNext
	* Returns: none
	* Preconditions: Node<T>* pNewNext
	* Postconditions: none
	*************************************************************/
	void setNextPtr(Node<T>* pNewNext);


private:
	T mpData;
	Node<T>* mpNext;
};

template <class T>
T& Node<T>::getData()
{
	return mpData;
}

template <class T>
void Node<T>::setData(const T& newData)
{
	mpData = newData;
}

template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return mpNext;
}

template <class T>
void Node<T>::setNextPtr(Node<T>* pNewNext)
{
	mpNext = pNewNext;
}