//Habiba Amr - 20220105 - haibaewiss5@gmail.com
//Habiba Ahmed - 20220102 - habibaahmedd88@gmail.com
//Hana Mohamed - 20221193 - hna27816@gmail.com

#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;

// intiliazing Unsigned char for the image and char to save the new filtered image
unsigned char Image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char result[SIZE][SIZE][RGB];
char filteredImage[SIZE][SIZE][RGB];




void loadImage();
void load2();

void saveImage();
void saveing();

void blackNwhite();
void invert();
void merge();
void flipImage();
void rotate();
void darken_lighten();
void EDGING();
void enlarge();
void shrink ();
void Mirror();
void shuffle();
void blur();

int main(){

    int choice;
    loadImage();
    cout << "choose 123456789abcdef";
    cin >> choice;
    switch (choice) {
        case 1: {
            blackNwhite();
            saveImage();
            break;
        }
        case 2: {
            invert();
            saveing();
            break;
        }
        case 3: {
            load2();
            merge();
            saveing();
            break;
        }
        case 4: {
            flipImage();
            saveing();
            break;
        }
        case 5: {
            rotate();
            saveImage();
            break;
        }
        case 6: {
            darken_lighten();
            saveing();
            break;
        }
        case 7: {
            EDGING();
            saveImage();
            break;
        }
        case 8: {
            enlarge();
            saveImage();
            break;
        }
        case 9: {
            shrink();
            saveImage();
            break;

        }
        case 10: {
            Mirror();
            saveing();
            break;
        }
        case 11: {
            load2();
            shuffle();
            saveing();
            break;
        }
        case 12: {
            blur();
            saveing();
            break;
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

    readRGBBMP(imageFileName, Image);
}

void load2() {
    char image[100];
    cout << "enter the image u want to merge:";
    cin >> image;
    strcat(image, ".bmp");
    readRGBBMP(image, image2);
}


//saving the new filtered image
void saveImage() {
    //receiving the new filtered image file name from the user
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, result);
}


void saveing(){
    char directory[100];
    cout<<"enter what name do u want to save ur image with:";
    cin>>directory;
    strcat(directory,".bmp");
    writeRGBBMP(directory,Image);
}

//Filter no (1) Black and white filter
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
//Filter no (2) Invert filter
void invert() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; k++) {
                Image[i][j][k] = 255 - Image[i][j][k];
            }

        }

    }

}
//filter no (3) Merge filter
void merge(){
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                Image[i][j][k]= (Image [i][j][k] + image2[i][j][k]) /2;
            }
        }
    }

}

//Filter no (4) flip filter

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
//Filter no (5) rotate filter
void rotate(){
    int choice;
    cout<<"please enter the orentation that you want:";
    cin>>choice;
    switch (choice) {
        case 90: {
            for (int k = 0; k < RGB; ++k) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        result[j][i][k] = Image[SIZE - i][j - 1][k];
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
                        result[row][column][k] = Image[i][j][k];
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
                        result[j][i][k] = Image[i][SIZE - (j - 1)][k];
                    }

                }
            }
            break;
        }
    }

}


//Filter no (6) darkenAndLightenFilter

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
                        if (Image[i][j][k]<=70){
                            Image[i][j][k]=Image[i][j][k];
                        }
                        else{
                            Image[i][j][k]=Image[i][j][k]-40;
                        }
                    }
                }
                break;
            }
            case 2:{
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        if (Image[i][j][k]>=220){
                            Image[i][j][k]=Image[i][j][k];
                        }
                        else{
                            Image[i][j][k]=Image[i][j][k]+35;
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

//Filter no (7) DetectImageEdges filter

void EDGING()
{
    //1- convert greyscale to black and white
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 1; i < SIZE - 1; i++)
        {
            for (int j = 1; j < SIZE - 1; j++)
            {
                //convert to black and white
                if (Image[i][j][k] > 127)
                    Image[i][j][k] = 255;
                else
                    Image[i][j][k] = 0;
            }
        }
    }
    for (int k = 0; k < RGB; k++) {
        for (int i = 1; i < SIZE - 1; i += 1)
        {
            for (int j = 1; j < SIZE - 1; j += 1)
            {
                //2- check detection of current pixel against before/after pixels
                if (Image[i][j][k] == Image[i][j + 1][k] and Image[i][j][k] == Image[i][j - 1][k])
                    //set value to white
                    result[i][j][k] = 255;
                else
                    //set value to black
                    result[i][j][k] = 0;
            }
        }
    }
}
//Filter no (8) enlarge filter

