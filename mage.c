#include <stdio.h>
#include "MyroC.h"

 /***********************************************************************
     * Name(s)  Justin Chen, Michael Spicer
     * Box(s):   3293, 4556                                                *
     * Assignment name Grouping Data and Image Processing with the Scribbler 2
     *              *
     * Assignment for Nov. 12, 2018                                        *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    [none]                    *
     *   Help obtained                                                     *
     *    [ Got help from Junze Yao.  Helped explain how to fill in a circle and greyscale values]
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:   Michael Spicer, Justin Chen                          *
     ***********************************************************************/
//Robot Notes
// original Fluke takes a picture that is 192 pixels high and 256 pixels wide
/*
***MyroC struct for a pixel

typedef struct
{
  unsigned char R; // The value of the red component 
  unsigned char G; // The value of the green component 
  unsigned char B; // The value of the blue component 
} Pixel;
Within this framework, R/G/B values of 0 correspond to black and R/G/B values of 255 correspond to white. This leads to the following natural definitions:

***MyroC struct for a picture object
typedef struct 
{
  int height;       // The actual height of the image, but no more than 266
  int width;        // The actual width of the image, but no more than 427
  Pixel pix_array[266][427]; // The array of pixels comprising the image
} Picture;
*/


void pixelStrip (Picture * pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic); 
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius);
void pixelate (Picture * pic, int degree);



int main () {
  
  //response variables
  int response = 0;
  char paramLetter = 'a';
  int paramNum1 = 0;
  int paramNum2 = 0;
  int paramNum3 = 0;
  char filename[] = "name";
  
  //connect to Robot
  rConnect("/dev/rfcomm0");

  //Take and display original picture
  printf("Point the robot at what you wish to take a picture of\n");
  printf("Enter any single key to take picture and continue:");
  scanf("%d", &response);
  Picture pic = rTakePicture();
  rDisplayPicture (&pic, 5, "Picture");

  //prompt user for which function to use
  printf("\n\nWhich function would you like to execute? (\n");
  printf("1. pixelStrip - set Red, Green, or Blue value to zero in every pixel\n");
  printf("2. pictureReder - increases the intensity of Red\n");
  printf("3. pictureGreener - increases the intensity of Green\n");
  printf("4. pictureBluer - increases the intensity of Blue\n");
  printf("5. cicleSelect - place a grey circle on to the picture\n");
  printf("6. pixelate - pixelates the picture\n");
  printf("\nPlease enter the numerical index of your option: ");
  getchar();
  scanf("%d", &response);
 
  //execute chosen function and display resulting picture
  switch (response) {
  case 1:
    // Ask the user to input color parameter
    printf("Please enter which color value to set to zero (Enter R, G, or B for Red, Green, Blue, respectively): ");
    getchar();
    scanf("%c", &paramLetter);
    //call pixelStrip
    pixelStrip(&pic, paramLetter);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  case 2:
    // Call the function pictureRedder
    pictureRedder(&pic);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  case 3:
    // Call the function pictureGrenner
    pictureGreener(&pic);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  case 4:
    // Call the function pictureBluer
    pictureBluer(&pic);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  case 5:
    // Ask the user to input the value x-axis, y-axis, radius of the circle 
    printf("Please enter the circle parameters.");
    printf("x-axis circle center integer value: ");
    scanf("%d", &paramNum1);
    printf("\ny-axis circle center integer value: ");
    scanf("%d", &paramNum2);
    printf("\ncircle radius integer size: ");
    scanf("%d", &paramNum3);
    // Call the function circleSelect
    circleSelect(&pic, paramNum1, paramNum2, paramNum3);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  case 6:
    // Ask the user to enter a value for how much pixelation they want
    printf("Please enter the integer degree of preferred pixelation (We recommend an a number between 1 and 10): ");
    scanf("%d", &paramNum1);
    pixelate(&pic, paramNum1);
    // Display the picture for 10 seconds and name the picture "Picture".
    rDisplayPicture (&pic, 10, "Picture");
    break;
    
  default:
    // If the user do not enter the number between 1 to 6 then the program will tell the user to try again
    printf("Please enter a valid function index.  Try again.");
     return 0;
     break;
  }
  
  // Ask the user if he or she wants to save the picture
    printf("Would you like to save your edited picture? (Enter Y or N for Yes and No, respectively): ");
    getchar();
    scanf("%c", &paramLetter);
    //if User wants to save picture, ask for file name as well
    if (paramLetter == 'y' || paramLetter == 'Y') {
      printf("What would you like to name this file?: ");
      getchar();
      fgets(filename, 100, stdin);
      rSavePicture(&pic, filename);
    }

    //terminate program
    return 0;
}


