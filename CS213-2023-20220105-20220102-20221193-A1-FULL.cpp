// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:CS213-2023-20220105-20220102-20221193-A1-FULL.cpp
// Last Modification Date:	19/10/2023
// Author1 and ID and Group:	Habiba Amr - 20220105
// Author2 and ID and Group:	Habiba Ahmed - 20220102
// Author3 and ID and Group:	Hana Mohamed - 20221193
// Teaching Assistant:	Sections haven't started yet
// Purpose: Grey scale photoshop program

#include <iostream>
#include <bits/stdc++.h>
#include "cmath"
#include "bmplib.cpp"

using namespace std;

// intiliazing Unsigned char for the image and char to save the new filtered image

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
char filteredImage[SIZE][SIZE];
unsigned char New[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];


void loadImage();
void load2();

void saveImage();

void blackAndAWhiteFilter();
void invertImage();
void mergeImage();
void flipImage();
void rotateImage();
void darkenAndLightenFilter();
void DetectImageEdges();
void enlarge();
void shrink();
void Mirror();
void shuffle();
void blur();
void crop();
void skew_horizontal();
void skew_vertical();

int main(){

    int choice;
    loadImage();
    cout << "choose 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15";
    cin >> choice;
    switch (choice) {
        case 1: {
            blackAndAWhiteFilter();
            saveImage();
            break;
        }
        case 2: {
            invertImage();
            saveImage();
            break;
        }
        case 3: {
            mergeImage();
            saveImage();
            break;
        }
        case 4: {
            flipImage();
            saveImage();
            break;
        }
        case 5: {
            rotateImage();
            saveImage();
            break;
        }
        case 6: {
            darkenAndLightenFilter();
            saveImage();
            break;
        }
        case 7: {
            DetectImageEdges();
            saveImage();break;
        }
        case 8:{
            enlarge();
            saveImage();break;
    }
    case 9:{
        shrink();
        saveImage();break;
    }
    case 10:{
        Mirror();
        saveImage();break;
    }
    case 11:{
        shuffle();
        saveImage();break;
    }
    case 12:{
        blur();
        saveImage();break;
    }case 13:{
        crop();
        saveImage();break;
    }case 14:{
        skew_horizontal();
        saveImage();break;
    }case 15:{
        skew_vertical();
        saveImage();break;
    }
    }
}

//recieving image from the user
void loadImage()
{

    // intiliazing char to recieve file name from the user

    char imageFileName[100];

    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    //converting file taken from the user to bmp

    strcat(imageFileName, ".bmp");

    //reading file taken from the user

    readGSBMP(imageFileName, image);
}

void load2() {
    char image[100];
    cout << "enter the image u want to merge:";
    cin >> image;
    strcat(image, ".bmp");
    readGSBMP(image, image2);
}

//saving the new filtered image
void saveImage() {
    //receiving the new filtered image file name from the user
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//Filter no (1) Black and white filter
void blackAndAWhiteFilter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //scaling up every bit more than 127 to 255(white)

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                //scalling down every bit less than 127 to 0(black)
                image[i][j] = 0;
        }
    }
}
//Filter no (2) Invert filter
void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}
//Filter no (3) Merge filter
void mergeImage() {
    load2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}

//Filter no (4) flip filter

void flipImage() {
    char choice;
    cout << "Press (h) to flip horizontally , (v) to flip vertically " << endl;
    cin >> choice;
    if (choice == 'h') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                filteredImage[i][j] = image[SIZE - i][SIZE - j];
            }
        }
    } else if (choice == 'v') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                filteredImage[j][i] = image[j][SIZE - i];

            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = filteredImage[i][j];
        }
    }
}
//Filter no (5) rotate filter

void rotateImage() {
    int degree;
    cin >> degree;
    if (degree == 90) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                filteredImage[i][j] = image[j][i];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = filteredImage[i][SIZE - j];
            }
        }
    } else if (degree == 180) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                filteredImage[i][j] = image[SIZE - i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = filteredImage[i][SIZE - j];
            }
        }
    } else if (degree == 270) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                filteredImage[i][j] = image[j][i];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = filteredImage[SIZE - i][j];
            }
        }
    }


}
//Filter no (6) darkenAndLightenFilter

