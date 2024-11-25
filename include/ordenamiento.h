/**
 * Ordenamiento con diferentes complejidades:
 *
 *    1) O(n^2): Bubble Sort, (Insertion Sort)
 *    2) O(n log n): Quick Sort, (Merge Sort)
 *    3) O(d(n+k)): Radix Sort
 *
 *    Se ordena un arreglo de atletas segun el id
 *
 **/

#include "atleta.h"

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

int bubble_sort(atleta **arreglo, int n);

void quick_sort(atleta **arr, int low, int high, int *comp);

int radix_sort(atleta **arr, int n);



#endif //ORDENAMIENTO_H
