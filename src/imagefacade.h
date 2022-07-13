/**
 * @file imagefacade.h
 * @author Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IMAGEFACADE
#define IMAGEFACADE
/*******************************************************************************
* Includes
******************************************************************************/
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "canny_edge_detect.h"
#include "composite_filter.h"
#include "iimage.h"
#include "image_helper.h"
#include "image_processor.h"
#include "colorthresholding.h"
#include "camera_controller.h"


class ImageFacade {

    public:
        /**
         * @brief Construct a new Image Facade object
         * 
         */
        ImageFacade(){}
        /**
         * @brief Destroy the Image Facade object
         * 
         */
        ~ImageFacade(){}
        /**
         * @brief calls the processImage functions using created filters to decide whether or not the drone is there.
         * 
         * @param images 
         * @return ICameraResult* 
         */
        ICameraResult* ProcessImages(std::vector<IImage*> images);

};
#endif //SearchandRescue