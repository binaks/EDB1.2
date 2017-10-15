#ifndef Q2_H
#define Q2_H

#include <iostream>

using namespace std;

void Invert (Sequence<int> *seq);
void rInvert (Sequence<int> *seq, int count, Node<int> *p); 

void printList (Sequence<int> *seq);

void printList (Sequence<int> *seq) {
	cout << "{";

	Node<int> *p = seq->getFirst();

	for (int i = 1; i <= seq->getQuantity(); i++) {
		cout << p->getValue();
		p = p->getNext();

		if (i != seq->getQuantity()) {
			cout << ", ";
		} else {
			cout << "}" << endl;
		}
	}
}

void Invert (Sequence<int> *seq) {
	return rInvert (seq, 0, seq->getFirst());
}

void rInvert (Sequence<int> *seq, int count, Node<int> *p) {
	if (count == seq->getQuantity()) {
		return;
	}

	seq->insert(seq->getQuantity() + 1 - count, p->getValue());
	seq->removeBegin();

	return rInvert (seq, ++count, seq->getFirst());
}

#endif
