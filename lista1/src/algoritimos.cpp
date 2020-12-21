/*
 */

#include <iostream>

#include <algorithm>

#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

#include "../include/algoritimos.h"

namespace sa {

    /*!
       * 1. Local minimum in an array. Write a function that, given an array a[] of n distinct
          integers, finds and returns the location a local minimum. A local minimum in an array
          is an element a[i] such that both a[i] <  a[i-1] and a[i] < a[i+1] (assuming
          the neighbor entry is inside the array). Note that an element that does not have one
          (or both) of its two neighbors can still be a local minimum. Your program should use
          ∼ 2 lg(n) compares in the worst case.
          Hint: Examine the middle value a[n/2] and its two neighbors a[n/2 - 1] and
          a[n/2 + 1] . If a[n/2] is a local minimum, stop; otherwise search in the half with
          the smaller neighbor
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       */
    int * local_minimum(int * first, int * last) {
        for (int i = 1; i < ((last - first)) - 1; i++)
            if ( * (first + i) < * (first + i + 1) && * (first + i - 1) > * (first + i))
                return first + i;
        return last;
    }

    /*!
       * 2. Local minimum in a matrix. Given an n-by-n matrix a[][] of n
          2 distinct integers,
          design an algorithm that runs in time proportional to n log(n) to find a local minimum: a
          pair of indices i and j such that a[i][j] < a[i+1][j] , a[i][j] < a[i][j+1] ,
          a[i][j] < a[i-1][j] , and a[i][j] < a[i][j-1] (assuming a[i][j] has both
          neighbors).
          Hint: Find the minimum entry in row n/2, say a[n/2][j] . If it’s a local minimum, 
          then return it. Otherwise, check it’s two vertical neighbors a[n/2-1][j] and
          a[n/2+1][j] . Recur in the half with the smaller neighbor.
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       */
    std::tuple < int, int > local_minimum_matriz(int ** A, int cols) {
        for (int i = 1; i < cols; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (A[i][j] < A[i][j + 1] && A[i][j] < A[i][j - 1])
                    if (A[i][j] < A[i - 1][j] && A[i][j] < A[i + 1][j])
                        return {
                            i,
                            j
                        };
            }
        }

