#include "search.h"

int leftBinarySearch (int *v, int first, int last, int x) {
	if (last < first) {
		return -1;
	} else {
		int k = (first + last) / 2;
		if (v[k] == x) {
			if (k != 0 && v[k - 1] == x) {
				return leftBinarySearch (v, first, k - 1, x);
			} else {
				return k;
			}
		} else if (v[k] > x) {
			return leftBinarySearch (v, first, k - 1, x);
		} else {
			return leftBinarySearch (v, k + 1, last, x);
		}
	}
}

int rightBinarySearch (int *v, int first, int last, int x) {
	if (last < first) {
		return -1;
	} else {
		int k = (first + last) / 2;
		if (v[k] == x) {
			if (k != last && v[k + 1] == x) {
				return rightBinarySearch (v, k + 1, last, x);
			} else {
				return k;
			}
		} else if (v[k] > x) {
			return rightBinarySearch (v, first, k - 1, x);
		} else {
			return rightBinarySearch (v, k + 1, last, x);
		}
	}
}