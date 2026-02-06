#ifndef UNDERCORE_MATERIAL_TEXTURE_HPP
#define UNDERCORE_MATERIAL_TEXTURE_HPP

#include "./texture.hpp"

namespace undercore
{

struct Material_texture
{
    Texture diffuse_texture{};
    Texture speculat_texture{};

    float shiness{};
};

}

#endif
