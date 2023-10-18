#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to darken\\lighten:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
}

void darken_lighten(){
    int op;
    cout<<"do u want darken-->1 or lighten-->2:";
    cin>>op;
    for (int k = 0; k < RGB; k++)
    {
        switch (op)
        {
            case 1:{
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        if (image[i][j][k]<=70){
                            image[i][j][k]=image[i][j][k];
                        }
                        else{
                            image[i][j][k]=image[i][j][k]-40;
                        }
                    }
                }
                break;
            }
            case 2:{
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        if (image[i][j][k]>=220){
                            image[i][j][k]=image[i][j][k];
                        }
                        else{
                            image[i][j][k]=image[i][j][k]+35;
                        }
                    }
                }
                break;
            }

            default:
                darken_lighten();
                break;
        }
    }

}

void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeRGBBMP(directory,image);
}

int main() {

    getimg();
    darken_lighten();
    saveimg();

}