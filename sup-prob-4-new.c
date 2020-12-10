
    /***********************************************************************
     * Name(s) Justin Chen                                                 *
     * Box(s): 3293                                                            *
     * Assignment name  Supplemental Problem #4                            *
     * Assignment for 11/16/2018                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    None                                                             *
     *   Help obtained                                                     *
     *     None                                                            *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Justin Chen                                            *
     ***********************************************************************/
#include <stdio.h>
#include <string.h>

 typedef struct{
  char title[50];
  int year;
  float rating;
 } movie;


void changeRating(movie action[], int length);
void sortTitle(movie action[], int length);
void sortRating(movie action[], int length);

int main() {
  
  int movie_Num = 0;
  int user_input = 0;
  char movie_name[50];
  int movie_year = 0;
  float rating = 0.0;
  
  printf("Creating a list of your favorite movies! \n");
  // Ask the user to enter numbers of movie they want
  printf("How many movies do you want to input: ");
  scanf("%d", &movie_Num);
  
  char  ch = getchar();
  movie action[movie_Num];
  // Read the movie name and the program will read the name in as the same line as the year and the rating
    for(int i = 0; i < movie_Num; i++){

      printf("Enter the movie name that is enclosed in double quotes \n" );
      printf("Please enter movie name: ");
      ch = getchar();
   
      int j = 0;
      char arr[100];
      // reading in the movie name
      while((ch = getchar()) != '"'){
        arr[j] = ch;
        j++;      
      }
      
      arr[j] = '\0';
      
      // Let the the title in the struct to be equal to the user input
      strcpy(action[i].title, arr);
      
      // Ask the user to enter the movie year
      printf("Enter the year: ");
      scanf("%d", &movie_year);
      
      // Ask the user to enter the movie year
      printf("The rating has to be an integer or a real number");
      printf("Range of ratings is between 0 and 4 \n");
      printf("Enter rating: ");
      scanf("%f",&rating);
      // if the rating the user had inputed is greater than 4 or less than 0, then the program will throw out an error
      while(rating > 4 || rating < 0){
        getchar();
        printf("ERROR: rating is out of the range \n");
        printf("range of ratings is between 0 and 4 \n");
        printf("Enter rating: ");
        scanf("%f",&rating);
      }
      

      action[i].year = movie_year;
      action[i].rating = rating;
      
      getchar();
    }
    

    // Ask the user to enter an option and the program will end when the user type in 4
  do{
    
    printf("1. Change rating \n");
    printf("2. Print array sorted by title \n");
    printf("3. Print the array sorted by rating \n");
    printf("4. Quit \n ");
    printf("Please remember to enter the option by the number \n");
    printf("Input an option: ");
    scanf("%d", &user_input);
    getchar();
    // Check which option the user has inputed
      if(user_input == 1){
        changeRating(action, movie_Num);
      }
      
      else  if(user_input == 2){
        sortTitle(action, movie_Num);
      }
      
      else if(user_input == 3){
        sortRating(action, movie_Num);
      }

  }while(user_input != 4);
    
    
    return 0; 
}

//Pre-condition
/*
 movie action[] a sturct of arrays
 length the number of the movie that user had inputed and it is also an integer
 */
//Post-conditon
/*
 change the rating of the specific movie that the user has requested
 */
void changeRating(movie action[], int length){
  char arr[100];
  float new_input = 0.0;
  int counter = 0;
  //Ask the user to input the movie that they wish to change
  printf("When entering the movie this time do not enclosed it with double quotes \n");
  printf("Enter the movie that you would like the rating to be change: ");
  gets(arr);
  
  // Ask the user to give the new rating
  printf("range of ratings is between 0 and 4 \n");
  printf("Please enter the rating: ");
  scanf("%f", &new_input);
  // check if the rating is out of range
   while(new_input> 4 || new_input < 0){
      getchar();
      printf("ERROR: rating is out of the range \n");
      printf("range of ratings is between 0 and 4 \n");
      printf("Enter rating: ");
      scanf("%f", &new_input);
   }
   // change the rating
   for(int i = 0; i < length; i++ ){
     if(strcmp(action[i].title, arr) == 0 ){
        action[i].rating = new_input;
        counter++;
     } 
   }
   // If the movie does not exits throw an error 
   if(counter <=  0){
     printf("ERROR: You did not enter a movie that exists in this list please try again. \n");
   }
}
 
//Pre-condition
/*
 movie action[] a sturct of arrays
 length the number of the movie that user had inputed and it is also an integer
 */
//Post-conditon
/*
 Sort the title by alphabetical order by using insertion sort
 */
void sortTitle(movie action[], int length){
  for (int k = 1; k < length; k++) {

    float item = action[k].rating;
    
    char *item_title = action[k].title;
    char item_title2[50];
    strcpy(item_title2,item_title);
    
    int item_year = action[k].year;
    
    int i = k-1;
    // check if the if  alphabetes is alphabetical if not the program will switch the two aphabetes poistion
    while ((i >= 0) && (strcmp(action[i].title, item_title2) > 0)){
     
      strcpy(action[i+1].title,  action[i].title);
      action[i+1].rating = action[i].rating;
      action[i+1].year = action[i].year;
      i--;
    }
    // put the second alphabete in the first aphabete's initial position
    strcpy(action[i+1].title, item_title2);
    action[i+1].rating = item;
    action[i+1].year = item_year;
      
  }
  // print out the sorted ratings
  for(int i = 0; i< length; i++){
    printf("%s %d %.1f \n", action[i].title, action[i].year, action[i].rating);
  }
}

//Pre-condition
/*
 movie action[] a sturct of arrays
 length the number of the movie that user had inputed and it is also an integer
 */
//Post-conditon
/*
 Sort the rating by accending order by using insertion sort
 */
void sortRating(movie action[], int length){


  for (int k = 1; k < length; k++) {
    
    float item = action[k].rating;
    
    char *item_title = action[k].title;
    char item_title2[50];
    strcpy(item_title2,item_title);
    
    int item_year = action[k].year;
     
    int i = k-1;
    // if the first number is larger than the next number swtich their spaces.
    while ((i >= 0) && (action[i].rating > item)){
      strcpy(action[i+1].title, action[i].title);
      action[i+1].rating = action[i].rating;
      action[i+1].year = action[i].year;
  
    i--;
  }
  // put the second number to the first number initial postion. However, if it is not the case the numbers will stay in their postion
  strcpy(action[i+1].title, item_title2);
  action[i+1].rating = item;
  action[i+1].year = item_year;
      
}
  // print out the sorted rating
  for(int i = 0; i< length; i++){
    printf("%s %d %.1f \n", action[i].title, action[i].year, action[i].rating);
  }
 
}
