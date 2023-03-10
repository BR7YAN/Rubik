#ifndef CUBE_HPP
# define CUBE_HPP

#define	FrontGreen "\e[0;32m G \e[0m"
#define	BackBlue "\e[0;34m B \e[0m"
#define	RightRed "\e[0;31m R \e[0m"	
#define LeftOrange "\033[38;5;214m O \e[0m"
#define	UpWhite "\e[0;37m W \e[0m"
#define	DownYellow "\e[0;33m Y \e[0m"	

#include <iostream>
#include <map>
#include "face.hpp"

class Cube {
    private:
        std::map<std::string, Face *> _arrFace;
        typedef std::map<std::string, Face *>::iterator	face_iter;
        void    deleteFaces();
    public:
        Cube();
        ~Cube();
        void printFace(std::string color);
        void printMe();
        void upClockwise();
        void downClockwise();
        void rightClockWise();
        void leftClockWise();
        void frontClockWise();
        void backClockWise();
};

#endif