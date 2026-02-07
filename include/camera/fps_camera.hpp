#ifndef UNDERCORE_FPS_CAMERA_HPP
#define UNDERCORE_FPS_CAMERA_HPP

#include "camera.hpp"

namespace undercore
{

///@brief Implementation of Camera (first person).
class FPS_camera : public Camera
{
public:
    /**
     * @name Constructors
     * @{
     */

    /**
     * @param [in] possition_   Start position of a camera.
     * @param [in] up_      Up direction of world.
     * @param [in] yaw_     x axis rotation euler angle.
     * @param [in] pitch_   y axis rotation euler angle.
     */
    FPS_camera(glm::vec3 possition_ = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 up_ = glm::vec3{0.0f, 1.0f, 0.0f}, float yaw_ = YAW, float pitch_ = PITCH) noexcept;

    /**
     * @param [in] pos_x    Start position x of a camera.
     * @param [in] pos_y    Start position y of a camera.
     * @param [in] pos_z    Start position z of a camera.
     * @param [in] up_x     Up x direction of world.
     * @param [in] up_y     Up y direction of world.
     * @param [in] up_z     Up z direction of world.
     * @param [in] yaw_     x axis rotation euler angle.
     * @param [in] pitch_   y axis rotation euler angle.
     */
    FPS_camera(float pos_x, float pos_y, float pos_z, float up_x, float up_y, float up_z, float yaw_, float pitch_) noexcept;

    ///@}

    /**
     * @name Input_processing
     * @{
     */

    /**
     * @brief Implementation form Camera class.
     * @param [in] direction    Direction in wich camera move.
     * @param [in] delta_time   Time passed since last update.
     */
    void Process_keyboard(Camera_movement direction, float delta_time) noexcept override;

    ///@}
};

}

#endif // UNDERCORE_FPS_CAMERA_HPP
