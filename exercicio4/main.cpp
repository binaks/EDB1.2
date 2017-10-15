#include <iostream>
#include <string>
#include "Node.h"
#include "Sequence.h"

int iMax (Sequence<int> *seq); 
int rMax (Sequence<int> *seq, int count, int max, Node<int> *p); 
int Max (Sequence<int> *seq); 
int rSum (Sequence<int> *seq, int count, int sum, Node<int> *p); 
int Sum (Sequence<int> *seq); 
int rCount (Sequence<int> *seq, int n, int count, int total, Node<int> *p); 
int CountMin (Sequence<int> *seq, int n); 

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
