#ifndef FACE_HPP
# define FACE_HPP

#define	FrontGreen "\e[0;32m G \e[0m"
#define	BackYellow "\e[0;33m Y \e[0m"	
#define	RightRed "\e[0;31m R \e[0m"	
#define LeftOrange "\033[38;5;214m O \e[0m"
#define	UpWhite "\e[0;37m W \e[0m"
#define	DownBlue "\e[0;34m B \e[0m"	

#include <iostream>
#include <vector>
#include "square.hpp"

class Face {
    private:
        Face();
    public:
        Face(std::string side, std::string color);
        ~Face();
        void printFace();
        
        void change1thRow(Square **row);
        Square **getRow(int index);

        std::string _side;
        Square** _1thRow;
        Square* _2thRow[3];
        Square* _3thRow[3];
};

#endif