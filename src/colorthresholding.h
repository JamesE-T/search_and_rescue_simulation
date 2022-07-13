#ifndef COLORTHRESHOLDING
#define COLORTHRESHOLDING

#include "imageio/filter.h"

using namespace imageio;

// Creating your own Filter class is simple. Just override ApplyInternal().
class ColorThresholding : public Filter {
public:
    // 1 input, 1 output
    ColorThresholding() : Filter(1, 1) {}

protected:
    void ApplyInternal(const vector<IImage *> &inputs, const vector<IImage *> &outputs) override;
};

#endif //ColorThresholding