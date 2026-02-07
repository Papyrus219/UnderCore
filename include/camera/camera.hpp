#ifndef UNDERCORE_CAMERA_HPP
#define UNDERCORE_CAMERA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace undercore
{

///@brief Enum class listing the available camera movement directions.
enum class Camera_movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

/**
 * @brief Abstract class representing camera in 3D space.
 */
class Camera
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
    Camera(glm::vec3 possition_ = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 up_ = glm::vec3{0.0f, 1.0f, 0.0f}, float yaw_ = YAW, float pitch_ = PITCH) noexcept;

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
    Camera(float pos_x, float pos_y, float pos_z, float up_x, float up_y, float up_z, float yaw_, float pitch_) noexcept;

    ///@}

    /**
     * @name Getters
     * @{
     */

    glm::mat4 Get_view_matrix() const noexcept { return glm::lookAt(possition, possition + front, up); };
    float Get_fov() const noexcept { return zoom;};

    ///@}

    /**
     * @name Input_processing
     * @{
     */

    /**
     * @brief Pure virtual function handling keyboard input.
     * @param [in] direction    Direction in wich camera move.
     * @param [in] delta_time   Time passed since last update.
     */
    virtual void Process_keyboard(Camera_movement direction, float delta_time) noexcept = 0;

    /**
     * @param [in] y_offset     Amount user scrolled verticly.
     */
    void Process_mouse_scroll(float y_offset) noexcept;

    /**
     * @param [in] x_offset     Current x mouse position.
     * @param [in] y_offset     Current y mouse position.
     * @param [in] constrain_pitch  Bool if we block illegal movement.
     */
    void Process_mouse_movement(float x_offset, float y_offset, bool constrain_pitch = true) noexcept;

    ///@}

    /**
     * @name Destructor
     * @{
     */

    virtual ~Camera() noexcept = default;

    ///@}
protected:
    ///@brief Recalculate camera vector.
    void Update_camera_vectors() noexcept;

    glm::vec3 possition{};
    glm::vec3 front{};
    glm::vec3 up{};
    glm::vec3 right{};
    glm::vec3 world_up{};

    float yaw{};
    float pitch{};
    float movement_speed{};
    float mouse_sensivity{};
    float zoom{};

    /**
     * @name Defaults
     * @{
     */

    static constexpr float YAW{-90.0f};
    static constexpr float PITCH{};
    static constexpr float SPEED{2.5f};
    static constexpr float SENITIVITY{0.1f};
    static constexpr float ZOOM{45.0f};

    ///@}
};

}

#endif // UNDERCORE_CAMERA_HPP
