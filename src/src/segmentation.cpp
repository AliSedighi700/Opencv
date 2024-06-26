#include "segmentation.hpp" 


Segmentation::View2D Segmentation::thereshold(const View2D& inputImage, int theresholdValue)
{
    int height = inputImage.extent(0); 
    int width = inputImage.extent(1); 

    View2D outputImage("outputImage", height, width); 

    Kokkos::parallel_for("tehreshold", height * width, KOKKOS_LAMBDA(const int index){
           
            int value = inputImage(index / width, index % width); 
            outputImage(index / width, index % width) = (value > thresholdValue) ? 255 : 0;
            }); 
    return outputImage; 
}
