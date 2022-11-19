//
// Created by Sahil Khairnar on 17-11-2022.
//
#include <bits/stdc++.h>

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
using namespace std;

class RubiksCube {
public:

    enum class COLOR{
        W,
        G,
        R,
        B,
        O,
        Y
    };

    char getcolorletter(COLOR color);

    virtual void print() const = 0;


};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
