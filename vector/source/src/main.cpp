#include "../include/vector.h"

int main(void)
{

    sc::vector<int> vec{ 1, 2, 3, 4, 5 };
    sc::vector<int> vec2;

    vec2 = std::move( vec );
   std::cout << vec2.size() << " == 5" << std::endl;
   std::cout << vec2.empty() << " == ASSERT_FALSE" << std::endl;
   std::cout << vec.size() << " == 0" << std::endl;
   std::cout << vec.capacity() << " == 0" << std::endl;
   std::cout << vec.empty() << " == EXPECT_TRUE" << std::endl;

    // // CHeck whether the copy worked.
    for( auto i{0u} ; i < vec2.size() ; ++i )
       std::cout << i+1 << " == vec2[i]" <<vec2[i]<< std::endl;

  return 0;
}