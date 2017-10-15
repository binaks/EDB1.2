#include <iostream>
#include <string>

template <class T>
class Node {
private:
	T content;
	Node *next;
public:
	Node();
	Node(T value);
	Node(T value, Node* n);

	Node* getNext();
	void setNext(Node* n); 

	T getValue();
	void setValue(T value);
};

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
Node<T>::Node(T value) {
	content = value;
	next = nullptr;
}

template <class T>
Node<T>::Node(T value, Node* n) {
	content = value;
	next = n;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <class T>
void Node<T>::setNext(Node* n) {
	next = n;
}

template <class T>
T Node<T>::getValue() {
	return content;
}

template <class T>
void Node<T>::setValue(T value) {
	content = value;
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

	for (int i = 1; i < quantity; i++) {
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
	newNode->setNext(nullptr);

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

int iMax (Sequence<int> *seq) {
	int max = (seq->getFirst())->getValue();

	Node <int> *p = seq->getFirst();

	for (int i = 1; i < seq->getQuantity(); i++) {
		p = p->getNext();

		if (p->getValue() > max) {
			max = p->getValue();
		}
	}

	return max;
}

int rMax (Sequence<int> *seq, int count, int max, Node<int> *p) {
	if (count == seq->getQuantity()) {
		return max;
	}

	p = p->getNext();

	if (p->getValue() > max) {
		max = p->getValue();
	}

	return rMax (seq, ++count, max, p);
}

int Max (Sequence<int> *seq) {
	return rMax (seq, 0, (seq->getFirst())->getValue(), seq->getFirst());
}

int rSum (Sequence<int> *seq, int count, int sum, Node<int> *p) {
	if (count == seq->getQuantity()) {
		return sum;
	}

	p = p->getNext();

	sum += p->getValue();

	return rSum (seq, ++count, sum, p);
}

int Sum (Sequence<int> *seq) {
	return rSum (seq, 0, (seq->getFirst())->getValue(), seq->getFirst());	
}

int rCount (Sequence<int> *seq, int n, int count, int total, Node<int> *p) {
	if (p->getValue() < n) {
		total++;
	}

	if (count == seq->getQuantity()) {
		return total;
	}

	return rCount (seq, n, ++count, total, p->getNext());
}

int CountMin (Sequence<int> *seq, int n) {
	return rCount (seq, n, 1, 0, seq->getFirst());
}

using namespace std;

int main () {
	Sequence <int> *seq = new Sequence <int>();

	seq->insertBegin(2);
	seq->insertBegin(5);
	seq->insertBegin(8);
	seq->insertBegin(3);

	cout << "First: " << (seq->getFirst())->getValue() << endl;

	int n;

	n = Max(seq);

	cout << "The greatest element of the list is " << n 
		 << ", on the position " << seq->search(n) << "." << endl;

	cout << "The sum of its elements is " << Sum(seq) << "." << endl;
	cout << "There are " << CountMin(seq, n) << " elements less than " << n << " in the sequence." << endl;

	

	return 0;
}
