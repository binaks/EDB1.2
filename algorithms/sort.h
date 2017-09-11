#ifndef SORT_H
#define SORT_H

void quickSort (int *v, int left, int right);

inline void swap(int& x, int& y);

void selection_sort(int *v, int first, int last);

void selection_sort_it (int *v, int first, int last);

void insertion_sort (int *v, int first, int last);

void bubble_sort (int *v, int first, int last);

void merge_sort (int *v, int first, int last);

void merge (int *v, int first, int last, int m);

#endif
