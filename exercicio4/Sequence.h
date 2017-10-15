#ifndef SEQUENCE_H
#define SEQUENCE_H	

template <class T>
class Sequence {
private:
	Node<T> *first;
	int quantity;
public:
	Sequence();

	int search(T element);

	Node<T>* getFirst();
	int getQuantity();

	void insertEnd (T element);
	void insertBegin (T element);
	void insert (int index, T element);

	T removeEnd ();
	T removeBegin ();
	T remove (int index);
};

template <class T>
Node<T>::Node() {
	content = {};
	next = nullptr;
}


template <class T>
Sequence<T>::Sequence() {
	first = new Node<T>();
	first->setNext(nullptr);
	quantity = 0;
}

template <class T>
int Sequence<T>::search (T element) {
	if (quantity == 0) {
		return -1;
	}

	Node <T> *p = first;

	if (p->getValue() == element) {
		return 1;
	}

	for (int i = 1; i <= quantity; i++) {
		p = p->getNext();

		if (p->getValue() == element) {
			return i + 1;
		}
	}

	return -1;
}

template <class T>
void Sequence<T>::insertEnd (T element) {
	if (quantity == 0) {
		return insertBegin(element);
	}

	Node <T> *newNode = new Node <T> (element);
	Node <T> *p = first;

	for (int i = 1; i < quantity; i++) {
		p = p->getNext();
	}

	p->setNext(newNode);
	newNode->setNext(first);

	quantity++;
}

template <class T>
void Sequence<T>::insertBegin (T element) {
	Node <T> *newNode = new Node <T> (element);

	newNode->setNext(first);
	first = newNode;

	quantity++;
}

template <class T>
void Sequence<T>::insert (int index, T element) {
	if (index <= 1) {
		return insertBegin (element);
	} else if (index == quantity + 1) {
		return insertEnd (element);
	}

	Node <T> *newNode = new Node <T> (element);
	Node <T> *p = first;

	for (int i = 1; i < index - 1; i++) {
		p = p->getNext();
	}

	newNode->setNext(p->getNext());
	p->setNext(newNode);

	quantity++;
}

template <class T>
T Sequence<T>::removeEnd() {
	if (quantity <= 1) {
		return removeBegin();
	}

	Node <T> *p = first;

	for (int i = 1; i < quantity - 1; i++) {
		p = p->getNext();
	}

	T value = p->getValue();

	delete p->getNext();
	p->setNext(nullptr);
	
	quantity--;
	return value;
}

template <class T>
T Sequence<T>::removeBegin() {
	if (quantity == 0) {
		return {};
	}

	Node <T> *p = first;
	T value = p->getValue();
	first = first->getNext();

	delete p;

	quantity--;
	return value;
}

template <class T>
T Sequence<T>::remove(int index) {
	if (index > quantity) {
		return {};
	} else if (index == quantity) {
		return removeEnd();
	} else if (index == 1) {
		return removeBegin();
	}

	Node <T> *p = first;

	for (int i = 1; i < index - 2; i++) {
		p = p->getNext();
	}

	Node <T> *q = p->getNext();
	T value = q->getValue();

	p->setNext(q->getNext());
	
	delete q;
	
	quantity--;
	return value;
}

template <class T>
Node<T>* Sequence<T>::getFirst() {
	return first;
}

template <class T>
int Sequence<T>::getQuantity() {
	return quantity;
}

#endif
