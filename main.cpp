#include <iostream>

//#include "Model/RubiksCube3DArray.cpp"
//#include "Model/RubiksCube1DArray.cpp"
#include "Model/RubiksCubeBitboard.cpp"
#include "Model/RubiksCube.h"

using namespace std;

int main() {

    RubiksCubeBitboard cubeobj;
    cubeobj.RubiksCube::print();
    vector<RubiksCube::MOVE> v;
    v = cubeobj.RubiksCube::randomshuffle(13);
    for(auto it : v){
        cout<< RubiksCube::getmove(it)<<" ";
    }
    cout<<endl;
    cubeobj.RubiksCube::print();


    return 0;
}
