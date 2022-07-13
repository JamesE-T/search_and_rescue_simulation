
/*******************************************************************************
* Includes
******************************************************************************/
#include "camera.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void Camera::TakePicture() {
        controller->TakePicture(id);
}

ICameraResult* Camera::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
        if (cameraId == id || cameraId < 0) {
            // These will output the image to files.  Ultimately this is just for debugging:
            std::ofstream colorFile ("color.png", std::ios::out | std::ios::binary);
            colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
            std::ofstream depthFile ("depth.png", std::ios::out | std::ios::binary);
            depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);
            ImageFacade* imf = new ImageFacade();
            // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
             int width, height, components;
            IImage* color = ImageHelper::FromFile("/home/hauss011/3081W/repo-team-88/project/color.png");

            IImage* depth = ImageHelper::FromFile("/home/hauss011/3081W/repo-team-88/project/depth.png");
            ICameraResult* result;;
            std::vector<IImage*> images;
            images.push_back(color);
            images.push_back(depth);
            result = imf->ProcessImages(images);
            // std::cout << "test 2" << std::endl;
            // Generate the result of image processing.  This could include images using the Result class.


            return result;
        }
        else {
            return NULL;
         }
    }




void Camera::ImageProcessingComplete(ICameraResult* result) {
        CameraResult& res = *static_cast<CameraResult*>(result);
        if (res.found) {
            std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[1] << std::endl;
        }
        delete result;
    }