void enlarge(){
    int quarter;
    cout<<"please enter the quarter u want to enlarge:";
    cin>>quarter;
    for (int k =0 ; k<RGB; k++){
        for (int i = 0; i < SIZE; i+=2){
            for (int j =0; j<SIZE;j+=2){
                if (quarter==1){
                    Image[i][j][k]=result[i/2][j/2][k];
                    Image[i][j+1][k]=result[i/2][j/2][k];
                    Image[i+1][j][k]=result[i/2][j/2][k];
                    Image[i+1][j+1][k]=result[i/2][j/2][k];
                }else if (quarter==2){
                    Image[i][j][k]=result[i/2][(j+SIZE)/2][k];
                    Image[i][j+1][k]=result[i/2][(j+SIZE)/2][k];
                    Image[i+1][j][k]=result[i/2][(j+SIZE)/2][k];
                    Image[i+1][j+1][k]=result[i/2][(j+SIZE)/2][k];
                }else if (quarter==3){
                    Image[i][j][k]=result[(i+SIZE)/2][j/2][k];
                    Image[i][j+1][k]=result[(i+SIZE)/2][j/2][k];
                    Image[i+1][j][k]=result[(i+SIZE)/2][j/2][k];
                    Image[i+1][j+1][k]=result[(i+SIZE)/2][j/2][k];
                }else if (quarter==4){
                    Image[i][j][k]=result[(i+SIZE)/2][(j+SIZE)/2][k];
                    Image[i][j+1][k]=result[(i+SIZE)/2][(j+SIZE)/2][k];
                    Image[i+1][j][k]=result[(i+SIZE)/2][(j+SIZE)/2][k];
                    Image[i+1][j+1][k]=result[(i+SIZE)/2][(j+SIZE)/2][k];
                }
            }
        }
    }

}
//Filter no (9) shrink filter

void shrink(){
    int choice;
    cout<<"for 1/4 ->1\nfor 1/3 ->2\nfor 1/2 ->3\nenter:" ;
    cin>>choice;
    for (int k = 0; k < RGB; k++)
    {
        if (choice==1){
            for (int i = 0; i < SIZE ; i+=2)
            {
                for (int j = 0; j < SIZE; j+=2)
                {
                    result[i/2][j/2][k]=Image[i][j][k];
                }

            }

        }else if (choice == 2)
        {
            for (int i = 0; i < SIZE; i+=3)
            { for (int j = 0; j < SIZE; j+=3)
                {
                    result[i/3][j/3][k] =Image[i][j][k];
                }
            }
        }else if (choice == 3)
        {
            for (int i = 0; i < SIZE; i+=4)
            { for (int j = 0; j < SIZE; j+=4)
                {
                    result[i/ 4][j/4][k] = Image[i][j][k];
                }
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
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE; i++) {
                    // half size of vertical mirror
                    for (int j = 0; j < SIZE / 2; j++) {
                        int temp =  Image[i][j][k];
                        //check if first half
                        if (j < SIZE / 2) {
                            Image[i][SIZE - j][k] = temp;
                        } else {
                            Image[i][j][k] = Image[i][SIZE - j][k];
                        }

                    }
                }
            }
        }
        if (choice2 == 'r') {
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE; i++) {
                    // half size of vertical mirror
                    for (int j = 0; j < SIZE / 2; j++) {
                        int temp = Image[i][j][k];
                        // check if second half
                        if (j > SIZE / 2) {
                            Image[i][SIZE - j][k] = temp;
                        } else {
                            Image[i][j][k] = Image[i][SIZE - j][k];
                        }

                    }
                }
            }

        }
    }
    if (choice1 == 'h') {
        cout << "Choose either the upper part (u) or the lower part (l)" << endl;
        cin >> choice2;
        if (choice2 == 'u') {
            // half size of horizontal mirror
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        int temp = Image[i][j][k];
                        // check if first half
                        if (i < SIZE / 2) {
                            Image[SIZE - i][j][k] = temp;
                        } else {
                            Image[i][j][k] = Image[SIZE - i][j][k];
                        }
                    }
                }
            }
        }
        if (choice2 == 'l') {
            // half size of horizontal mirror
            for (int k = 0; k < RGB; k++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        int temp = Image[i][j][k];
                        // check if second half
                        if (i > SIZE / 2) {
                            Image[SIZE - i][j][k] = temp;
                        } else {
                            Image[i][j][k] = Image[SIZE - i][j][k];
                        }
                    }
                }
            }

        }
    }
}
//Filter no (11) shuffle filter

