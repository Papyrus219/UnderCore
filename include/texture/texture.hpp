#ifndef UNDERCORE_TEXTURE_HPP
#define UNDERCORE_TEXTURE_HPP

#include <filesystem>

namespace undercore
{

enum class Texture_type
{
    DIFFUSE,
    SPECULAR,

};
std::string Texture_type_to_string(Texture_type type);

struct Texture
{
public:
    Texture() = default;
    Texture(std::filesystem::path path, Texture_type type = Texture_type::DIFFUSE);

    unsigned int Get_id() const {return id;};
    Texture_type Get_type() const {return type;};

    void Load_from_file(std::filesystem::path path, Texture_type type = Texture_type::DIFFUSE);
private:
    unsigned int id{};
    Texture_type type{Texture_type::DIFFUSE};
};

}

#endif //UNDERCORE_TEXTURE_HPP
