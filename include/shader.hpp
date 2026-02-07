#ifndef UNDERCORE_SHADER_HPP
#define UNDERCORE_SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

#include "texture/material.hpp"

namespace undercore
{

/**
 * @brief Class abstracting OpenGl shader.
 */
class Shader
{
public:
    /**
     * @name Constructors
     * @{
     */

    /**
     * @param vertex_path   Path to file contained vertex shader source.
     * @param fragment_path Path to file contained fragment shader source.
     */
    Shader(const char* vertex_path, const char* fragment_path);

    ///@}

    ///@brief Active shader.
    void Use();

    /**
     * @name Setters
     * @{
     */


    void Set_bool(const std::string &name, bool value) noexcept;
    void Set_int(const std::string &name, int value) noexcept;
    void Set_float(const std::string &name, float value) noexcept;

    void Set_vec2(const std::string &name, const glm::vec2 vector) noexcept;
    void Set_vec2(const std::string &name, int x, int y) noexcept;

    void Set_vec3(const std::string &name, const glm::vec3 vector) noexcept;
    void Set_vec3(const std::string &name, int x, int y, int z) noexcept;

    void Set_vec4(const std::string &name, const glm::vec4 vector) noexcept;
    void Set_vec4(const std::string &name, int x, int y, int z, int w) noexcept;

    void Set_matrix2(const std::string &name, const glm::mat2 matrix) noexcept;

    void Set_matrix3(const std::string &name, const glm::mat3 matrix) noexcept;

    void Set_matrix4(const std::string &name, const glm::mat4 matrix) noexcept;

    void Set_Material(const Material_texture &material) noexcept;

    ///@}

    /**
     * @name Getters
     * @{
     */

    unsigned int Get_id() const noexcept;

    ///@}

    /**
     * @name Destructors
     * @{
     */

    ~Shader() noexcept;

    ///@}
private:
    ///@brief OpenGl shader object id.
    unsigned int id{};
};

}

#endif // UNDERCORE_SHADER_HPP
