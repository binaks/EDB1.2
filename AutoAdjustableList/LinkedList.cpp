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
    Node<string>* n = this->head;
    
    while(n != this->tail)
    {
        Node<string>* toDestroy = n;
        
        n = n->getNext();
        
        delete toDestroy;
    }
    
    delete this->tail;
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
        throw invalid_argument("Valor do índice de busca deve estar entre [1, quantity].");
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
	Node <string> *p = head; 
	
	for (int i = 1; i <= quantity; i++) {
		p = p->getNext();

		if (p->getValue() == s) {
			return i;
		}
	}

    return -1;
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

bool LinkedList::insertBegin(string s)
{
	Node <string> *novo = new Node <string> (s);
	
	novo->setNext(head->getNext());
	novo->setPrevious(head);
	(head->getNext())->setPrevious(novo);
	head->setNext(novo);

	quantity++;
	return true;
}

bool LinkedList::insertEnd(string s)
{
	if (quantity < 1) {
		return insertBegin(s);
	} else {
		Node <string> *novo = new Node <string> (s);

		novo->setNext(tail);
		novo->setPrevious(tail->getPrevious());
		(tail->getPrevious())->setNext(novo);
		tail->setPrevious(novo);

		quantity++;
    	return true;
	}
}

bool LinkedList::insert(int i, string s)
{
	if (i > quantity + 1) {
    	return false;
	} else if (i == quantity + 1) {
		return insertEnd(s);
	} else if (i == 1) {
		return insertBegin(s);
	}

	Node <string> *novo = new Node <string> (s);
	Node <string> *p = head;

	for (int j = 1; j < i; j++) {
		p = p->getNext();
	}

	Node <string> *q = p->getNext();
	
	p->setNext(novo);
	novo->setPrevious(p);
	q->setPrevious(novo);
	novo->setNext(q);
	
	quantity++;
	return true;
}

bool LinkedList::insertOrdered(string s)
{
	if (quantity == 0) {
		return insertBegin(s);
	}

	Node <string> *novo = new Node <string> (s);
	Node <string> *p = head;

	std::string nValue = novo->getValue();
	std::string pValue = "";

	for (int i = 1; i <= quantity; i++) {
		p = p->getNext();

		pValue = p->getValue();

		if (pValue > nValue) {
			return insert(i, s);
		}
	}

    return insertEnd(s);
}

Node<string>* LinkedList::searchCF(string s)
{
	if (quantity == 0) {
		return nullptr;
	}

	Node <string> *p = head;
	Node <string> *q = head;

	for (int i = 1; i <= quantity; i++) {
		p = p->getNext();

		if (p->getValue() == s) {
			p->setCount(p->getCount() + 1);

			for (int j = 1; j <= i; j++) {
				q = q->getNext();

				if (p->getCount() >= q->getCount()) {
					(p->getNext())->setPrevious(p->getPrevious());
					(p->getPrevious())->setNext(p->getNext());
					p->setNext(q);
					p->setPrevious(q->getPrevious());
					(q->getPrevious())->setNext(p);
					q->setPrevious(p);

					return p; 
				}
			}
		}
	}
	
    return nullptr;
}

Node<string>* LinkedList::searchMF(string s)
{
	if (quantity == 0) {
		return nullptr;
	}

	Node <string> *p = head;

	for (int i = 1; i <= quantity; i++) {
		p = p->getNext();

		if (p->getValue() == s) {
			(p->getNext())->setPrevious(p->getPrevious());
			(p->getPrevious())->setNext(p->getNext());
			p->setPrevious(head);
			p->setNext(head->getNext());
			(head->getNext())->setPrevious(p);
			head->setNext(p);

			return p;
		}
	}

    return nullptr;
}

string LinkedList::removeEnd(void)
{
	if (quantity <= 1) {
		return removeBegin();
	}

	Node <string> *p = tail->getPrevious();
	Node <string> *q = p->getPrevious();

	std::string value = p->getValue();
	q->setNext(tail);
	tail->setPrevious(q);

	delete p;
	
	quantity --;
    return value;
}

string LinkedList::removeBegin(void)
{
	if (quantity == 0) {
		return "";
	} else {
		Node <string> *p = head->getNext();

		(p->getNext())->setPrevious(head);
		head->setNext(p->getNext());

		std::string value = p->getValue();

		delete p;

		quantity--;
		return value;
	}
}

string LinkedList::remove(int indice)
{
	if (indice > quantity) {
    	return "";
	} else if (indice == quantity) {
		return removeEnd();
	} else if (indice == 1) {
		return removeBegin();
	}

	Node <string> *p = head;

	for (int i = 1; i <= indice; i++) {
		p = p->getNext();
	}

	(p->getPrevious())->setNext(p->getNext());
	(p->getNext())->setPrevious(p->getPrevious());

	std::string value = p->getValue();

	quantity--;
	return value;
}
