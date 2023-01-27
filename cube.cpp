#include "cube.hpp"

Cube::Cube() {
    _arrFace.insert(std::pair<std::string, Face *>("front", new Face("front", FrontGreen)));
    _arrFace.insert(std::pair<std::string, Face *>("back", new Face("back", BackYellow)));
    _arrFace.insert(std::pair<std::string, Face *>("right", new Face("right", RightRed)));
    _arrFace.insert(std::pair<std::string, Face *>("left", new Face("left", LeftOrange)));
    _arrFace.insert(std::pair<std::string, Face *>("up", new Face("up", UpWhite)));
    _arrFace.insert(std::pair<std::string, Face *>("down", new Face("down", DownBlue)));
}

Cube::~Cube() {
    this->deleteFaces();
}

void Cube::deleteFaces() {
        face_iter i = _arrFace.begin();
        while (i != _arrFace.end()) {
            Face *face = i->second;
            delete face;
            i = _arrFace.erase(i);
    }
}

void Cube::printFace(std::string side) {
    _arrFace[side]->printFace();
}

void Cube::upClockwise () {
    _arrFace["front"]->change1thRow(_arrFace["right"]->getRow(1));
}

// void Cube::upClockwise () {
    
// }

void Cube::printMe() {
    _arrFace["front"]->printFace();
    _arrFace["back"]->printFace();
    _arrFace["right"]->printFace();
    _arrFace["left"]->printFace();
    _arrFace["up"]->printFace();
    _arrFace["down"]->printFace();
    std::cout << std::endl;
}