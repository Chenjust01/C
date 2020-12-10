
    /***********************************************************************
     * Name(s): Justin Chen                                                *
     * Box(s):  3293                                                       *
     * Assignment name:  Problem 7: Decimal Numbers to Binary              *
     *                                                                     *
     * Assignment for 12/13/2018                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *  https://www.geeksforgeeks.org/program-decimal-binary-conversion/   *
     *   Help obtained:                                                    *
     *    None                                                             *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/


#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
  char array[100];
  int shifts = 0;
  char new[100];
  int num_char = 0;
  
  // Ask user to enter the message that they want to encrypt 
  printf("Input your message to be encrypted: ");
  gets(array);
  // Ask user how many times they want each character to shift
  printf("Enter the shifts amount: ");
  scanf("%d", &shifts);
  //calculate the characters in the message that the user had inputed 
  for(int i = 0;  array[i] != '\0'; i++){
    num_char++;
  }
  //Throw an error if the user did not input anything
  if(num_char == 0){
    printf("Please enter the message again \n");
  }else{
     // Shifts the character around based on what the user had requested
     for(int i = 0; i < num_char; i++){
       // check if the character is an alphabet or if not don't change the character
       if(isalpha(array[i]) == 0){
       new[i] = array[i];
       }
       // if the character is uppercase then shift the character around the uppercase
       else if(isupper(array[i])){
         new[i] = ((array[i] - 'A') + shifts)%26 + 'A';
       }
       // if the charater is lowercase then shift the character around the lowercase
       else if(islower(array[i])){
         new[i] = ((array[i] - 'a') + shifts)%26 + 'a';
       } 
     }
     // Prints out the original message
     printf("Original alphabet: ");
     // for(int i = 0; array[i] != '\0'; i++){
     for(int i = 0; i < num_char; i++){
       printf("%c", array[i]);
     }
     printf("\n");
  
     // Print out the encrypted message
     printf("Alphabet shifted %d: ", shifts);
     for(int i = 0; i < num_char; i++){
       printf("%c", new[i]);
     }
     printf("\n");
   }

  return 0;
}
