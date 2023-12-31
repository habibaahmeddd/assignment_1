#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to blur:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
}

void blur(){
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                image[i+1][j+1][k]=(image[i][j][k]+image[i][j+1][k]+image[i][j+2][k]+image[i+1][j][k]+image[i+1][j+1][k]+image[i+1][j+2][k]+image[i+2][j][k]+image[i+2][j+1][k]+image[i+2][j+2][k])/9;
            }
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
    blur();
    saveimg();
}