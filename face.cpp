#include "face.hpp"

Face::Face() {
    std::cout << "Faccia creata" << std::endl;
}

Face::Face(std::string side, std::string color): _side(side){
    for(int i = 0; i < 3; i++){
        _1thRow[i] = new Square(color);
        _2thRow[i] = new Square(color);
        _3thRow[i] = new Square(color);
    }
    //std::cout << "Faccia side " << _side << " creata" << std::endl;
}

Face::~Face() {
    for(int i = 0; i < 3; i++){
        delete _1thRow[i];
        delete _2thRow[i];
        delete _3thRow[i];
    }
}

void Face::printFace() {
    std::cout << std::endl;
    std::cout << "Cube's Side: " << _side << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << _1thRow[i]->getColor(); 
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << _2thRow[i]->getColor();
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << _3thRow[i]->getColor();
    }
}

void Face::change1thRow(Square **row) {
    //Square _temp[3] = *_1thRow;
    //_1thRow = row;

    std::cout <<  std::typeof(_1thRow) << std::typeof(row) << std::endl;
}

Square **Face::getRow(int index){
    if (index == 1)
        return this->_1thRow;
    else
        return this->_3thRow;
}