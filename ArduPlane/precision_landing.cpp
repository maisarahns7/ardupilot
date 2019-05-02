//
// functions to support precision landing
//

#include "Plane.h"

#if PRECISION_LANDING == ENABLED

void Plane::init_precland()
{
    plane.precland.init();
}

void Plane::update_precland()
{
    int32_t height_above_ground_cm = current_loc.alt;

    // temp
    //plane.precland.init();

    // use range finder altitude if it is valid
    if (rangefinder_state.in_range) {
        height_above_ground_cm = rangefinder.distance_cm_orient(ROTATION_PITCH_270);
    }
    plane.precland.update(height_above_ground_cm, rangefinder_state.in_range);
}
#endif