void darkenAndLightenFilter() {
    int check;
    cout << "do u want darken-->1 or lighten-->2:";
    cin >> check;
    switch (check) {
        case 1: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image[i][j] < 60) {
                        image[i][j] = image[i][j];
                    } else {
                        image[i][j] = image[i][j] * 0.5;
                    }
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image[i][j] >= 195) {
                        image[i][j] = image[i][j];
                    } else {
                        image[i][j] = (image[i][j] + 60);
                    }
                }
            }
            break;
        }

        default:
            darkenAndLightenFilter();
            break;
    }
}
//Filter no (7) DetectImageEdges filter

void DetectImageEdges()
{
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 1; i < SIZE - 1; i += 1) {
        for (int j = 1; j < SIZE - 1; j += 1) {
            if (image[i][j] == image[i][j + 1] and image[i][j] == image[i][j - 1])
                New[i][j] = 255;
            else
                New[i][j] = 0;
        }
    }
}
//Filter no (8) enlarge filter

void enlarge(){
    int quarter;
    cout<<"please enter the quarter u want to enlarge:";
    cin>>quarter;
    for (int i = 0; i < SIZE; i+=2){
        for (int j =0; j<SIZE;j+=2){
            if (quarter==1){
                image[i][j]=newimage[i/2][j/2];
                image[i][j+1]=newimage[i/2][j/2];
                image[i+1][j]=newimage[i/2][j/2];
                image[i+1][j+1]=newimage[i/2][j/2];
            }else if (quarter==2){
                image[i][j]=newimage[i/2][(j+SIZE)/2];
                image[i][j+1]=newimage[i/2][(j+SIZE)/2];
                image[i+1][j]=newimage[i/2][(j+SIZE)/2];
                image[i+1][j+1]=newimage[i/2][(j+SIZE)/2];
            }else if (quarter==3){
                image[i][j]=newimage[(i+SIZE)/2][j/2];
                image[i][j+1]=newimage[(i+SIZE)/2][j/2];
                image[i+1][j]=newimage[(i+SIZE)/2][j/2];
                image[i+1][j+1]=newimage[(i+SIZE)/2][j/2];
            }else if (quarter==4){
                image[i][j]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i][j+1]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i+1][j]=newimage[(i+SIZE)/2][(j+SIZE)/2];
                image[i+1][j+1]=newimage[(i+SIZE)/2][(j+SIZE)/2];
            }
        }
    }
}
//Filter no (9) shrink filter

void shrink(){
    int choice;
    cout<<"for 1/4 ->1\nfor 1/3 ->2\nfor 1/2 ->3\nenter:" ;
    cin>>choice;
    if (choice==1){
        for (int i = 0; i < SIZE ; i+=2)
        {
            for (int j = 0; j < SIZE; j+=2)
            {
                image[i/2][j/2]=newimage[i][j];
            }

        }

    }else if (choice == 2)
    {
        for (int i = 0; i < SIZE; i+=3)
        { for (int j = 0; j < SIZE; j+=3)
            {
                image[i/3][j/3] = newimage[i][j];
            }
        }
    }else if (choice == 3)
    {
        for (int i = 0; i < SIZE; i+=4)
        { for (int j = 0; j < SIZE; j+=4)
            {
                image[i/4][j/4] = newimage[i][j];
            }
        }
    }
}
//Filter no (10) mirror filter

void Mirror() {
    char choice1, choice2;

    cout << "Choose whether you want to mirror the image horizontally (h) or vertically (v)" << endl;
    cin >> choice1;
    if (choice1 == 'v') {
        cout << "Choose either the left part (l) or the right part (r)" << endl;
        cin >> choice2;
        if (choice2 == 'l') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image[i][j];
                    //check if first half
                    if (j < SIZE / 2)
                        image[i][SIZE - j] = temp;
                    else
                        image[i][j] = image[i][SIZE - j];

                }
            }
        }
        if (choice2 == 'r') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image[i][j];
                    // check if second half
                    if (j > SIZE / 2)
                        image[i][SIZE - j] = temp;
                    else
                        image[i][j] = image[i][SIZE - j];

                }
            }
        }

    }
    if (choice1 == 'h') {
        cout << "Choose either the upper part (u) or the lower part (l)" << endl;
        cin >> choice2;
        if (choice2 == 'u') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int temp = image[i][j];
                    // check if first half
                    if (i < SIZE / 2)
                        image[SIZE - i][j] = temp;
                    else
                        image[i][j] = image[SIZE - i][j];
                }
            }
        }
        if (choice2 == 'l') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int temp = image[i][j];
                    // check if second half
                    if (i > SIZE / 2)
                        image[SIZE - i][j] = temp;
                    else
                        image[i][j] = image[SIZE - i][j];
                }
            }
        }

    }
}
//Filter no (11) shuffle filter

