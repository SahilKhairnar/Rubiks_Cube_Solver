//
// Created by Sahil Khairnar on 17-11-2022.
//

#include "RubiksCube.h"

/*
This returns a char initial of a colour of data type COLOR
*/

char RubiksCube::getcolorletter(COLOR color){
    switch (color) {
        case COLOR::B:return 'B';
        case COLOR::W:return 'W';
        case COLOR::O:return 'O';
        case COLOR::Y:return 'Y';
        case COLOR::G:return 'G';
        case COLOR::R:return 'R';
    }
}

