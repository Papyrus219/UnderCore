#ifndef UNDERCORE_MATERIAL_TEXTURE_HPP
#define UNDERCORE_MATERIAL_TEXTURE_HPP

#include "./texture.hpp"

namespace undercore
{

/**
 * @brief Struct that represent material texture.
 *
 * @details
 * It simplify process of applying material on shader.
 */
struct Material_texture
{
    Texture diffuse_texture{};
    Texture speculat_texture{};

    float shiness{};
};

}

#endif
