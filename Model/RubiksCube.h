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
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class MOVE{
        U,UPRIME,U2,
        F,FPRIME,F2,
        L,LPRIME,L2,
        R,RPRIME,R2,
        B,BPRIME,B2,
        D,DPRIME,D2
    };

    /*
    Returns a char initial of a colour of data type COLOR
    */
    static char getcolorletter(COLOR color);

    /*
     * Returns color of cubie(row,col) on a face
     */
    virtual char getcolor(FACE face, int row, int col) const = 0;

    /*
     * Prints the present config of cube
     */
    void print() const;

    /*
     * Returns true if the Cube is solved
     */
    virtual bool issolved() const = 0;

    /*
     * Returns the move in the string format.
     */
    static string getmove(MOVE ind);

    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
    vector<MOVE> randomshuffle(unsigned int times);

    /*
     * Perform moves on the Rubik Cube
     */
    RubiksCube &move(MOVE ind);

    /*
     * Invert a move
     */
    RubiksCube &invert(MOVE ind);

    /*
     All the 18 possible moves
     */
    virtual RubiksCube &u() = 0;
    virtual RubiksCube &uprime() = 0;
    virtual RubiksCube &u2() = 0;
    virtual RubiksCube &f() = 0;
    virtual RubiksCube &fprime() = 0;
    virtual RubiksCube &f2() = 0;
    virtual RubiksCube &r() = 0;
    virtual RubiksCube &rprime() = 0;
    virtual RubiksCube &r2() = 0;
    virtual RubiksCube &l() = 0;
    virtual RubiksCube &lprime() = 0;
    virtual RubiksCube &l2() = 0;
    virtual RubiksCube &b() = 0;
    virtual RubiksCube &bprime() = 0;
    virtual RubiksCube &b2() = 0;
    virtual RubiksCube &d() = 0;
    virtual RubiksCube &dprime() = 0;
    virtual RubiksCube &d2() = 0;


};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
