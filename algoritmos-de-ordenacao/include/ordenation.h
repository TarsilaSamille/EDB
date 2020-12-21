/**
 * @file ordenation.h
 * @author Társila Samille Santos da Silveira (tarsillasamile@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ORDENATION_H
#define ORDENATION_H

#include <iterator>

namespace oa {

    using value_type = int;
  /**
   * @brief insertion sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
    void insertionsort(value_type * array, int size);
  /**
   * @brief selectio sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
    void selectionsort(value_type * array, int size);
  /**
   * @brief bubble sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
    void bubblesort(value_type * array, int size );

  /**
   * @brief shell sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
   void shellsort(value_type * array, int size );
 
      /**
   * @brief quick sort / passa da estrutura padrão (value_type * array, int size ) 
   para a requerida pelo algoritimo (value_type * array, int low, int high)
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
   void quicksort(value_type * array, int size );

  /**
   * @brief quick sort
   * 
   * @param array array a ser ordenado
   * @param l posição menor
   * @param h posição maior
   */

   void quicksort(value_type * array, int low, int high);

      /**
   * @brief merge sort / passa da estrutura padrão (value_type * array, int size ) 
   para a requerida pelo algoritimo (value_type * array, int l, int r).
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
   void mergesort(value_type * array, int size );

  /**
   * @brief merge sort
   * 
   * @param array array a ser ordenado
   * @param l posição mais a esquerda
   * @param r posição mais a direita
   */
   void mergesort(value_type * array, int l, int r);
    
  /**
   * @brief mistura os arrays
   * 
   * @param array array a ser ordenado
   * @param l posição mais a esquerda
   * @param m metade
   * @param r posição mais a direita
   */
   void merge(value_type * array, int l, int m, int r);

      /**
   * @brief radix sort
   * 
   * @param array array a ser ordenado
   * @param size tamanho do array
   */
   void radixsort(value_type * array, int size );

}

#endif 
