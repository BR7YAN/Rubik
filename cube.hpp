#ifndef CUBE_HPP
# define CUBE_HPP

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
};

#endif