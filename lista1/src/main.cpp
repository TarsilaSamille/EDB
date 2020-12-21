
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore
#include <stdio.h>      /* printf, scanf, puts, NULL */

#include "../include/algoritimos.h"

using namespace sa;

std::string print(int * first, int * last) {
    std::ostringstream oss;
    std::copy(first, last, std::ostream_iterator < int > (oss, " "));
    return oss.str();
}

// Driver function.
void run_lsearch() {

    std::cout << "\n>>> run_lsearch \n\n";


    int A[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    }; // Data container.
    int targets[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -4, 20
    }; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    for (const auto & x: A)
        std::cout << x << " ";
    //std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
    for (const auto & e: targets) {
        // Look for target in the entire range.
        auto result = const_cast < int * > (lsearch(std::begin(A), std::end(A), e));

        // Process the result
        if (result != std::end(A)) {
            std::cout << ">>> Found \"" << e << "\" at position " <<
                std::distance(std::begin(A), result) << ".\n";
        } else {
            std::cout << ">>> Value \"" << e << "\" was not found in the array!\n";
        }
    }
}

void run_bsearch() {
    int A4[] {
        1, 2, 3, 4, 5, 6, 7
    };

    std::cout << ">>> A4[ " << print(std::begin(A4), std::end(A4)) << "]\n";
    for (auto i(0u); i <= (sizeof(A4) / sizeof(A4[0])) + 1; ++i) {
        std::cout << ">>> Looking for value \'" << i << "\' in A4: ";
        auto result = bsearch(std::begin(A4), std::end(A4), i);
        (result == std::end(A4)) ?
        std::cout << "Search failed!\n":
            std::cout << "Located target element at position " << std::distance(std::begin(A4), result) << std::endl;
    }
}

void run_lower_upper_bounds() {
    int A1[] {
        1, 2, 3, 3, 3, 4, 5
    };
    int A2[] {
        1, 3, 3, 4, 4, 4, 5
    };
    int A3[] {
        1, 1, 2, 2, 3, 3, 4
    };

    auto value {
        3
    };
    auto lb1 = lbound(std::begin(A1), std::end(A1), value);
    auto ub1 = ubound(std::begin(A1), std::end(A1), value);
    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A1), lb1) << std::endl;
    std::cout << "    Just past the last instance of \'" << value << "\' found at position " << std::distance(std::begin(A1), ub1) << std::endl;

    auto lb2 = lbound(std::begin(A2), std::end(A2), value);
    auto ub2 = ubound(std::begin(A2), std::end(A2), value);
    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A2), lb2) << std::endl;
    std::cout << "    Just past the last instance of \'" << value << "\' found at position " << std::distance(std::begin(A2), ub2) << std::endl;

    auto lb3 = lbound(std::begin(A3), std::end(A3), value);
    auto ub3 = ubound(std::begin(A3), std::end(A3), value);
    std::cout << ">>> A3[ " << print(std::begin(A3), std::end(A3)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A3), lb3) << std::endl;
    std::cout << "    Just past the last instance of \'" << value << "\' found at position " << std::distance(std::begin(A3), ub3) << std::endl;
}

void run_local_minimum() {
    std::cout << "\n>>> run_local_minimum \n\n";

    int A1[] = {
        35, 33, 42, 15, 14, 19, 27, 44, 26, 31
    };
    auto lm1 = local_minimum(std::begin(A1), std::end(A1));

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";
    std::cout << "    local_minimum '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;
}

void run_local_minimum_matrix() {

    std::cout << "\n>>> run_local_minimum_matrix \n\n";

    int ** A1;
    A1 = new int * [10];

    for (int i = 0; i < 10; ++i) {
        A1[i] = new int[10];
    }
    for (int i = 0; i < 10; ++i) { // for each row
        for (int j = 0; j < 10; ++j) { // for each column
            A1[i][j] = rand() % 50;
        }
    }

    std::tuple < int, int > t = local_minimum_matriz(A1, 10);

    for (int i = 0; i < 10; ++i) { // for each row

        std::cout << ">>> A1[ " << print( & A1[i][0], & A1[i][10]) << "]\n";

    }

    int ni, nj;

    std::tie(ni, nj) = t;

    std::cout << "Existe [";
    std::cout << ni << ",";
    std::cout << nj << "]=";
    std::cout << A1[ni][nj] << "\n";

}

