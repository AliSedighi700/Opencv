#include <Kokkos_Core.hpp>
#include <iostream>
#include "convolution.hpp"
#include "histogram_equalization.hpp"
#include "segmentation.hpp"
#include <vectors>

int main(int argc, char* argv[]) {
    Kokkos::initialize(argc, argv);
    {
        using View2D = Kokkos::View<int**>; 

        int height = 512; 
        int width = 512; 

        View2D inputImage("inputImage", height, width); 

        std::vector<std::vector<double>> blurFilter = 
        {
            {1/9.0, 1/9.0, 1/9.0},
            {1/9.0, 1/9.0, 1/9.0},
            {1/9.0, 1/9.0, 1/9.0}
        };

   

    auto bluredImage = Convolution::applyFilter(inputImage, blurFilter); 
    auto equalizeImage = HistogramEqualization::equlize(inputImage); 

    int thereshold = 128 ; 

    auto segmentation = Segmentation::thereshold(inputImage, theresholdValue); 


    }

    Kokkos::finalize(); 
    return 0; 
