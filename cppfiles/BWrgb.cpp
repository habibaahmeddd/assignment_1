
#include <iostream>
#include <cstring>
#include"bmplib.cpp"
using namespace std;
unsigned char Image[SIZE][SIZE][RGB];
unsigned char result[SIZE][SIZE][RGB];

void blackNwhite()
{
    int sum;
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum = 0;

            for (int k= 0; k < RGB; k++)
            {
                result[i][j][k] = Image[i][j][k];
                sum += result[i][j][k];
            }

            sum = sum/3;

            if (sum > 127) {
                for (int k = 0; k < RGB; k++) {
                    result[i][j][k] = 255;
                }
            }
            else {
                for (int k = 0; k < RGB; k++) {

                    result[i][j][k] = 0;
                }
            }

        }
    }
}




void loadImage()
{
    // intiliazing char to recieve file name from the user
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    //converting file taken from the user to bmp
    strcat(fileName, ".bmp");
    //reading file taken from the user
    readRGBBMP(fileName, Image);
}
void saveImage()
{
    //receiving the new filtered image file name from the user
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, result);
}
int main() {

    loadImage();
    blackNwhite();
    saveImage();

}