        return {
            cols,
            cols
        };
    }

    /*!
       * 3, Bitonic search. An array is bitonic if it is comprised of an increasing sequence of integers
          followed immediately by a decreasing sequence of integers. Write a function that, given
          a bitonic array of n distinct int values, determines whether a given integer is in the
          array. Your program should use ∼ 3 log(n) compares in the worst case.
          Hint: Use a version of binary search to find the maximum (in ∼ 1 lg(n) compares); then
          use binary search to search in each piece (in ∼ 1 lg(n) compares per piece).
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */
    int * bitonic_search(int * first, int * last, int value) {
        int i;
        int * max;

        for (i = 0; i < ((last - first)) - 1; i++)
            if ( * (first + i) < * (first + i + 1))
                max = first + i + 1;

        if ( * (max) != value) {
            int * crescent = bsearch(first, max, value);
            if ( * (crescent) == value)
                return crescent;

            int first_copy[(last - max)];
            int * pfc = first_copy;
            std::copy(max + 1, last, pfc);

            std::sort(pfc, pfc + (last - max) - 1);

            int * decrescent = bsearch(pfc, pfc + (last - first), value);

            int dist_to_final = decrescent - pfc;

            if ( * (last - dist_to_final - 1) == value)
                return last - dist_to_final - 1;

        }
        if ( * (max) == value)
            return max;
        return last;
    }
    /*!
    4. Binary search with duplicates. Modify binary search function so that it always returns
    the smallest index of a key of an item matching the search key
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    int * binary_search_with_diplicates(int * first, int * last, int value) {
        return lbound(first, last, value);
    }

    /*!
    5. Hot or cold. Your goal is the guess a secret integer between 1 and N. You repeatedly
    guess integers between 1 and N. After each guess you learn if it equals the secret integer
    (and the game stops); otherwise (starting with the second guess), you learn if the guess
    is hotter (closer to) or colder (farther from) the secret number than your previous guess.
    Design an algorithm that finds the secret number in ∼ 2 lg(N) guesses.
    In terms of design, first create the main program that reads from the command line a
    value for N. Then generate a random secret integer ∈ [1, N]. After that, asks the user
    for guesses, providing the corresponding clues (hot or cold). In the example below, the
    user has defined N = 50.

     */
    void hot_or_cold(int n) {

    int *A1 = new int [n];
    int  i ;
    for ( i = 0; i < n; ++i) {
        A1[i] = i;
    }
    i =0;
    int numeroSecreto, acho1, acho2,dif2 , dif1;

        numeroSecreto = rand() % n + 1;
        acho1 = rand() % n + 1;

        std::cout <<numeroSecreto <<">>> Guess the number:" << acho1 << std::endl;
        
        acho2 = rand() % n+ 1;
        if(numeroSecreto!=acho1)
            std::cout << ">>> Nop, try again:" << acho2 << std::endl;

      do {
        dif2 = acho2 - numeroSecreto < 0 ? (acho2 - numeroSecreto )* -1 : acho2 - numeroSecreto ;
        dif1 = acho1 - numeroSecreto < 0 ? (acho1 - numeroSecreto )* -1 : acho1 - numeroSecreto ;

        if (dif2 <=dif1){
                    n= acho1;
          acho1 = acho2;
          acho2 = A1[i+((n-i)/2 +(n-i)%2)];
            std::cout << numeroSecreto<< ">>> Nop, it’s hot though,  try again:" << acho2 << std::endl;

        }  
        else if (dif2 > dif1){
             i= acho1;
          acho1 = acho2;
          acho2 = A1[i+((n-i)/2  - (n-i)%2)];
            std::cout << ">>> Nop, it’s getting cold,  try again: "<< acho2 << std::endl ;

        }

      } while (numeroSecreto!=acho2 && numeroSecreto!=acho1 );
            std::cout << ">>>Congratulations:" << acho2 << std::endl;

    }

    /*!
    6. Floor and ceiling. Given a set of comparable elements, the ceiling of x is the smallest
    element in the set greater than or equal to x, and the floor is the largest element less
    than or equal to x. Suppose you have an array of N items in ascending order. Write
    an O(log N) algorithm (function) that receives an array, finds and returns the floor and
    ceiling of x.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     */
    std::tuple < int * , int * > floor_ceiling(int * first, int * last, int value) {

        int * floor = ubound(first, last, value);
        int * ceiling = lbound(first, last, value);

        while (floor == last)
            floor = ubound(first, last, value--);

        return {
            floor,
            ceiling
        };

    }

    /*!
          7. Identity. Given an array a of N distinct integers (positive or negative) in ascending order.
          Write a function that receives an array and finds an index i such that a[i] = i if
          such an index exists.
          Hint: binary search.
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       */

    int * identity(int * first, int * last) {
        int * result = bsearch_identity(first, last);
        if ( * (result) != (result - first))
            return last;
        return result;
    }

    int * bsearch_identity(int * first, int * last) {
        if ( * (last - 1) >= * (first)) {
            int index = ((last - first)) / 2;
            int * mid = (first + index);

            if ( * (mid) == (mid - first))
                return mid;
            if ( * (mid) > (mid - first) && mid != first)
                return bsearch_identity(first, mid - 1);
            if (mid != last)
                return bsearch_identity(mid + 1, last);
        }
        return last;
    }
    /*!
           
           8.    Find a duplicate. Given an array of N elements in which each element is an integer
           between 1 and N, write function to determine if there are any duplicates. Your algorithm
           should run in linear time and use O(1) extra space.
           Hint: you may destroy the array
        * \param first Pointer to the begining of the data range.
        * \param last Pointer just past the last element of the data range.
        */
    /*!
14. Find the duplicate. Given a sorted array of N + 2 integers between 0 and N with
        exactly one duplicate, design a logarithmic time algorithm to find the duplicate.
        Hint: binary search.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     */
    int * find_duplicate(int * first, int * last) {
        if ( * (last - 1) >= * (first)) {
            int index = ((last - first)) / 2;
            int * mid = (first + index);
            if ( * (mid) == * (mid - 1))
                return mid;
            if ( * (mid) == * (mid + 1))
                return mid + 1;
            if ( * (mid) <= (mid - first) && mid != first)
                return find_duplicate(first, mid - 1);
            if ( * (mid) < * (mid + 1) && mid != last)
                return find_duplicate(mid + 1, last);
        }
        return last;
    }

    /*!
          9. Search in a sorted, rotated array. Given a sorted array of n distinct integers that has
          been rotated an unknown number of positions, e.g., 15 36 1 7 12 13 14, write a function
          to determine if a given integer is in the list. The order of growth of the running time of
          your algorithm should be lg(n).
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */

    int * search_rotated_array(int * first, int * last, int value) {
        int i;
        int * max, * crescent, * decrescent;

        for (i = 0; i < ((last - first)) - 1; i++)
            if ( * (first + i) > * (first + i + 1))
                max = first + i;
        if ( * (max) != value)
            crescent = bsearch(first, max, value);
        if ( * (crescent) == value)
            return crescent;
        decrescent = bsearch(max + 1, last, value);
        if ( * (decrescent) == value)
            return decrescent;
        return last;
    }

    /*!
          10. Find the jump in the array. Given an array of n integers of the form 1, 2, 3, . . . , k −
          1, k + j, k + j + 1, . . . , n + j, where 1 ≤ k ≤ nandj > 0, design a logarithmic time
          algorithm to find the integer k. That is, the array contains the integers 1 through n,
          except that at some point, all remaining values are increased by j.
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */
    int find_jump(int * first, int * last) {
        if ( * (first) == * (first - 1) + 1)
            return find_jump(first + 1, last);

        return *(first - 1) + 1;
    }
    /*!
          11. Longest row of 0s. Given an N-by-N matrix of 0s and 1s such that in each row no 0
          comes before a 1, write a function that receives the matrix, finds and returns the row
          with the most 0s in O(N) time.
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */

    int longest_rown_0(int ** A, int cols) {
        int * max = & A[0][0], *
            var, iFinal, * bM = & A[0][0];
        for (int i = 0; i < cols; ++i) {
            var = lbound( & A[i][0], & A[i][cols], 1);
            if (std::distance( & A[i][0],
                    var) > std::distance(bM, max)) {
                max =
                    var;
                bM = & A[i][0];
                iFinal = i;
            }
        }
        return iFinal;
    }

    /*!
          12. Sum of two. Given two arrays A and B of at most N integers each, write a function
          that receives these arrays and determines whether the sum of any two distinct integers
          in A equals an integer in B. The function should return the three indices, two from
          A and one from B, for which the sum is true. In case there are no such indexes, your
          function should return three invalid locations (see the last paragraph in Section 2).
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */
    std::tuple < int * , int * , int * > sum_of_two(int * first1, int * last1, int * first2, int * last2) {
        for (int k = 0; k < ((last2 - first2)) - 1; k++)
            for (int j = 0; j < ((last1 - first1)) - 1; j++)
                for (int i = 0; i < ((last1 - first1)) - 1; i++)
                    if ( * (first2 + k) == * (first1 + i) + * (first1 + j) && * (first1 + i) != * (first1 + j))
                        return {
                            first2 + k,
                            first1 + i,
                            first1 + j
                        };

        return {
            last2,
            last2,
            last2
        };

    }
    /*!
           13. Sum of three. Given three arrays A, B, and C of at most N integers each, determine
          whether there exists a triple a in A, b in B, and c in C such that a + b + c = 0.
          Hint: Sort B in increasing order; sort C in decreasing order; for each a in A, scan B
          and C for a pair that sums to −a (when the sum is too small, advance in B, when the
          sum is too large, advance in C).
       * \param first Pointer to the begining of the data range.
       * \param last Pointer just past the last element of the data range.
       * \param value The value we are looking for.
       */
    std::tuple < int * , int * , int * > sum_of_three(int * first1, int * last1, int * first2, int * last2, int * first3, int * last3) {
        for (int k = 0; k < ((last3 - first3)) - 1; k++)
            for (int j = 0; j < ((last1 - first1)) - 1; j++)
                for (int i = 0; i < ((last1 - first1)) - 1; i++)
                    if ( * (first2 + k) + * (first1 + i) + * (first3 + j) == 0)
                        return {
                            first2 + k,
                            first1 + i,
                            first3 + j
                        };

        return {
            last2,
            last2,
            last2
        };
    }

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    int * lsearch(int * first, int * last, int value) {
        // TODO: Insert here your solution for the linear search problem.
        while (first != last && * first != value)
            first++;
        return first;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    int * bsearch(int * first, int * last, int value) {
        // TODO: Insert here your solution for the binary search problem.
        if ( * (first) > value)
            return last;
        if ( * (last - 1) >= * (first)) {
            int index = (last - first) / 2;
            int * mid = (first + index);

            if ( * (mid) == value)
                return mid;

            if ( * (mid) > value && mid != first) {
                int * result = bsearch(first, mid - 1, value);
                return ( * (result) != value && result < last && first <= result) ?
                    last : result;
            }
            if (mid != last)
                return bsearch(mid + 1, last, value);
        }
        return last;
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    int * lbound(int * first, int * last, int value) {
        // TODO: Insert here your solution for the lower bound problem.

        int * position = bsearch(first, last, value);

        if (position != last && * (position) != value)
            return lbound(first, last, value + 1);

        if ( * (position - 1) >= value && position - 1 <= last && first <= position - 1)
            return lbound(first, position - 1, value);

        return position;

    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    int * ubound(int * first, int * last, int value) {
        int * position = bsearch(first, last, value);

        if ( * (position + 1) == value && position + 1 <= last && first <= position + 1)
            return ubound(position + 1, last, value);
        return position;
    }

}