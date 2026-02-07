#ifndef UNDERCORE_VERTEX_HPP
#define UNDERCORE_VERTEX_HPP

#include <glm/glm.hpp>

namespace undercore
{

/**
 * @brief Vertex class
 *
 * @details
 * It representing points in 3D space.
 * Class contains most of important data we need to send to GPU.
*/
struct Vertex
{
    /** @name Constructors
     *@{
     */
    /**
     * @brief Default constructor.
     */
    Vertex() noexcept = default;

    /**
     * @param [in] poss_x Position x of a point in 3D space.
     * @param [in] poss_y Position y of a point in 3D space.
     * @param [in] poss_z Position z of a point in 3D space.
     * @param [in] normal_x Normalize x direction of a point in 3D space.
     * @param [in] normal_y Normalize y direction of a point in 3D space.
     * @param [in] normal_z Normalize z direction of a point in 3D space.
     * @param [in] tex_cords_x Position x of a point on the texture, that corresponds to the position x of this point in the 3D space.
     * @param [in] tex_cords_y Position y of a point on the texture, that corresponds to the position y of this point in the 3D space.
     */
    Vertex(float pos_x, float pos_y, float pos_z, float normal_x, float normal_y, float normal_z, float tex_cords_x, float tex_cords_y) noexcept;

    /**
     * @param [in] possition_ Coordinates of a point in 3D space.
     * @param [in] normal_ Normalize direction of a point in 3D space.
     * @param [in] tex_cords_ Position of a point on the texture, that corresponds to the position of this point in the 3D space.
     */
    Vertex(glm::vec3 position_, glm::vec3 normal_, glm::vec3 tex_cords_) noexcept;
    /**
     * @}
     */

    ///@brief Coordinates of a point in 3D space.
    glm::vec3 position{};
    ///@brief Normalize direction of a point in 3D space
    glm::vec3 normal{};
    ///@brief Position of a point on the texture, that corresponds to the position of this point in the 3D space.
    glm::vec2 tex_cords{};
};

}

#endif