void run_bitonic_search() {
    std::cout << "\n>>> run_bitonic_search \n\n";


    int A1[] = {
        6, 7, 8, 11, 9, 5, 2, 1
    };

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    int * lm1 = bitonic_search(std::begin(A1), std::end(A1), 1);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    bitonic_search '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = bitonic_search(std::begin(A1), std::end(A1), 2);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    bitonic_search '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = bitonic_search(std::begin(A1), std::end(A1), 11);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    bitonic_search '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = bitonic_search(std::begin(A1), std::end(A1), 12);
    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    bitonic_search '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;
}

void run_binary_search_with_diplicates() {
    std::cout << "\n>>> run_binary_search_with_diplicates \n\n";


    int A1[] {
        1, 2, 3, 3, 3, 4, 5
    };
    int A2[] {
        1, 3, 3, 4, 4, 4, 5
    };
    int A3[] {
        1, 1, 2, 2, 3, 3, 4
    };

    auto value {
        3
    };
    auto lb1 = binary_search_with_diplicates(std::begin(A1), std::end(A1), value);
    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A1), lb1) << std::endl;

    auto lb2 = binary_search_with_diplicates(std::begin(A2), std::end(A2), value);
    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A2), lb2) << std::endl;

    auto lb3 = binary_search_with_diplicates(std::begin(A3), std::end(A3), value);
    std::cout << ">>> A3[ " << print(std::begin(A3), std::end(A3)) << "]\n";
    std::cout << "    First instance of \'" << value << "\' found at position " << std::distance(std::begin(A3), lb3) << std::endl;
}

void run_identity() {
    std::cout << "\n>>> run_identity \n\n";


    int A1[] {
        -2, -1, 2, 3, 4, 8, 9, 55
    };
    auto lb1 = identity(std::begin(A1), std::end(A1));
    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    (lb1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    identity:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A1), lb1) << std::endl;

    int A2[] {
        -2, -1, 0, 2, 3, 5, 6, 7
    };
    lb1 = identity(std::begin(A2), std::end(A2));
    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";

    (lb1 == std::end(A2)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    identity:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A2), lb1) << std::endl;

    int A3[] {
        0, 2, 3, 5, 6, 7
    };
    lb1 = identity(std::begin(A3), std::end(A3));
    std::cout << ">>> A3[ " << print(std::begin(A3), std::end(A3)) << "]\n";

    (lb1 == std::end(A3)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    identity:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A3), lb1) << std::endl;

    int A4[] {
        1, 2, 3, 5, 6, 7
    };
    lb1 = identity(std::begin(A4), std::end(A4));
    std::cout << ">>> A4[ " << print(std::begin(A4), std::end(A4)) << "]\n";

    (lb1 == std::end(A4)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    identity:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A4), lb1) << std::endl;

}

void run_find_duplicate() {

        std::cout << "\n>>> run_find_duplicate \n\n";

    int A1[] {
        1, 2, 2, 3, 4, 5, 6
    };
    auto lb1 = find_duplicate(std::begin(A1), std::end(A1));
    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    (lb1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    find_duplicate:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A1), lb1) << std::endl;

    int A2[] {
        1, 1, 2, 3, 4, 5, 6
    };
    lb1 = find_duplicate(std::begin(A2), std::end(A2));
    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";

    (lb1 == std::end(A2)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    find_duplicate:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A2), lb1) << std::endl;

    int A3[] {
        1, 2, 3, 4, 5, 6, 6
    };
    lb1 = find_duplicate(std::begin(A3), std::end(A3));
    std::cout << ">>> A3[ " << print(std::begin(A3), std::end(A3)) << "]\n";

    (lb1 == std::end(A3)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    find_duplicate:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A3), lb1) << std::endl;

    int A4[] {
        1, 2, 3, 4, 5, 6, 7
    };
    lb1 = find_duplicate(std::begin(A4), std::end(A4));
    std::cout << ">>> A4[ " << print(std::begin(A4), std::end(A4)) << "]\n";

    (lb1 == std::end(A4)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    find_duplicate:  '" << * (lb1) << "\' found at position " << std::distance(std::begin(A4), lb1) << std::endl;

}
void run_find_jump() {
        std::cout << "\n>>> run_find_jump \n\n";


    int A1[] {
        1, 2, 3, 5, 6
    };
    int jump = find_jump(std::begin(A1), std::end(A1));
    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    std::cout << "    find_jump:  '" << jump << std::endl;
}

