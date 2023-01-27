#include "square.hpp"

Square::Square() {
}

Square::Square(std::string color): _color(color){
}

Square::~Square() {
}

std::string Square::getColor() {
    return _color;
}