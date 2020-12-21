/**
 * @file timing_template.cpp
 * @author Társila Samille Santos da Silveira (tarsillasamile@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <math.h>
#include "ordenation.h"

using namespace oa;
using namespace std;

constexpr unsigned long long LIMIT{1000000};

int main( void )
{

    unsigned long tamanho_array = 10000ul;

    while(tamanho_array <= LIMIT + 1){

        value_type *crescente = new value_type[tamanho_array];

        for( auto i{0ull} ; i < tamanho_array ; ++i ){
            //crescente[i]  =  i;
            //decrescente[i] =  tamanho_array - i;
            //aleatorio[i] =  rand() % tamanho_array;
            //aleatorio75[i] =  (i%4==0)  ? i :  rand() % tamanho_array;
            //aleatorio50[i] =  (i%2==0)  ? i :  rand() % tamanho_array;
            //aleatorio25[i] =  (i%4!=0)  ? i :  rand() % tamanho_array;
        }




        auto start = std::chrono::steady_clock::now();
        //================================================================================

    // insertionsort(&crescente[0], tamanho_array );
    // selectionsort(&crescente[0], tamanho_array );
    // bubblesort(&crescente[0], tamanho_array );
    // shellsort(&crescente[0], tamanho_array );
    // quicksort(&crescente[0], tamanho_array );
    // mergesort(&crescente[0], tamanho_array );
    // radixsort(&crescente[0], tamanho_array );
        //================================================================================

        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = end - start;

        std::cout << " " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;

        delete [] crescente;

        tamanho_array = tamanho_array + 40000;

    }

    return EXIT_SUCCESS;
}
