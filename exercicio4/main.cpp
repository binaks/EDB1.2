#include <iostream>
#include <string>
#include "Node.h"
#include "Sequence.h"
#include "q1.h"
#include "q2.h"

using namespace std;

int main () {
	Sequence <int> *seq = new Sequence <int>();

	seq->insertBegin(2);
	seq->insertBegin(5);
	seq->insertBegin(8);
	seq->insertBegin(3);
	seq->insertEnd(9);
	seq->insertEnd(7);
	seq->insert(2, 22);

	cout << "First: " << (seq->getFirst())->getValue() << endl;

	int n;

	n = Max(seq);

	cout << "The greatest element of the list is " << n 
		 << ", on the position " << seq->search(n) << "." << endl;

	cout << "The sum of its elements is " << Sum(seq) << "." << endl;
	cout << "There are " << CountMin(seq, n) << " elements less than " << n << " in the sequence." << endl;

	cout << "Your list: ";
	printList(seq);

	Invert(seq);

	cout << "The list was inverted." << endl;
	cout << "New list: ";
	printList(seq);

	return 0;
}
