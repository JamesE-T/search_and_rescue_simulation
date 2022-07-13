#include "colorthresholding.h"

void ColorThresholding::ApplyInternal(const vector<IImage *> &inputs, const vector<IImage *> &outputs) {
        // Do not modify any of the inputs
        // Outputs are assumed to be empty images, resize them first

        const IImage& input = *inputs[0];
        IImage& output = *outputs[0];

        // pick 1 or 2
        // 1. resize image to have same dimensions as input (does not copy pixels over)
        output.Resize(input);

        // loop over pixels
        for (int x = 0; x < input.GetWidth(); x++) {
            for (int y = 0; y < input.GetHeight(); y++) {
                Color pixel = input.GetPixel(x,y);
                Color orange = Color(1, .643, .035);
                Color strong_orange = orange*1.1;
                Color weak_orange = orange*.9;
                Color white = Color(1,1,1);
                Color black = Color(0,0,0);
                if(pixel.GetLuminance() < strong_orange.GetLuminance() || pixel.GetLuminance() > weak_orange.GetLuminance()){
                    output.SetPixel(x,y, white);
                }
                else{
                    output.SetPixel(x,y, black);
                }
            }
        }
    }