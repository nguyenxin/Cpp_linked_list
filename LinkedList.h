#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <class T>
class Note{
	
	public:
		T data;
	 	Note *next;
};

template <class T>
class LinkedList
{
	public:
		LinkedList();
		void push_back(T element);
		T get(unsigned int index);
		void insert_at(size_t index, T element);
		void edit_at(size_t index, T element);
		void delete_at(size_t index);
		unsigned int len();
		~LinkedList();
	protected:
		Note<T> * _createNode(T element);
		Note<T> * _pHead;
		Note<T> * _pTail;
};

///////////////////////////////////////////////////////////////////////
template <class T>
LinkedList<T>::LinkedList(void){
	_pHead = _pTail = NULL;
}

template <class T>
Note<T>* LinkedList<T>::_createNode(T element)
{
	Note<T> *pNote = new Note<T>;
	if(pNote == NULL) 
		return NULL;
	pNote->data = element;
	pNote->next = NULL;
	return pNote;
}

template <class T>
void LinkedList<T>::push_back(T element){
	Note<T> *pNote = _createNode(element);
	if(_pHead == NULL)
		_pHead = _pTail = pNote;
	else{
		_pTail->next = pNote;
		_pTail = pNote;
	}
}
template <class T>
void LinkedList<T>::insert_at(size_t index, T element){
	Note<T> *pNote = _createNode(element);
	if(index == 0){
		if(_pHead == NULL){
			_pHead = _pTail = pNote;
		}else{
			pNote->next = _pHead;
			_pHead = pNote;
		}
	}else{
		int i = 1;
		Note<T> * pTemp;
		for(Note<T> *k = _pHead; k != NULL; k = k->next){
			if(i == index){
				pTemp = k->next;
				k->next = pNote;
				pNote->next = pTemp;
				return;
			}
			i++;
		}
	}
}

template <class T>
void LinkedList<T>::edit_at(size_t index, T element){

	int i = 0;
	for(Note<T> *k = _pHead; k != NULL; k = k->next){
		if(index == i){
			k->data = element;
		}
		i++;
	}

}

template <class T>
void LinkedList<T>::delete_at(size_t index){
	if (index ==0){
		Note<T> *pNote = _pHead;
		_pHead = _pHead->next;
		delete pNote;
	}else{
		int i = 1;
		Note<T> *pTemp;
		for(Note<T> *k = _pHead; k != NULL; k = k->next)
		{
			if(i == index){
				pTemp = k->next;
				k->next = pTemp->next;
				delete pTemp;
				return;
			}
			i++;
		}
	}
}

template <class T>
unsigned int LinkedList<T>::len(){
	unsigned int length = 0;
	for(Note<T> *k = _pHead; k != NULL; k = k->next){
		length++;
	}
	return length;
}

template <class T>
T LinkedList<T>::get(unsigned int index)
{
	
	T element;
	int i = 0;
	for (Note<T> *k = _pHead; k != NULL; k = k->next){
		if(i == index){
			element = k->data;
			return element;
		}
		i++;
	}
	return element;
}

template <class T>
LinkedList<T>::~LinkedList(){
	Note<T> *pNote;
	while(_pHead != NULL){
		pNote = _pHead;
		_pHead = _pHead->next;
		delete pNote;
	}
}

#endif