void shuffle(){
    string order;
    cout<<"enter the order";
    cin>>order;
    int length = order.length();
    for (int k = 0; k < RGB; k++)
    {
        int index =0;
        while (index<4){
            if (index==0){
                if (order[index]=='1'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j][k]=image2[i][j][k];
                        }
                    }

                }else if (order[index]=='2'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j][k]=image2[i][j+SIZE/2][k];
                        }
                    }
                }else if (order[index]=='3'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j][k]=image2[i+SIZE/2][j][k];
                        }

                    }
                }else if (order[index]=='4'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j][k]=image2[i+SIZE/2][j+SIZE/2][k];
                        }

                    }
                }
            }
                // --------------------
            else if (index ==1){
                if (order[index]=='1'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j+SIZE/2][k]=image2[i][j][k];
                        }

                    }

                }else if (order[index]=='2'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j+SIZE/2][k]=image2[i][j+SIZE/2][k];
                        }

                    }
                }else if (order[index]=='3'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j+SIZE/2][k]=image2[i+SIZE/2][j][k];
                        }

                    }
                }else if (order[index]=='4'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i][j+SIZE/2][k]=image2[i+SIZE/2][j+SIZE/2][k];
                        }

                    }
                }
            }
                // -------------
            else if (index==2){
                if (order[index]=='1'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j][k]=image2[i][j][k];
                        }

                    }

                }else if (order[index]=='2'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j][k]=image2[i][j+SIZE/2][k];
                        }

                    }
                }else if (order[index]=='3'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j][k]=image2[i+SIZE/2][j][k];
                        }

                    }
                }else if (order[index]=='4'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j][k]=image2[i+SIZE/2][j+SIZE/2][k];
                        }

                    }
                }
            }// ---------
            else if (index ==3){
                if (order[index]=='1'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j+SIZE/2][k]=image2[i][j][k];
                        }

                    }
                }else if (order[index]=='2'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j+SIZE/2][k]=image2[i][j+SIZE/2][k];
                        }

                    }
                }else if (order[index]=='3'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j+SIZE/2][k]=image2[i+SIZE/2][j][k];
                        }

                    }
                }else if (order[index]=='4'){
                    for (int i = 0; i < SIZE/2; i++){
                        for (int j = 0; j < SIZE/2; j++){
                            Image[i+SIZE/2][j+SIZE/2][k]=image2[i+SIZE/2][j+SIZE/2][k];
                        }

                    }
                }
            }
            index++;
        }
    }


}

//Filter no (12) blur filter

void blur(){
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                Image[i+1][j+1][k]=(Image[i][j][k]+Image[i][j+1][k]+Image[i][j+2][k]+Image[i+1][j][k]+Image[i+1][j+1][k]+Image[i+1][j+2][k]+Image[i+2][j][k]+Image[i+2][j+1][k]+Image[i+2][j+2][k])/9;
            }
        }
    }
}





