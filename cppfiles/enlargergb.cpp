#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to enlarge:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image2);
}

void enlarge(){
    int quarter;
    cout<<"please enter the quarter u want to enlarge:";
    cin>>quarter;
    for (int k =0 ; k<RGB; k++){
        for (int i = 0; i < SIZE; i+=2){
            for (int j =0; j<SIZE;j+=2){
                if (quarter==1){
                    image[i][j][k]=image2[i/2][j/2][k];
                    image[i][j+1][k]=image2[i/2][j/2][k];
                    image[i+1][j][k]=image2[i/2][j/2][k];
                    image[i+1][j+1][k]=image2[i/2][j/2][k];
                }else if (quarter==2){
                    image[i][j][k]=image2[i/2][(j+SIZE)/2][k];
                    image[i][j+1][k]=image2[i/2][(j+SIZE)/2][k];
                    image[i+1][j][k]=image2[i/2][(j+SIZE)/2][k];
                    image[i+1][j+1][k]=image2[i/2][(j+SIZE)/2][k];
                }else if (quarter==3){
                    image[i][j][k]=image2[(i+SIZE)/2][j/2][k];
                    image[i][j+1][k]=image2[(i+SIZE)/2][j/2][k];
                    image[i+1][j][k]=image2[(i+SIZE)/2][j/2][k];
                    image[i+1][j+1][k]=image2[(i+SIZE)/2][j/2][k];
                }else if (quarter==4){
                    image[i][j][k]=image2[(i+SIZE)/2][(j+SIZE)/2][k];
                    image[i][j+1][k]=image2[(i+SIZE)/2][(j+SIZE)/2][k];
                    image[i+1][j][k]=image2[(i+SIZE)/2][(j+SIZE)/2][k];
                    image[i+1][j+1][k]=image2[(i+SIZE)/2][(j+SIZE)/2][k];
                }
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
    enlarge();
    saveimg();

}