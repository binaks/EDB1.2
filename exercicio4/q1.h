#ifndef Q1_H
#define Q1_H

int Max (Sequence<int> *seq); 
int rMax (Sequence<int> *seq, int count, int max, Node<int> *p); 
int iMax (Sequence<int> *seq); 
int Sum (Sequence<int> *seq); 
int rSum (Sequence<int> *seq, int count, int sum, Node<int> *p); 
int CountMin (Sequence<int> *seq, int n); 
int rCount (Sequence<int> *seq, int n, int count, int total, Node<int> *p); 

int Max (Sequence<int> *seq) {
	return rMax (seq, 0, (seq->getFirst())->getValue(), seq->getFirst());
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

int Sum (Sequence<int> *seq) {
	return rSum (seq, 0, (seq->getFirst())->getValue(), seq->getFirst());	
}

int rSum (Sequence<int> *seq, int count, int sum, Node<int> *p) {
	if (count == seq->getQuantity()) {
		return sum;
	}

	p = p->getNext();

	sum += p->getValue();

	return rSum (seq, ++count, sum, p);
}

int CountMin (Sequence<int> *seq, int n) {
	return rCount (seq, n, 1, 0, seq->getFirst());
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

#endif
