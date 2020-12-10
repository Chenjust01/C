 /***********************************************************************
     * Name(s): Justin Chen                                                *
     * Box(s):  3293                                                       *
     * Assignment name:   Problem 7: Decimal Numbers to Binary             *
     *                                                                     *
     * Assignment for 12/13/2018                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     * https://www.geeksforgeeks.org/program-decimal-binary-conversion/    *
     *   Help obtained:                                                    *
     *    None                                                             *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/


#include <stdio.h>

void decToBinary(int n);

int main() 
{ 
  int n = 0;
  
  printf("please enter a number to be converted to binary number: ");
  scanf("%d", &n);
  decToBinary(n);
  
  return 0; 
}

/*
pre: takes in n as an interger
 */
void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[1000]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    printf("The binary of %d",n);
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
      printf("%d", binaryNum[j]);

    printf("\n");
} 
