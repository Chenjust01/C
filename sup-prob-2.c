#include <stdio.h>

    /***********************************************************************
     * Name(s) Justin Chen                                                 *
     * Box(s): 3293                                                        *
     * Assignment name:   Problem 2: Credit Card Comparison                *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <8/05/18>                                            *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Help obtained                                                     *
     *             Shelby                                                  *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

// Caulate the new balance
double calc_balance(double old_balance, double interest, double payment){
  double new_balance = 0.0;

  new_balance = old_balance - payment + (interest *(old_balance - payment));
  
  return new_balance; 
}

int main(){
  double total_budget = 0.0;
  double min_pay = 0.0;
  
  double interest1 = 0;
  double annual_fee1 = 0.0;
  double interest_percent1 = 0.0;
  

  double interest2 = 0;
  double annual_fee2 = 0.0;
  double interest_percent2 = 0.0;
  
  int month = 1;
  double balance1 = 0.0;
  double balance2 = 0.0;

  double new_balance1 = 0.0;
  double new_balance2 = 0.0;

  double total_pay1 = 0.0;
  double total_pay2 = 0.0;
  
 // Ask user to input the budget of the trip 
    printf("What is the budget amount for your trip: ");
    scanf("%lf", &total_budget);
    
 // Ask the user to input the minimun pay   
    printf("What is the minimun monthly payment: ");
    scanf("%lf", &min_pay);

 // Ask for the annual fee for card#1 if none ask user to input 0.00
    printf("Enter annual fee for card#1 (enter 0.00 if there is none): ");
    scanf("%lf", &annual_fee1);
    balance1 = balance1 + annual_fee1; 
 
    
 // Ask user to enter the annual inerest rate for card#1 and ask user to input interger  
    printf("Enter the annual interest rate for card#1 (please enter a interger): ");
    scanf("%lf", &interest1);
   
      // Caulate the percent of the interest 
       interest_percent1 = interest1 / 100.0;
       interest_percent1 = interest_percent1 / 12.0;
         
     

 // Ask for the annual fee for card#2 if none ask user to input 0.00
    printf("Enter annual fee for card#2 (enter 0.00 if there is none): ");
    scanf("%lf", &annual_fee2);
    balance2 = balance2 + annual_fee2;
    
 // Ask user to enter the annual inerest rate for card#2 and ask user to input interger  
    printf("Enter the annual inerest rate for card#2 (please enter a interger): ");
    scanf("%lf", &interest2);
    
      // Caulate the percent of the interest
       interest_percent2 = interest2 / 100;
       interest_percent2 = interest_percent2 / 12.0;
      
       balance1 = total_budget + annual_fee1;
       balance2 = total_budget + annual_fee2;
      
      printf("Starting balances \n");
      printf("Card 1: %.2lf , Card2: %.2lf \n", balance1, balance2);
      printf("Month   card#1    card#2 \n");
 
      total_pay1 = total_pay1 + min_pay;
      total_pay2 = total_pay2 + min_pay;

      int zero = 0;
      if (min_pay == 0){
         printf("%4d %9.2lf %9.2lf \n", month, zero, zero);

      }else{
        // Print the comparison table out
        while((balance1 > 0.00)||(balance2 > 0.00)){ 
     
          // annual fee at the end of the year
       

          if((month%12) == 0){
            balance1 = balance1 + annual_fee1;
            balance2 = balance2 + annual_fee2;
            
            total_pay1 = total_pay1 + annual_fee1;
            total_pay2 = total_pay2 + annual_fee2;
          }

          
          new_balance1 = calc_balance(balance1,interest_percent1, min_pay);
          new_balance2 = calc_balance(balance2,interest_percent2, min_pay);
          
          balance1 = new_balance1;
          balance2 = new_balance2;
          //keep tracking of total pay
          if(balance1 > 0){
            total_pay1 = total_pay1 + min_pay;
          }
        
          if(balance2 > 0){
            total_pay2 = total_pay2 + min_pay;
          }
        
          // if balance is less than zero set the balances to zero
          if(balance1 < 0){
            total_pay1 = total_pay1 + new_balance1;
            new_balance1 = new_balance1 - new_balance1;
          }

          if(balance2 < 0){
            total_pay2 = total_pay2 + new_balance2;
            new_balance2 = new_balance2 - new_balance2; 
          }
          
          printf("%4d %9.2lf %9.2lf \n", month, new_balance1, new_balance2);

        
          month++; 
        }

        printf("Cost comparison summary \n");
        printf("Card 1 total of payments: %.2lf \n", total_pay1);
        printf("Card 2 total of payments: %.2lf \n", total_pay2);

        // Comparing card#1 and card#2
        if (total_pay1 < total_pay2){
          printf("Card 1 is the better deal. Annual fee: %.2lf and the annual interest rate: %.2lf \n", annual_fee1, interest1);
        } else{
           printf("Card 2 is the better deal. Annual fee: %.2lf and the annual interest rate: %.2lf \n", annual_fee2, interest2);
        }
      }
}
