//
// Created by Sahil Khairnar on 20-11-2022.
//

#include <bits/stdc++.h>
#include "RubiksCube.h"
using namespace std;

class RubiksCube1DArray : public RubiksCube{
private :
    static int getflatindex(int face, int row, int col){
        return (face*9 + row*3 + col);
    }

    void rotateface(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getflatindex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getflatindex(ind, 0, i)] = temp_arr[getflatindex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(ind, i, 2)] = temp_arr[getflatindex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(ind, 2, 2 - i)] = temp_arr[getflatindex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(ind, 2 - i, 0)] = temp_arr[getflatindex(0, 2, 2 - i)];
    }

public :
    char cube[54]{};

    RubiksCube1DArray(){
        for(int i=0 ; i<6 ; i++){
            for(int j=0 ; j<3 ; j++){
                for(int k=0 ; k<3 ; k++){
                    cube[getflatindex(i,j,k)] = getcolorletter(COLOR(i));
                }
            }
        }
    }

    char getcolor(FACE face, int row, int col) const override{
        char color = cube[getflatindex((int)face,row,col)];
    }

    bool issolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[getflatindex(i, j, k)] != getcolorletter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateface(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(4, 0, 2 - i)] = cube[getflatindex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(1, 0, 2 - i)] = cube[getflatindex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(2, 0, 2 - i)] = cube[getflatindex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }

    RubiksCube &uprime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override {
        this->rotateface(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(0, i, 0)] = cube[getflatindex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(4, 2 - i, 2)] = cube[getflatindex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(5, i, 0)] = cube[getflatindex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &lprime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateface(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(0, 2, i)] = cube[getflatindex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(1, 2 - i, 2)] = cube[getflatindex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(5, 0, 2 - i)] = cube[getflatindex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &fprime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateface(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(0, 2 - i, 2)] = cube[getflatindex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(2, 2 - i, 2)] = cube[getflatindex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(5, 2 - i, 2)] = cube[getflatindex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &rprime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateface(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(0, 0, 2 - i)] = cube[getflatindex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getflatindex(3, 2 - i, 2)] = cube[getflatindex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(5, 2, i)] = cube[getflatindex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getflatindex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &bprime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateface(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getflatindex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(2, 2, i)] = cube[getflatindex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(1, 2, i)] = cube[getflatindex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(4, 2, i)] = cube[getflatindex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getflatindex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubiksCube &dprime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

};
