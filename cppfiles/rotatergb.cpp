#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;



unsigned char image[SIZE][SIZE][RGB];
unsigned char result[SIZE][SIZE][RGB];



void rotate(){
    int choice;
    cout<<"please enter the orentation that you want:";
    cin>>choice;
    switch (choice) {
        case 90: {
            for (int k = 0; k < RGB; ++k) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        result[j][i][k] = image[SIZE - i][j - 1][k];
                    }

                }
            }
            break;
        }

        case 180: {
            for (int k = 0; k < RGB; k++) {
                int row = 255;
                int column = 255;
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        result[row][column][k] = image[i][j][k];
                        column -= 1;
                        if (column == 0) {
                            row -= 1;
                        }
                    }
                }
            }
            break;
        }
        case 270: {
            for (int k = 0; k < RGB; ++k) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        result[j][i][k] = image[i][SIZE - (j - 1)][k];
                    }

                }
            }
            break;
        }
    }

}
void getimg(){
    char directory[100];
    cout<<"enter the image u want to rotate:";
    cin>>directory;
    strcat(directory,".bmp");
    readRGBBMP(directory,image);
    // readRGBBMP(directory,rotated_image);
}
void saveimg() {
    char directory[100];
    cout << "enter what name do u want to save ur image with:";
    cin >> directory;
    strcat(directory, ".bmp");
    writeRGBBMP(directory, result);


}

int main() {

    getimg();
    rotate();
    saveimg();

}