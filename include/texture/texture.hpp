#ifndef UNDERCORE_TEXTURE_HPP
#define UNDERCORE_TEXTURE_HPP

#include <filesystem>

namespace undercore
{

///@brief Enum class listing the available texture types.
enum class Texture_type
{
    DIFFUSE,
    SPECULAR,

};

std::string Texture_type_to_string(Texture_type type) noexcept;

/**
 * Struct abstractiong OpenGl texture.
 */
struct Texture
{
public:
    /**
     * @name Constructors
     * @{
     */

    Texture() noexcept = default;

    /**
     * @param [in] path     Path to load texture from.
     * @param [in] type     Type of loaded texture.
     */
    Texture(std::filesystem::path path, Texture_type type = Texture_type::DIFFUSE) noexcept;

    ///@}

    /**
     * @name Getters
     * @{
     */

    unsigned int Get_id() const noexcept {return id;};
    Texture_type Get_type() const noexcept {return type;};

    ///@}

    /**
     * @param [in] path     Path to load texture from.
     * @param [in] type     Type of loaded texture.
     */
    void Load_from_file(std::filesystem::path path, Texture_type type = Texture_type::DIFFUSE);
private:
    ///@brief Id of OpenGl texture.
    unsigned int id{};
    Texture_type type{Texture_type::DIFFUSE};
};

}

#endif //UNDERCORE_TEXTURE_HPP
