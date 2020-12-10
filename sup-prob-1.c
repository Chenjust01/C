#include <stdio.h>

    /***********************************************************************
     * Name(s)  Justin Chen                                                *
     * Box(s):   3293                                                      *
     * Assignment name (Supplemental Problem 1)                            *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <9/21/2018>                                          *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     * http://www.cs.grinnell.edu/~johnsonba/161.fa18/show-resource.php?resourceID=237*                                                                *
     *   Help obtained                                                     *
     *     Evening Tutor: Lucky                                            *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

int main()
{
  
  int no = 0;
  int yes = 1;
  int studentAnswer;
  int veteransAnswer;
  int age;

  
  int location = 1;
  int time;
  double mid = 20.0;
  double sides = 15.0;
  double balcony = 10.0;
  
  double total;
  
  //Ask the user their age and whether or not they are a student or a veterans.
  
  printf("How old are you?: ");
  scanf("%d", &age);
  
  //check if age is out of bound.
  if(age > 100){
    printf ("Input the right age.\n");
  }
    else if (age < 0)
      printf("ERROR: Input the right age\n");
    else{
      
  //Ask if you are a student or not.
  printf("Are you a student?: ");
  scanf("%d",&studentAnswer);

  //Check whether or not user input the right input
  if(!((studentAnswer == 0)||(studentAnswer==1)))
    {
      printf("Please input 0 or 1.\n");
  }
  
  else{
  //Ask whether you are a veterans or not.
  printf("Are you a veterans?: ");
  scanf("%d", &veteransAnswer);
  
  // Check if the user input the right input
  if(!((veteransAnswer == 0)||(veteransAnswer == 1)))
    {
      printf("Please input 0 or 1.\n");
    }
  
  else{
    //input the location where the user wishes to go.
    printf("Please input the section you want, middle = 0, sides = 1, Balcony = 2: ");
    scanf("%d", &location);
    //Check if the user input the right input
    if(!((location == 0)||(location == 1)||(location == 2))){
      printf("Please input 0, 1, or 2\n");
    }
    //Calulate the ticket pricing
    else {
     if(location == 0){
       total = total + mid;
     }
     if(location == 1){
       total = total + sides;
     }
     if(location == 2){
       total = total + balcony;
     }
    
    //input the time the user wishes to go
    printf("Please input the time you would like to go, Matinee: 0, Evening: 1 : ");
    scanf("%d", &time);

    //
    if(!((time == 0)||(time == 1))){
        printf("ERROR: Please input 0 or 1 as your answer.\n");
      }
    else{
      if(time == 1)
        total = total + 5.0;

      //Age discount for people who are yonger than 
      if (5 > age)
        printf("Your total: 0\n");
      else{

      //Age discount for people who are older than 55
      if (age>55)
        total = total - 2.0;
  

      //Student and veterans discount
      if((studentAnswer&&veteransAnswer)==1){
        double totalDiscount;
        totalDiscount = total * 0.15;
        total = total - totalDiscount;
      }

      //Student discount
      else if(studentAnswer==1){
        double totalDiscount;
        totalDiscount = total* 0.05;
        total = total - totalDiscount; 
      }

      //Veterans discount
      else if(veteransAnswer==1){
        double totalDiscount;
        totalDiscount = total*0.1;
        total = total - totalDiscount;
      }
  
    //Print out the total amount
    printf("Your total is $ %lf\n", total);
         }
       }
     }
    }
   }
  }
  return 0;

  
}
