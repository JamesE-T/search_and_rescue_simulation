/**
 * @file camera.h
 * @author Jack Haussner/3081 teams code
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include "camera_controller.h"
#include <fstream>
#include "imagefacade.h"
#include "stb_image_write.h"
#include "stb_image.h"


class Camera : public ICameraObserver {
public:

    /**
     * @brief structure of the camera result returned to drone.
     * 
     */
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    /**
     * @brief Construct a new Camera object
     * 
     * @param cameraId 
     * @param controller 
     */
    Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
        controller->AddObserver(*this);
    }

    /**
     * @brief take a picture from the drone camera.
     * 
     */
    void TakePicture();

    /**
     * @brief process the images, calls the image facade to complete the algorithm on it.
     * 
     * @param cameraId 
     * @param xPos 
     * @param yPos 
     * @param zPos 
     * @param images 
     * @param details 
     * @return ICameraResult* 
     */
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;

    /**
     * @brief returns the completed result to the drone.
     * 
     * @param result 
     */
    void ImageProcessingComplete(ICameraResult* result);

private:
    ICameraController* controller;
    int id;
};