#include "../../include/geometry/vertex.hpp"

undercore::Vertex::Vertex(float pos_x, float pos_y, float pos_z, float normal_x, float normal_y, float normal_z, float tex_cords_x, float tex_cords_y) noexcept: position{pos_x, pos_y, pos_z}, normal{normal_x, normal_y, normal_z}, tex_cords{tex_cords_x, tex_cords_y}
{

}

undercore::Vertex::Vertex(glm::vec3 position_, glm::vec3 normal_, glm::vec3 tex_cords_) noexcept: position{position_}, normal{normal_}, tex_cords{tex_cords_}
{

}
