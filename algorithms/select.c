#include <stdio.h>

void selection(int *a, int first, int last) {
	if (last == first) return;

	for(int i = first; i <= last; i++) {
		int coco = first;
		
		if(v[coco] >= v[i]) {
			v[coco] = i;
		}
