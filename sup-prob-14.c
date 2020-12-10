 /***********************************************************************
     * Name(s): Justin Chen                                                *
     * Box(s):  3293                                                       *
     * Assignment name:   Problem 14:Selection sort                        *
     *                                                                     *
     * Assignment for 12/14/2018                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *  https://www.geeksforgeeks.org/selection-sort/                      *
     *   Help obtained:                                                    *
     *    None                                                             *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

#include <stdio.h>

void selectionSort(int arr[], int n);
void swap(int *a, int *b);

int main(){
  int size = 0;
  int array[100];
  int element = 0;
  //get the size of the array
  printf("How many element do you wish to enter: ");
  scanf("%d", &size);

  //get the user input
  for(int i = 0; i<size; i++){
  printf("Enter an integer: ");
  scanf("%d", &element);
  array[i] = element; 
  }
  
  //sort the numbers
  selectionSort(array, size);
  printf("Sorted elements: \n");
  //print out sorted array
  for(int j = 0; j < size; j++){
    printf("%d ", array[j]);
  }
  printf("\n");
  return 0;
}

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
/*
Pre:
takes in array of interger and n as the size of the array
Post: 
None
 */
void selectionSort(int arr[], int n) 
{ 
    int i, j, min; 
  

    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum number in unsorted array 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
  
        // Swap the found minimum number  with the first number
        swap(&arr[min], &arr[i]); 
    } 
} 
