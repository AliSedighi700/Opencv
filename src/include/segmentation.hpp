#ifndef SEGMENTATION_HPP
#define SWGMENTATION_HPP

#include <Kokkos_Core.hpp>


Class Segmentation
{
    public: 
        using View2D = Kokkos::View<int **>; 

        static View2D threshold(const View2D& inputImage, int theresholdVlue); 
};