void shuffle(){
    int index =0;
    string order;
    cout<<"enter the order";
    cin>>order;
    while (index<4){
        if (index==0){
            if (order[index]=='1'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j]=newimage[i][j];
                    }
                }

            }else if (order[index]=='2'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j]=newimage[i][j+SIZE/2];
                    }
                }
            }else if (order[index]=='3'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j]=newimage[i+SIZE/2][j];
                    }

                }
            }else if (order[index]=='4'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j]=newimage[i+SIZE/2][j+SIZE/2];
                    }

                }
            }
        }

        else if (index ==1){
            if (order[index]=='1'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j+SIZE/2]=newimage[i][j];
                    }

                }

            }else if (order[index]=='2'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j+SIZE/2]=newimage[i][j+SIZE/2];
                    }

                }
            }else if (order[index]=='3'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j+SIZE/2]=newimage[i+SIZE/2][j];
                    }

                }
            }else if (order[index]=='4'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i][j+SIZE/2]=newimage[i+SIZE/2][j+SIZE/2];
                    }

                }
            }
        }

        else if (index==2){
            if (order[index]=='1'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j]=newimage[i][j];
                    }

                }

            }else if (order[index]=='2'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j]=newimage[i][j+SIZE/2];
                    }

                }
            }else if (order[index]=='3'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j]=newimage[i+SIZE/2][j];
                    }

                }
            }else if (order[index]=='4'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j]=newimage[i+SIZE/2][j+SIZE/2];
                    }

                }
            }
        }
        else if (index ==3){
            if (order[index]=='1'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j+SIZE/2]=newimage[i][j];
                    }

                }
            }else if (order[index]=='2'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j+SIZE/2]=newimage[i][j+SIZE/2];
                    }

                }
            }else if (order[index]=='3'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j+SIZE/2]=newimage[i+SIZE/2][j];
                    }

                }
            }else if (order[index]=='4'){
                for (int i = 0; i < SIZE/2; i++){
                    for (int j = 0; j < SIZE/2; j++){
                        image[i+SIZE/2][j+SIZE/2]=newimage[i+SIZE/2][j+SIZE/2];
                    }

                }
            }
        }
        index++;
    }

}
//Filter no (12) blur filter

void blur(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i+1][j+1]=(image[i][j]+image[i][j+1]+image[i][j+2]+image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+2][j]+image[i+2][j+1]+image[i+2][j+2])/9;
        }
    }
}

void crop() {
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = 255;

        }
    }
    for (int i = 220; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = 255;
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 36; j++) {
            image[i][j] = 255;

        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 220; j < 256; j++) {
            image[i][j] = 255;
        }
    }
}

void skew_horizontal(){
   cout << "Enter Skew angle: ";
    double angle;
    cin >> angle;
    unsigned char tmp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tmp[i][j] = 255;
        }
    }

    double l = tan(angle * 3.14 / 180.0) * SIZE;
    double cmprs = SIZE / (SIZE - l);
    double step = l / 256;
    double taken = 0;
    for (int i = 0; i < SIZE; i++) {
        double current = 0;
        for (int j = l
 - taken; j < SIZE - taken; j++) {
            int average = 0;
            int px = 0;
            for (int k = max(0, (int) ceil(current - cmprs)); k < min(SIZE, (int) ceil(current + cmprs)); k++, ++px) {
                average += image1[i][k];
            }
            average /= max(1, px);
            tmp[i][j] = average;
            current += cmprs;
        }
        taken += step;
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image1[i][j] = tmp[i][j];

}
void skew_vertical() {
    cout << "Enter Skew angle: ";
    double angle;
    cin >> angle;
    unsigned char tmp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tmp[i][j] = 255;
        }
    }

    double l = tan(angle * 3.14 / 180.0) * SIZE;
    double cmprs = SIZE / (SIZE - l);
    double step = l / 256;
    double taken = 0;
    for (int j = 0; j < SIZE; j++) {
        double current = 0;
        for (int i = l
 - taken; i < SIZE - taken; i++) {
            int average = 0;
            int px = 0;
            for (int k = max(0, (int) ceil(current - cmprs)); k < min(SIZE, (int) ceil(current + cmprs)); k++, ++px) {
                average += image1[k][j];
            }
            average /= max(1, px);
            tmp[i][j] = average;
            current += cmprs;
        }
        taken += step;
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image1[i][j] = tmp[i][j];
}