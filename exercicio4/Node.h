#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
	T content;
	Node *next;
public:
	Node();
	Node(T value);

	Node<T>* getNext();
	void setNext(Node* n); 

	T getValue();
	void setValue(T value);
};

template <class T>
Node<T>::Node(T value) {
	content = value;
	next = nullptr;
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

#endif
