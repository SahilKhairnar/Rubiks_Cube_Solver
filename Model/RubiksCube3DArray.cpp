//
// Created by Sahil Khairnar on 18-11-2022.
//

#include "RubiksCube.h"

using namespace std;

class RubiksCube3DArray : public RubiksCube {
private :

public :
    char cube[6][3][3]{};

    RubiksCube3DArray(){
        //cout<<"i m here"<<endl;
        for(int i=0 ; i<6 ; i++){
            for(int j=0 ; j<3 ; j++){
                for(int k=0 ; k<3 ; k++){
                    cube[i][j][k] = getcolorletter(COLOR(i));
                    //cube[i][j][k] = 'A';
                    //cout<<i<<j<<k<<endl;
                }
            }
        }
    }



    void print() const override {
        cout<< "The cube is "<<endl<<endl;
        for(int k=0 ; k<3 ; k++){
            for(int i=0 ; i<7 ; i++) cout<< " ";
            for(int j=0 ; j<3 ; j++){
                cout << cube[0][k][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0 ; i<3 ; i++){
            for(int j=1 ; j<=4 ; j++){
                for(int k=0 ; k<3 ; k++){
                    cout<< cube[j][i][k] << " ";
                }
                cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0 ; i<3 ; i++){
            for(int z=0 ; z<7 ; z++) cout<< " ";
            for(int j=0 ; j<3 ; j++){
                cout<< cube[5][i][j]<< " ";
            }
            cout<<endl;
        }
        cout<<endl;

    }

};
