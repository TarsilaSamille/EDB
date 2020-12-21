/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + linear search
 *  + upper bound
 *  + lower bound
 *  + binary search
 *
 * \author Selan R. dos Santos
 * \date July, 31st.
 */

#ifndef SEARCHING_H
#define SEARCHING_H

#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

#include <iterator>

/// Searching Algorithms Namespace
namespace sa {

    /// just an alias for an integer type.

    /// local minimum.
    int * local_minimum(int * first, int * last);

    /// local minimum matriz
    std::tuple < int, int > local_minimum_matriz(int ** A, int cols);

    /// bitonic search.
    int * bitonic_search(int * first, int * last, int value);

    /// binary search with diplicates
    int * binary_search_with_diplicates(int * first, int * last, int value);

    /// return a[i] = i, if if such an index exists.
    int * identity(int * first, int * last);
    int * bsearch_identity(int * first, int * last);

    /// find_jump
    int find_jump(int * first, int * last);

    int longest_rown_0(int ** A, int cols);

    std::tuple < int * , int * > floor_ceiling(int * first, int * last, int value);

    std::tuple < int * , int * , int * > sum_of_two(int * first1, int * last1, int * first2, int * last2);

    std::tuple < int * , int * , int * > sum_of_three(int * first1, int * last1, int * first2, int * last2, int * first3, int * last3);

    int * search_rotated_array(int * first, int * last, int value);
    /// find duplicate( int * first, int * last )

    int * find_duplicate(int * first, int * last);

    //hot or cold
    void hot_or_cold(int n);

    /// local minimum.
    void reverseArray(int * first, int * last);

    /// Linear search.
    int * lsearch(int * first, int * last, int value);

    /// Binary search.
    int * bsearch(int * first, int * last, int value);

    /// Lower bound.
    int * lbound(int * first, int * last, int value);

    /// Upper bound.
    int * ubound(int * first, int * last, int value);
}

#endif // SEARCHING_H