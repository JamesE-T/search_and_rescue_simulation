#include "imagefacade.h"

ICameraResult* ImageFacade::ProcessImages(std::vector<IImage*> images){
    CompositeFilter composite;

    composite.AddFilter(new CannyEdgeDetect());
    Image cannyEdge;
    composite.Apply({images[0]} , {&cannyEdge});


    composite.AddFilter(new ColorThresholding());
    Image colorthreshold;
    composite.Apply({images[0]} , {&colorthreshold});


    ICameraResult* result = new ICameraResult();



    return result;
}