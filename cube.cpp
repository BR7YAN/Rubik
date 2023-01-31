#include "cube.hpp"

Cube::Cube() {
    _arrFace.insert(std::pair<std::string, Face *>("front", new Face("front", FrontGreen)));
    _arrFace.insert(std::pair<std::string, Face *>("back", new Face("back", BackBlue)));
    _arrFace.insert(std::pair<std::string, Face *>("right", new Face("right", RightRed)));
    _arrFace.insert(std::pair<std::string, Face *>("left", new Face("left", LeftOrange)));
    _arrFace.insert(std::pair<std::string, Face *>("up", new Face("up", UpWhite)));
    _arrFace.insert(std::pair<std::string, Face *>("down", new Face("down", DownYellow)));
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
    _arrFace["front"]->swapRow(1, _arrFace["right"]->getRow(1));
    _arrFace["right"]->swapRow(1, _arrFace["back"]->getRow(1));
    _arrFace["back"]->swapRow(1, _arrFace["left"]->getRow(1));
    _arrFace["up"]->autoRotate(true);
}

void Cube::downClockwise () {
    _arrFace["front"]->swapRow(3, _arrFace["left"]->getRow(3));
    _arrFace["left"]->swapRow(3, _arrFace["back"]->getRow(3));
    _arrFace["back"]->swapRow(3, _arrFace["right"]->getRow(3));
    _arrFace["down"]->autoRotate(true); // ???
}

void Cube::rightClockWise() {
    std::vector<Square *> *ret  = _arrFace["front"]->getColumn(3);
    _arrFace["up"]->swapColumn(3, ret);
    _arrFace["back"]->swapColumn(3, ret);
    _arrFace["down"]->swapColumn(3, ret);
    _arrFace["front"]->swapColumn(3, ret);
    _arrFace["right"]->autoRotate(true); // ???
    //capire come levare il leak
}

void Cube::leftClockWise() {
    std::vector<Square *> *ret  = _arrFace["front"]->getColumn(1);
    _arrFace["down"]->swapColumn(1, ret);
    _arrFace["back"]->swapColumn(1, ret);
    _arrFace["up"]->swapColumn(1, ret);
    _arrFace["front"]->swapColumn(1, ret);
    _arrFace["left"]->autoRotate(true); // ???
    //capire come levare il leak
}

void Cube::printMe() {
    _arrFace["front"]->printFace();
    _arrFace["back"]->printFace();
    _arrFace["right"]->printFace();
    _arrFace["left"]->printFace();
    _arrFace["up"]->printFace();
    _arrFace["down"]->printFace();
    std::cout << std::endl;
}