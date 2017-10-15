//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    // TO-DO
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

string LinkedList::get(int i)
{
    if( i < 1 || i > this->getQuantity())
    {
        std::cout << "Valor do índice de busca deve estar entre [1, quantity].\n";
        return "";
    }
	if( this->isEmpty() )
	{
		std::cout << "Não há elementos a serem retornados, pois lista está vazia.\n";
        return "";
	}
		
    int counter = 1;
    
    string result;
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( i == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;
}

int LinkedList::search(string s)
{
	if (quantity == 0) {
		return -1;
	} else {
		Node <string> *p = head;

		for (int i = 1; i <= quantity; i++) {
			p = p->getNext();

			if (p->getValue() == s) {
				return i;
			}
		}

		return -1;
	}
}

bool LinkedList::insertBegin(string s)
{
   	Node<string> *novo = new Node<string>(s);

	(head->getNext())->setPrevious(novo);
	novo->setNext(head->getNext()); 
	head->setNext(novo);
	novo->setPrevious(head);

	quantity++;

    return true;
}

bool LinkedList::insertEnd(string s)
{
	if (quantity == 0) {
		return insertBegin(s);
	} else {
		Node <string> *novo = new Node <string> (s);
		Node <string> *p = head;

		for (int i = 1; i <= quantity; i++) {
			p = p->getNext();
		}

		novo->setNext(tail);
		novo->setPrevious(p);
		p->setNext(novo);
		tail->setPrevious(novo);

		quantity++;
		return true;
	}
}

bool LinkedList::insert(int i, string s)
{
	if (quantity < i - 1) {
		return false;
	} else if (quantity == i - 1) {
		return insertEnd(s);
	} else if (i == 1) {
		return insertBegin(s);
	} else {
		Node <string> *p = head;
		Node <string> *novo = new Node <string>(s);

		for (int j = 1; j < i; j++) {
			p = p->getNext();
		}

		novo->setNext(p->getNext());
		novo->setPrevious(p);
		(p->getNext())->setPrevious(novo);
		p->setNext(novo);

		quantity++;
		return true;
	}
}

string LinkedList::removeEnd(void)
{
	if (quantity <= 1) {
		return removeBegin();
	} else {
		Node <string> *p = head;

		for (int i = 1; i < quantity; i++) {
			p = p->getNext();
		}
		
		Node <string> *q = p->getNext();		

		std::string value = q->getValue();
		p->setNext(tail);
		tail->setPrevious(p);
		
		delete q;

		quantity--;
		return value;
	}
}

string LinkedList::removeBegin(void)
{
    if (quantity == 0) {
		return "";
	} else {
		Node <string> *p = head->getNext();
		std::string value = p->getValue();

		head->setNext(p->getNext());
		(p->getNext())->setPrevious(head);

		delete p;

		quantity--;
		return value;
	}
}

string LinkedList::remove(int indice)
{
	if (quantity < indice) {
    	return "";
	} else if (quantity == indice) {
		return removeEnd();
	} else if (indice == 1) {
		return removeBegin();
	} else {
		Node <string> *p = head;

		for (int i = 1; i < indice; i++) {
			p->getNext();
		}

		Node <string> *q = p->getNext();
		std::string value = q->getValue();

		p->setNext(q->getNext());
		(q->getNext())->setPrevious(p);

		delete q;

		quantity--;
		return value;
	}
}

void LinkedList::print(void)
{
	for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
	if( this->head == NULL )
	{
		return HeadNull;
	}
	else if( this->head->getNext() == NULL )
	{
		return HeadNextNull;
	}
	else if( this->head->getNext()->getPrevious() != this->head )
	{
		return IncorrectLink;
	}
	else if( this->head->getPrevious() != NULL )
	{
		return HeadPrevious;
	}
	
	if( this->tail == NULL )
	{
		return TailNull;
	}
	else if( this->tail->getPrevious() == NULL )
	{
		return TailPreviousNull;
	}
	else if( this->tail->getPrevious()->getNext() != this->tail )
	{
		return IncorrectLink;
	}
	else if( this->tail->getNext() != NULL )
	{
		return TailNext;
	}
	
	if(this->isEmpty())
	{
		if( this->head->getNext() != this->tail )
		{
			return HeadTail;
		}
		
		if( this->head != this->tail->getPrevious() )
		{
			return HeadTail;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
		{
			if( i->getNext()->getPrevious() != i )
			{
				return IncorrectLink;
			}
			if( i->getPrevious()->getNext() != i )
			{
				return IncorrectLink;
			}
		}
	}
	
	return OK;
}
