#ifndef FACE_HPP
# define FACE_HPP

#define	FrontGreen "\e[0;32m G \e[0m"
#define	BackBlue "\e[0;34m B \e[0m"
#define	RightRed "\e[0;31m R \e[0m"	
#define LeftOrange "\033[38;5;214m O \e[0m"
#define	UpWhite "\e[0;37m W \e[0m"
#define	DownYellow "\e[0;33m Y \e[0m"

#include <iostream>
#include <vector>
#include "square.hpp"

class Face {
    private:
        Face();
        
        std::string _side;

    
    public:
        std::vector<Square *> unoFila;
        std::vector<Square *> dueFila;
        std::vector<Square *> treFila;
        
        Face(std::string side, std::string color);
        ~Face();
        void printFace();
        void swapRow(int i, std::vector<Square *> & rowToSwap);
        void swapColumn(int i, std::vector<Square *> * column);
        void swapColumnWithRow(bool clockwise, std::vector<Square *> * column);
        void swapColumnWithRow(bool clockwise, std::vector<Square *> & rowToSwap);
        void autoRotate(bool clockwise);
        std::string getSide(){ return _side; }
        std::vector<Square *> & getRow(int index);
        std::vector<Square *> * getColumn(int index);
};

#endif