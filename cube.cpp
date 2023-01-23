#include "cube.hpp"

Cube::Cube() {
    _arrFace.insert(std::pair<std::string, Face *>("white", new Face("white")));
    _arrFace.insert(std::pair<std::string, Face *>("black", new Face("black")));
    _arrFace.insert(std::pair<std::string, Face *>("red", new Face("red")));
    std::cout << "Cubo creato" << std::endl;
}

Cube::~Cube() {
    this->deleteFaces();
    std::cout << "Cubo distrutto" << std::endl;
}

void Cube::deleteFaces() {
    // for (face_iter i = _arrFace.begin(); i != _arrFace.end(); i++) {
    //     std::cout << "elemento = " << i->first << std::endl;
    //     Face *face = i->second;
    //     delete face;
    //     _arrFace.erase(i->first);
    // }

        face_iter i = _arrFace.begin();
        while (i != _arrFace.end()) {
            std::cout << "elemento = " << i->first << std::endl;
            Face *face = i->second;
            delete face;
            i = _arrFace.erase(i);
            //std::cout << "elemento = " << i->first << std::endl;
    }
}