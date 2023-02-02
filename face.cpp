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
        // std::cout << unoFila[i]->getColor() << std::endl;
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

//Continuando a fare 3 swap invece di 4, la variabile clockwise qui si
//riferisce alla rotazione dello swap e non della faccia del cubo
//Per esempio se facciamo il movimento F clockwise, la variabile clockwise
//assumera il valore di false in quanto stiamo facendo lo swap tra la
//3 riga della faccia UP e la 3 colonna della faccia left
void Face::swapColumnWithRow(bool clockwise, std::vector<Square *> *column) {
    if (clockwise) {
        std::swap(unoFila[2], (*column)[0]);
        std::swap(unoFila[1], (*column)[1]);
        std::swap(unoFila[0], (*column)[2]);
    }
    else {
        std::cout  << unoFila[0] << std::endl;
        std::cout  << (*column)[0] << std::endl;
        
        std::cout  << unoFila[0]->getColor() << std::endl;
        std::cout  << (*column)[0]->getColor() << std::endl;

        Square * element0 = (*column)[0];
        Square * element1 = (*column)[1];
        Square * element2 = (*column)[2];

        (*column)[0] = unoFila[0];
        (*column)[1] = unoFila[1];
        (*column)[2] = unoFila[2];

        *unoFila[0] = *element0;
        *unoFila[1] = *element1;
        *unoFila[2] = *element2;

        // std::swap(unoFila[0], (*column)[0]);
        // std::swap(unoFila[1], (*column)[1]);
        // std::swap(unoFila[2], (*column)[2]);

        std::cout  << unoFila[0]->getColor() << std::endl;
        std::cout  << (*column)[0]->getColor() << std::endl;

        std::cout  << unoFila[0] << std::endl;
        std::cout  << (*column)[0] << std::endl;
    }
}

void Face::swapColumnWithRow(bool clockwise, std::vector<Square *> & rowToSwap) {
    if (clockwise) {
        std::swap(unoFila[0], rowToSwap[0]);
        std::swap(dueFila[0], rowToSwap[1]);
        std::swap(treFila[0], rowToSwap[2]);
    }
    else {
        std::swap(unoFila[2], rowToSwap[2]);
        std::swap(dueFila[2], rowToSwap[1]);
        std::swap(treFila[2], rowToSwap[0]);
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