#include <iostream>
#include <string>
#include "Node.h"
#include "Sequence.h"
#include "q1.h"

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
