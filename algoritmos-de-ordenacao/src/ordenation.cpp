/**
 * @file ordenation.cpp
 * @author Társila Samille Santos da Silveira (tarsillasamile@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>

#include "../include/ordenation.h"

namespace oa {
  /**
   * @brief Troca posição de elementos no array
   * 
   * @param p1 posição 1
   * @param p2 posição 2
   */
  void swap(int * p1, int * p2) {
    int temp = * p1;
    * p1 = * p2;
    * p2 = temp;
  }
  /**
   * @brief insertion sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void insertionsort(value_type * array, int size) {
    for (int i = 1; i < size; i++) {
      for (int j = i; j > 0; j--) {
        if (array[j - 1] > array[j]) {
          swap( & array[j], & array[j - 1]);
        }
      }
    }
  }
  /**
   * @brief selectio sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void selectionsort(value_type * array, int size) {
    int i, j, min_value;
    for (i = 0; i < size - 1; i++) {
      min_value = i;
      for (j = i + 1; j < size; j++)
        if (array[j] < array[min_value])
          min_value = j;
      swap( & array[min_value], & array[i]);
    }
  }
  /**
   * @brief bubble sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void bubblesort(value_type * array, int size) {
    bool changed = false;
    int ordained = 0;
    do {
      changed = false;
      ordained++;
      for (int i = 0; i < (size - ordained); i++) {
        if (array[i + 1] < array[i]) {
          changed = true;
          swap( & array[i], & array[i + 1]);
        }
      }
    } while (changed);
  }
  /**
   * @brief shell sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void shellsort(value_type * array, int size) {
    for (int intervalo = size / 2; intervalo > 0; intervalo /= 2) {
      for (int i = intervalo; i < size; i += 1) {
        int temp = array[i];
        int j;
        for (j = i; j >= intervalo && array[j - intervalo] > temp; j -= intervalo)
          array[j] = array[j - intervalo];
        array[j] = temp;
      }
    }
  }
  /**
   * @brief quick sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void quicksort(value_type * array, int size) {
    quicksort(array, 0, size - 1);
  }
  /**
   * @brief 
   * 
   * @param array  array a ser ordenado
   * @param low posição menor
   * @param high posição maior
   * @return int partição
   */
  int partition(value_type * array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
      if (array[j] < pivot) {
        i++;
        swap( & array[i], & array[j]);
      }
    }
    swap( & array[i + 1], & array[high]);
    return (i + 1);
  }

  /**
   * @brief quick sort
   * 
   * @param array array a ser ordenado
   * @param l posição menor
   * @param h posição maior
   */

  void quicksort(value_type * array, int l, int h) {
    int stack[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
      h = stack[top--];
      l = stack[top--];

      int p = partition(array, l, h);
      if (p - 1 > l) {
        stack[++top] = l;
        stack[++top] = p - 1;
      }
      if (p + 1 < h) {
        stack[++top] = p + 1;
        stack[++top] = h;
      }
    }
  }

  /**
   * @brief  merge sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void mergesort(value_type * array, int size) {
    mergesort(array, 0, size - 1);
  }
  /**
   * @brief merge sort
   * 
   * @param array array a ser ordenado
   * @param l posição mais a esquerda
   * @param r posição mais a direita
   */
  void mergesort(value_type * array, int l, int r) {
    if (l < r) {
      int m = l + (r - l) / 2;
      mergesort(array, l, m);
      mergesort(array, m + 1, r);
      merge(array, l, m, r);
    }
  }
  /**
   * @brief merge sort
   * 
   * @param array array a ser ordenado
   * @param l posição mais a esquerda
   * @param m metade
   * @param r posição mais a direita
   */
  void merge(value_type * array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], rigth[n2];

    for (i = 0; i < n1; i++)
      left[i] = array[l + i];
    for (j = 0; j < n2; j++)
      rigth[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
      if (left[i] <= rigth[j]) {
        array[k] = left[i];
        i++;
      } else {
        array[k] = rigth[j];
        j++;
      }
      k++;
    }
    while (i < n1) {
      array[k] = left[i];
      i++;
      k++;
    }
    while (j < n2) {
      array[k] = rigth[j];
      j++;
      k++;
    }
  }
  /**
   * @brief radix sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
  void radixsort(value_type * array, int size) {
    int i;
    value_type * b = new value_type[size];
    value_type maior = array[0];
    int exp = 1;
    for (i = 0; i < size; i++) {
      if (array[i] > maior)
        maior = array[i];
    }
    while (maior / exp > 0) {
      int count[10] = {
        0
      };
      for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;
      for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
      for (i = size - 1; i >= 0; i--)
        b[--count[(array[i] / exp) % 10]] = array[i];
      for (i = 0; i < size; i++)
        array[i] = b[i];
      exp *= 10;
    }
    delete[] b;
  }

}