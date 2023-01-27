#ifndef SQUARE_HPP
# define SQUARE_HPP

#define	FrontGreen "\e[0;32m G \e[0m"
#define	BackYellow "\e[0;33m Y \e[0m"	
#define	RightRed "\e[0;31m R \e[0m"	
#define LeftOrange "\033[38;5;214m O \e[0m"
#define	UpWhite "\e[0;37m W \e[0m"
#define	DownBlue "\e[0;34m B \e[0m"	

#include <iostream>


class Square {
    private:
        std::string _color;
    public:
        Square();
        Square(std::string color);
        ~Square();
        std::string getColor();
};

#endif