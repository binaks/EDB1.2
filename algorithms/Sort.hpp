//
//  Sort.h
//  Aula-Ordenacao
//
//  Created by Eiji Adachi Medeiros Barbosa on 09/03/17.
//  Copyright © 2017 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

inline void swap(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

void selection_sort(int *v, int first, int last) {
	if (last == first) return;

	for (int i = first; i <= last; i++) {
		int least = first;

		if (v[least] >= v[i]) {
			least = i;
		}
	}

	swap (v[first], v[last]);

	return selection_sort(v, first + 1, last);
}

void sort(int *v, int size) {
	selection_sort (v, 0, size - 1);
}

#endif /* Sort_hpp */