// pixelStrip will set all values of a given color (Red, Green, or Blue) to 0.
// Pre condition:
//     'color' must be a character R, G, or B.  It can be both upper or lower case.
// Post condition:
//      The resulting picture will set corresponding 'color' value to 0
void pixelStrip (Picture * pic, char color) {
  int i, j;
  // set corresponding Red values to 0
  if (color == 'R' || color == 'r'){
    for (i = 0; i < (*pic).height; i++)
      for (j = 0; j < (*pic).width; j++)
        (*pic).pix_array[i][j].R = 0;
  }
  //  set corresponding Green values to 0
    else if (color == 'G'|| color == 'g') {
    for (i = 0; i < (*pic).height; i++)
      for (j = 0; j < (*pic).width; j++)
        (*pic).pix_array[i][j].G = 0;
  }
  // set corresponding Blue values to 0
  else if (color == 'B'|| color == 'b'){ 
    for (i = 0; i < (*pic).height; i++)
      for (j = 0; j < (*pic).width; j++)
                (*pic).pix_array[i][j].B = 0;
  }
  else {
    printf ("Please Enter R, G, or B next time");
  }
}

//Intensifies red pixel values.  
// Pre condition:
//     none 
// Post condition:
//      intensiity increases more for smaller original red values, and less for larger original red values.
void pictureRedder (Picture * pic) {
  int i, j;
  int currentRed;
  double newRed;
  // Go through each of the pixels in the 2D array
  for (i = 0; i < (*pic).height; i++){
    for (j = 0; j < (*pic).width; j++){
      // increase old red value according to its size
      currentRed = (*pic).pix_array[i][j].R;
      newRed = ((255 - currentRed)/1.25) + currentRed;
      // set the pixel to the new intenisty
      (*pic).pix_array[i][j].R = newRed;
    }
  }
}

//Intensifies green pixel values.  
// Pre condition:
//     none 
// Post condition:
//      intensiity increases more for smaller original green values, and less for larger original green values.

void pictureGreener (Picture * pic) {
  int i, j;
  int currentGreen;
  double newGreen;
  // Go through each of the pixels in the 2D array
  for (i = 0; i < (*pic).height; i++){
    for (j = 0; j < (*pic).width; j++){
      // increase old Green value according to its size
      currentGreen = (*pic).pix_array[i][j].G;
      newGreen = ((255 - currentGreen)/1.25) + currentGreen;
       // set the pixel to the new intenisty
      (*pic).pix_array[i][j].G = newGreen;
    }
  }
}

//Intensifies blue pixel values.  
// Pre condition:
//     none 
// Post condition:
//      intensiity increases more for smaller original blue values, and less for larger original blue values.
void pictureBluer (Picture * pic) {
  int i, j;
  int currentBlue;
  double newBlue;
  // Go through each of the pixels in the 2D array
  for (i = 0; i < (*pic).height; i++){
    for (j = 0; j < (*pic).width; j++){
     // increase old Blue value according to its size
      currentBlue = (*pic).pix_array[i][j].B;
      newBlue = ((255 - currentBlue)/1.25) + currentBlue;
       // set the pixel to the new intenisty
      (*pic).pix_array[i][j].B = newBlue;
    }
  }
}

//circleSelect accepts parrameters of a circle (x and y center, and radius).  It then greyscales anywhere in the circle's parameters for a picture.
// Pre condition:
//     xCenter, YCenter and radius must be positive integers. 
// Post condition:
//      the greyscale used decreases red pixel values by 30%, green pixel values by 50%, and blue pixel values by 18%.
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius) {
  Pixel greyval;
  // Go through the pixels through the height and the width of the picture
  for (int i = 0; i < (*pic).height; i++) {
    for (int j = 0; j < (*pic).width; j++) {
      // if the (x-h)^2+(y-k)^2 <= radius^2 is true paint the pixel to the corresponding grayscale
      if ((((i - yCenter) * (i - yCenter)) + ((j - xCenter) * (j - xCenter))) <= radius * radius) {
        greyval.R = (*pic).pix_array[i][j].R * .30 + (*pic).pix_array[i][j].G * .50 + (*pic).pix_array[i][j].B * .18;
        greyval.G = greyval.R;
        greyval.B = greyval.R;
      (*pic).pix_array[i][j] = greyval;
      }
    }
  }
}

//pixelate groups pixels together and sets them to one value, effectively decreasing the amount of pixels shown and lowering resolution.  The degree of pixelation can be specified by the user.
// Pre condition:
//     degree has to be a positive integer
// Post conditions:
//      resulting pixel groups will have values set to the top left pixel of the group
void pixelate (Picture * pic, int degree) {
  Pixel groupedPix;
  // Go through the pixels through the height and the width of the picture
  for (int i = 0; i < (*pic).height; i++) {
    for (int j = 0; j < (*pic).width; j++) {
      // use the top left corner pixel of the grouped pixels and set it to 'groupedPix'
      if ((i % degree == 0) && (j % degree == 0)){
          groupedPix = (*pic).pix_array[i][j];
          //set all grouped pixels to 'groupedPix' values
          for (int k = 0; k <= (degree - 1); k++) {
            for (int l = 0; l <= (degree - 1); l++){
            (*pic).pix_array[i + k][j + l] = groupedPix;
            }
          }
      }
    }
  }
}
        
          
