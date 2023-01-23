#include "face.hpp"

Face::Face() {
    std::cout << "Faccia creata" << std::endl;
}

Face::Face(std::string color) {
    std::cout << "Faccia creata con colore " << color << " " << std::endl;
}

Face::~Face() {
    std::cout << "Faccia distrutta" << std::endl;
}