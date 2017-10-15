//
//  Sequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"

Sequence::Sequence()
{
    first = NULL;
    this->quantity = 0;
}

Sequence::~Sequence()
{
    // TO - DO
}

/**
 Returns the i-th element in this sequence.
 */
std::string Sequence::get(int i)
{
    Node* curr = first;
    int counter = 1;
    
    while( curr!= NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    return curr->getValue();
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, std::string element)
{
    if (quantity == 0) {
		insertBegin(element);
		return;
	}

    Node *novo = new Node (element);

	Node *p = first;

	for (int j = 1; j < i - 1; j++) {
		p = p->getNext();
	}

	novo->setNext(p->getNext());
	p->setNext(novo);

	quantity++;
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(std::string element)
{
    Node *novo = new Node (element);

    novo->setNext(first);
    first = novo;

    quantity++;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(std::string element)
{
    if (quantity == 0) {
        insertBegin(element);
        return;
    }

    Node *novo = new Node (element);

    Node *p = first; 

    for (int i = 1; i < quantity; i++) {
        p = p->getNext();
    }

    novo->setNext(nullptr);
    p->setNext(novo);

    quantity++;
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
std::string Sequence::remove(int i)
{
	if (quantity < i) {
		return "";
	} else if (quantity == i) {
		return removeEnd();
	} else if (i == 1) {
		return removeBegin();
	} else {
		Node *p = first;

		for (int j = 1; j < i - 2; j++) {
			p = p->getNext();
		}

		Node *q = p->getNext();

		std::string value = q->getValue();
		p->setNext(q->getNext());

		delete q;

		quantity--;
		return value;
	}
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeBegin()
{
    if (quantity == 0) {
		return "";
	} else {
		Node *p = first->getNext();
		std::string value = first->getValue();
		delete first;
		first = p;

		quantity--;
		return value;
	}
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeEnd()
{
    if (quantity <= 1) {
		return removeBegin();
	} else {
		Node *p = first;
		
		for (int i = 1; i < quantity - 1; i++) {
			p = p->getNext();
		}

		std::string value = (p->getNext())->getValue();
		delete p->getNext();
		p->setNext(nullptr);

		quantity--;
    	return value;
	}
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
