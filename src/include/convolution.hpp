#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP

#include <Kokkos_core.hpp>
#include <vector>

class Convolution
{
    public: 
        using View2D = Kokkos::View<double***> ; 
    
        static View2D applyFilter(const View2D inputImage, const sd::vector<std::vector<double>>& filter); 

    private: 

        static void convolve(const View2D& inputImage, const View2D& outputImage, const std::vector<std::vector<double>>& filter); 

};
#endif 