void run_longest_rown_0() {
            std::cout << "\n>>> run_longest_rown_0 \n\n";

    int ** A1;
    A1 = new int * [10];

    for (int i = 0; i < 10; ++i) {
        A1[i] = new int[10];
    }
    for (int i = 0; i < 10; ++i) { // for each row
        int ate = rand() % 10;
        for (int j = 0; j < 10; ++j) {
            if (j < ate) // for each column
                A1[i][j] = 0;
            else A1[i][j] = 1;
        }
    }

    int t = longest_rown_0(A1, 10);

    for (int i = 0; i < 10; ++i) { // for each row

        std::cout << ">>> A1[ " << print( & A1[i][0], & A1[i][10]) << "]\n";

    }

    std::cout << "Existe ";
    std::cout << ">>> FINAL[ " << print( & A1[t][0], & A1[t][10]) << "]\n";

}

void run_search_rotated_array() {
                std::cout << "\n>>> run_search_rotated_array \n\n";


    int A1[] = {
        6, 7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    int * lm1 = search_rotated_array(std::begin(A1), std::end(A1), 1);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    search_rotated_array: '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = search_rotated_array(std::begin(A1), std::end(A1), 2);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    search_rotated_array: '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = search_rotated_array(std::begin(A1), std::end(A1), 8);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    search_rotated_array: '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

    lm1 = search_rotated_array(std::begin(A1), std::end(A1), -1);

    (lm1 == std::end(A1)) ?
    std::cout << "  Search failed!\n":
        std::cout << "    search_rotated_array: '" << * (lm1) << "\' found at position " << std::distance(std::begin(A1), lm1) << std::endl;

}

void run_sum_of_two() {
                    std::cout << "\n>>> run_search_rotated_array \n\n";


    int A1[] = {
        6, 7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    int A2[] = {
        6, 7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";

    std::tuple < int * , int * , int * > teste = sum_of_two(std::begin(A1), std::end(A1), std::begin(A2), std::end(A2));

    int * resultado, * n1, * n2;

    std::tie(resultado, n1, n2) = teste;

    std::cout << "Existe ";
    std::cout << * (n1) << "+";
    std::cout << * (n2) << '=';
    std::cout << * (resultado) << '\n';

}

void run_sum_of_three() {
                    std::cout << "\n>>> run_sum_of_three \n\n";

    int A1[] = {
        6, 7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    int A2[] = {
        6, 7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A2[ " << print(std::begin(A2), std::end(A2)) << "]\n";

    int A3[] = {
        6, -7, 8, 11, 1, 2, 3, 4
    };

    std::cout << ">>> A3[ " << print(std::begin(A3), std::end(A3)) << "]\n";

    std::tuple < int * , int * , int * > teste = sum_of_three(std::begin(A1), std::end(A1), std::begin(A2), std::end(A2), std::begin(A3), std::end(A3));

    int * resultado, * n1, * n2;

    std::tie(resultado, n1, n2) = teste;

    std::cout << "Existe ";
    std::cout << * (n1) << "+";
    std::cout << * (n2) << '+';
    std::cout << * (resultado) << "=0\n";

}

void run_floor_ceiling() {
                        std::cout << "\n>>> run_floor_ceiling \n\n";


    int A1[] {
        -2, -1, 2, 3, 4, 8, 9, 55
    };

    std::cout << ">>> A1[ " << print(std::begin(A1), std::end(A1)) << "]\n";

    std::tuple < int * , int * > teste = floor_ceiling(std::begin(A1), std::end(A1), 1);

     int * floor, * ceiling;

    std::tie(floor, ceiling) = teste;

    std::cout << "floor:";
    std::cout << * (floor) << " ceiling:";
    std::cout << * (ceiling) <<  '\n';

}

void run_cold_hot(){
     std::cout << "\n>>> run_cold_hot \n\n";

    int tamanho;
    printf ("N: ");
    scanf ("%d",&tamanho);


    hot_or_cold(tamanho);
}


int main(int argc, char *argv[])
{

    run_local_minimum();

    run_local_minimum_matrix();

    run_bitonic_search();

    run_binary_search_with_diplicates();

    run_identity();

    run_find_jump();

    run_search_rotated_array();

    run_sum_of_two();

    run_sum_of_three();

    run_floor_ceiling();

    run_longest_rown_0();

    run_cold_hot();

    return 1;
}


