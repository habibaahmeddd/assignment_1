#include <iostream>
#include <cstring>
#include"bmplib.cpp"

using namespace std;
unsigned char Image[SIZE][SIZE][RGB];
char filteredImage[SIZE][SIZE][RGB];

void loadImage()
{
    char fileName[100];
    cout << "Enter the source image file name: ";
    cin >> fileName;
    strcat(fileName, ".bmp");
    readRGBBMP(fileName, Image);
}
void flipImage()
{
    char choice;
    cout << "Press (h) to flip horizontally , (v) to flip vertically " << endl;
    cin >> choice;
    if (choice == 'h')
    {
        for(int k = 0 ; k < RGB ; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    filteredImage[i][j][k] = Image[SIZE - i][SIZE - j][k];
                }

            }
        }
    }
    else if (choice == 'v')
    {
        for(int k = 0 ; k < RGB ; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    filteredImage[j][i][k] = Image[j][SIZE - i][k];

                }
            }
        }
    }
    for(int k = 0 ; k < RGB ; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                Image[i][j][k] = filteredImage[i][j][k];
            }
        }
    }
}
void saveImage()
{
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, Image);
}

int main() {

    loadImage();
    flipImage();
    saveImage();

}