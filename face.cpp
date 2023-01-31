#include "face.hpp"

Face::Face() {
    std::cout << "Faccia creata" << std::endl;
}

Face::Face(std::string side, std::string color): _side(side){
    for(int i = 0; i < 3; i++){
        unoFila.push_back(new Square(color));
        dueFila.push_back(new Square(color));
        treFila.push_back(new Square(color));
    }
}

Face::~Face() {
    for(int i = 0; i < 3; i++){
        delete unoFila[i];
        delete dueFila[i];
        delete treFila[i];
    }
}

void Face::printFace() {
    std::cout << std::endl;
    std::cout << "Cube's Side: " << _side << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << unoFila[i]->getColor(); 
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << dueFila[i]->getColor();
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << treFila[i]->getColor();
    }
}

void Face::swapRow(int i, std::vector<Square *> & rowToSwap) {
    if (i == 1)
        this->unoFila.swap(rowToSwap);
    else if (i == 3)
        this->treFila.swap(rowToSwap);
}

void Face::swapColumn(int i, std::vector<Square *> *column) {
    if (i == 1) {
        std::swap(unoFila[0], (*column)[0]);
        std::swap(dueFila[0], (*column)[1]);
        std::swap(treFila[0], (*column)[2]);
    }
    else {
        std::swap(unoFila[2], (*column)[0]);
        std::swap(dueFila[2], (*column)[1]);
        std::swap(treFila[2], (*column)[2]);
    }
}

void Face::autoRotate(bool clockwise) {
    if (clockwise){
        //angoli
        std::swap(treFila[0], treFila[2]);
        std::swap(treFila[2], unoFila[2]);
        std::swap(unoFila[2], unoFila[0]);
        //medi
        std::swap(treFila[1], dueFila[2]);
        std::swap(dueFila[2], unoFila[1]);
        std::swap(unoFila[1], dueFila[0]);
    }
    else {
        //angoli
        std::swap(treFila[0], unoFila[0]);
        std::swap(unoFila[0], unoFila[2]);
        std::swap(unoFila[2], treFila[2]);
        //medi
        std::swap(treFila[1], dueFila[0]);
        std::swap(dueFila[0], unoFila[1]);
        std::swap(unoFila[1], dueFila[2]);
    }
}

std::vector<Square *> & Face::getRow(int index){
    if (index == 1)
        return this->unoFila;
    else
        return this->treFila;
}

std::vector<Square *> * Face::getColumn(int index){
    if (index == 1) {
        std::vector<Square *> *ret = new std::vector<Square *>;
        ret->push_back(this->unoFila[0]);
        ret->push_back(this->dueFila[0]);
        ret->push_back(this->treFila[0]);
        return ret;
    }
    else {
        std::vector<Square *> *ret = new std::vector<Square *>;
        ret->push_back(this->unoFila[2]);
        ret->push_back(this->dueFila[2]);
        ret->push_back(this->treFila[2]);
        return ret;
    }
}