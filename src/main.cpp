#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    Kokkos::initialize(argc, argv);

  {
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7,8,9,6};


    // Create a Kokkos View to store data
    Kokkos::View<int*> nums("nums", 10);

    // Copy data into Kokkos View using deep_copy
    //
    for(int i : vec1){
    Kokkos::deep_copy(nums, i);
    }

    Kokkos::parallel_for("print", 10, KOKKOS_LAMBDA(int i){std::cout << nums(i) << '\n' ;}); 

  }

    Kokkos::finalize();
    return 0;
}

