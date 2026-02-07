#ifndef UNDERCORE_MESH_HPP
#define UNDERCORE_MESH_HPP

#include <vector>
#include "./vertex.hpp"
#include "./primitives.hpp"

namespace undercore
{

/**
 * @brief Class representing polygon mesh.
 *
 * @details
 * It is colection od vertecies and indices, with knowleage how to draw itself.
 */
class Mesh
{
public:
    /**
     * @name Constructors
     * @{
     */

    Mesh() noexcept = default;

    /**
     * @param [in] vertecies_ Vertecies of the mesh.
     * @param [in] indices_ Indices of the mesh.
     */
    Mesh(std::vector<Vertex> vertices_, std::vector<unsigned int> indices_) noexcept;

    /**
     * @param [in] primitive Primitive enum, wich we want mesh to represent.
     */
    Mesh(Primitive primitive) noexcept;

    /**
     * @}
     */

    ///@brief Bind the vao, and call to draw object.
    void Draw() const noexcept;

    /**
     * @name Destructor
     * @{
     */
    ~Mesh() noexcept;
    ///@}
private:
    ///@brief Buffer mesh data to OpenGl objects.
    void Buffer_data() noexcept;

    /**
     * @name Generation functions
     * @{
     */

    ///@brief Vertecies and indices generation for cube primitive.
    void Gen_cube_primitive() noexcept;
    ///@brief Vertecies and indices generation for sphere primitive.
    void Gen_sphere_primitive() noexcept;

    /**
     * @}
     */

    /**
     * @name OpenGl objects
     * @{
     */
    ///@brief Vertex array object id.
    unsigned int vao{};
    ///@brief Vertecies buffer object id.
    unsigned int vbo{};
    ///@brief Element buffer object id.
    unsigned int ebo{};

    ///@}

    /**
     * @name Mesh data
     * @{
     */

    std::vector<Vertex> vertices{};
    std::vector<unsigned int> indices{};

    ///@}
};

}

#endif //UNDERCORE_MESH_HPP
