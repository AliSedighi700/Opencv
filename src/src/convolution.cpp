#include"convolution.hpp"

Concolution::View2D Convolution::applyFilter(const View2D inputImage, 
                                             const std::vector<std::vector<double>>& filter){
    int numRows = inputImage.extent(0); 
    int numCols = inputImage.extent(1); 

    View2D outputImage("outputImage", numRows, numCols); 

    convolve(inputeImage, outputImgae, filter); 

    return outputImage;
}

void Concolution::convolve(const View2D inputImage, const View2D outputImage, 
        const std::vector<std::vector<double>>& filter){


    int numRows = inputImage.extent(0); 
    int numCols = inputImage.extent(1);

    int filterSize = filter.size(); 

    int offset = filterSize / 2;
    

    Kokkos::parallel_for("Convolution", 
                         Kokkos::MDRangePolicy<Kokkos::Rank<2>>({offset, offset}, 
                         {numRows - offset, numCols - offset}),
                         KOKKOS_LAMBDA(const int i , const int j){
                            double sum = 0.0; 
                            for(int fi = 0 ; fi < filterSize(); ++fi){
                              for(int fj = 0 ; fj < filterSize; ++fj){
                                sum += inputImage(i + fi - offset, j + fj - offset) * fiter[fi][fj]; 
                              }
                            }

                           outputImage(i,j) = sum; 
            
            });
}



