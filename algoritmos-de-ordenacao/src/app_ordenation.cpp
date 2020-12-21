#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "../include/ordenation.h"

using namespace oa;

std::string print( value_type * first, value_type * last )
{
    std::ostringstream oss;
    std::copy( first, last, std::ostream_iterator< value_type > ( oss, " " ) );
    return oss.str();
}


    void run_insertionsort(){
        std::cout << "run_insertionsort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        insertionsort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }

    void run_selectionsort(){
        std::cout << "run_selectionsort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        selectionsort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }
    void run_bubblesort(){
        std::cout << "run_bubblesort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        bubblesort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }
    void run_shellsort(){
        std::cout << "run_shellsort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        shellsort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }
    void run_quicksort(){
        std::cout << "run_quicksort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        quicksort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }
    void run_mergesort(){
        std::cout << "run_mergesort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        mergesort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }
    void run_radixsort(){
        std::cout << "run_radixsort()\n";
        value_type arr[] = {64, 25, 12, 22, 11};  
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
        radixsort( std::begin(arr), std::distance ( std::begin(arr), std::end(arr)));
        std::cout << ">>> arr[ " << print( std::begin(arr), std::end(arr) ) << "]\n";
    }


int main(void)
{
    run_insertionsort();
    run_selectionsort();
    run_bubblesort();
    run_shellsort();
    run_quicksort();
    run_mergesort();
    run_radixsort();

    return 0;
}
