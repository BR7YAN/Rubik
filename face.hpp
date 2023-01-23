#ifndef FACE_HPP
# define FACE_HPP

#include <iostream>
#include "square.hpp"

class Face {
    private:
        Face();
        //Square _1th_row[3];
        //Square _2th_row[3];
        //Square _3th_row[3];
    public:
        Face(std::string color);
        ~Face();
};

#endif