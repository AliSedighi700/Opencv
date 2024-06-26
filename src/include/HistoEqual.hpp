#ifndef HISTOEQUAL_HPP
#define HISTOEQUAL_HPP

#include<Kokkos_Core.hpp>

class HistogramEqualization{

    public:

        using View2D = Kokkos::View<int**> ; 
        static View2D equalize(const View2D& inputImage); 

    private: 

        static void calculateHistogram(const View2D inputImage, Kokkos::View<int*> histogram);

        static void calculateCdf(Kokkos::View<int*> histogram, Kokkos::View<int*> cdf); 
        static void applyEqualization(const View2D inputImage, View2D outputImage, 
                                      Kokkos::View<int*> cdf); 
};
#endif HISTOEQUAL_HPP
