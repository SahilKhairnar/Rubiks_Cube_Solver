//
// Created by Sahil Khairnar on 17-11-2022.
//

#include "RubiksCube.h"

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

string RubiksCube::getmove(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }
}

vector<RubiksCube::MOVE> RubiksCube::randomshuffle(unsigned int times){
    vector<MOVE> movesperformed;
    srand(time(0));
    for(int i=0 ; i<times ; i++){
        int _move = (rand()%18);
        movesperformed.push_back(static_cast<MOVE>(_move));
        this->move(static_cast<MOVE>(_move));
    }
    return movesperformed;
}

RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lprime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rprime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uprime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dprime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fprime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bprime();
        case MOVE::B2:
            return this->b2();
    }
}

RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lprime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rprime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uprime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dprime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fprime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bprime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void RubiksCube::print() const{
    cout << "Rubiks Cube is : " << endl<<endl;

    // Top face
    for(int k=0 ; k<3 ; k++){
        for(int i=0 ; i<7 ; i++) cout<< " ";
            for(int j=0 ; j<3 ; j++){
                cout << getcolor(RubiksCube::FACE::UP ,k,j)<<" ";
            }
        cout<<endl;
    }

    // Middle four faces
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cout<< getcolor(FACE::LEFT,i,j)<<" ";
        } cout<<" ";
        for(int j=0 ; j<3 ; j++){
            cout<< getcolor(FACE::FRONT,i,j)<<" ";
        } cout<<" ";
        for(int j=0 ; j<3 ; j++){
            cout<< getcolor(FACE::RIGHT,i,j)<<" ";
        } cout<<" ";
        for(int j=0 ; j<3 ; j++){
            cout<< getcolor(FACE::BACK,i,j)<<" ";
        }
        cout<<endl;
    }

    // Bottom face
    for(int k=0 ; k<3 ; k++){
        for(int i=0 ; i<7 ; i++) cout<< " ";
        for(int j=0 ; j<3 ; j++){
            cout << getcolor(RubiksCube::FACE::DOWN ,k,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

