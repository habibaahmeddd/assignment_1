#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void getimg(){
    char directory[100];
    cout<<"enter the image u want to invert:";
    cin>>directory;
    strcat(directory,".bmp");
    readGSBMP(directory,image);
}

void invert(){
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int pixel = image[i][j];
            if (pixel>0 && pixel<255){
                image[i][j]=255-pixel;
            }
            else if (pixel==255)
            {
                image[i][j]=0;
            }
            else if(pixel==0){
                image[i][j]=255+pixel;
            }
        }

    }

}
void saveimg(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeGSBMP(directory,image);
}

int main() {

    getimg();
    invert();
    saveimg();

}

