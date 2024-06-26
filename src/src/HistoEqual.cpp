#include "HistoEqual.hpp"
#include <Kokkos_ScatterView.hpp>

HistogramEqualization::View2D HistogramEqualization::equalize(const View2D inputImage)
{
    int height = inputImage.extent(0); 
    int width = inputImage.extent(1); 

    View2D output("outImage", height, width); 
    Kokkos::View<int *> histogram("histogram", 256); 
    Kokkos::View<int*> cdf("cdf" , 256);

    calculateHistogram(inputImage, histigram); 
    calculareCdf(histogram, cdf); 
    applyEqualization(inputImage, outputImage, cdf); 

    return outputImage; 
}


void HistogramEqualization::calculateHistogram(const View2D inputImage, Kokkos::View<int*> histogram)
{
   int height = inputImage.extent(0); 
   int width = inputImage.extent(1); 

   Kokkos::parallel_for("CalculateHisto",height * width, KOKKOS_LAMBDA(const int i){
           
           int value = inputImage(index / width, index % width); 
           Kokkos::atomic_increment(&histogram(value));
           });
}

void HistogramEqualization::calculateCdf(Kokkos::View<int*> histogram, Kokkos::View<int*> cdf)
{
    Kokkos::Parallel_for("calculatecdf", 256, KOKKOS_LAMBDA(const int i, int& update, const bool final){
                update += histogram(i);
                if(final)
                {
                    cdf(i) = update;
                }
            });
}

void HistogramEqualization::applyEqualization(const View2D inputImage, View2D outputImage, 
                                              Kokkos::View<int*>cdf){
     int height = inputImage.extent(0);
    int width = inputImage.extent(1);
    int totalPixels = height * width;
    int minValue = cdf(0);
    
      Kokkos::parallel_for("ApplyEqualization", height * width, KOKKOS_LAMBDA(const int index) {
        int value = inputImage(index / width, index % width);
        outputImage(index / width, index % width) = (cdf(value) - minValue) * 255 / (totalPixels - minValue);
    });
}




