 /***********************************************************************
     * Name(s) Anthony Fu, Justin Chen            						   *
     * Assignment name 	module 011: Robot Command Project                  *
     * Assignment for Wed, Oct 31, 2018                                    *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   MyroC header file documentation, module 001:Robot Actions Project *
     *   Help obtained: None                                               *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/



#include <stdio.h>
#include "MyroC.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "scale-notes.h" // Need to use within the rBeep command

void beeptravel(int beepnum);
void usersong(double notelength);
void remotecontrol();
void sing(int reps);
void dance(double timelength, int repetitions);


int main(){

  rConnect("/dev/rfcomm0");
  
  char input[20];
  int commandcount = 0;
  
  
  do{
    printf("The commands are: Forward, Backward, TurnRight, TurnLeft, Beep, Beeptravel, Usersong, Remotecontrol, Sing, Dance\n Input \"Quit\" to exit the program\n");
    
    printf("Input command: ");
    scanf("%s", input);
   // Ask user to input the speed and the time in order to move the robot forward
     if(strcmp(input, "Forward") == 0){
      double speed = 0.0;
      double time = 0.0;
    
      printf("Input the speed: ");
      scanf("%lf",&speed);

      printf("Input the time: ");
      scanf("%lf", &time);

      rForward(speed, time);
      commandcount++;
     }
   // Ask user to input the speed and the time in order to move the robot backward
     else if(strcmp(input, "Backward") == 0){
      double speed = 0.0;
      double time = 0.0;
  
  
      printf("Input the speed: ");
      scanf("%lf",&speed);

      printf("Input the time: ");
      scanf("%lf", &time);

      rBackward(speed, time);
      commandcount++;
     }
   // Ask user to input the speed and the time in order to move the robot turn right
     else if(strcmp(input, "TurnRight") == 0){
      double speed = 0.0;
      double time = 0.0;    
   
      printf("Input the speed: ");
      scanf("%lf",&speed);

      printf("Input the time: ");
      scanf("%lf", &time);

      rTurnRight(speed, time);
      commandcount++;
     }
  // Ask user to input the speed and the time in order to move the robot turn left 
     else if(strcmp(input, "TurnLeft") == 0){
      double speed = 0;
      double time = 0;
    
      printf("Input the speed: ");
      scanf("%lf",&speed);

      printf("Input the time: ");
      scanf("%lf", &time);

      rTurnLeft(speed, time);
      commandcount++;
     }
  // Ask user to input the pitch and the time in order to let the robot make sound
     else if(strcmp(input, "Beep") == 0){
      int pitch = 0;
      double time = 0.0; 
    
      printf("Input the pitch: ");
      scanf("%d",&pitch);

      printf("Input the time: ");
      scanf("%lf", &time);

      rBeep(time, pitch);
      commandcount++;
     }
  // Ask user to input the length of the dance and the number of times to repeat it the dance
     else if(strcmp(input, "Dance") == 0 ){
       double length = 0.0;
       int reps = 0;
       printf("Please input length of dance in second: ");
       scanf("%lf", &length);
       printf("Please input number of dance repetitions as an integer: ");
       scanf("%d", &reps);
       dance(length, reps);
       commandcount++;
     }
  // Ask user to input the number of time to play the National Anthem
     else if(strcmp(input, "Sing")==0){
       int reps = 0;
       printf("Please input number of times to sing the US National Anthem: ");
       scanf("%d", &reps);
       sing(reps);
       commandcount++;
     }
  // Call the function remotecontrol
     else if(strcmp(input, "Remotecontrol") == 0){
       remotecontrol();
       commandcount++;
     }
  // Ask the user to input the length of the note and call the function user song   
     else if(strcmp(input, "Usersong") == 0){
       double length = 0.0;
       printf("Please input your desired note lengths: ");
       scanf("%lf", &length);
       usersong(length);
       commandcount++;
     }
  // Ask the user to input the number of times to beep and to move forward and call the function beeptravel
     else if(strcmp(input, "Beeptravel")== 0){
       int beepnum = 0;
       printf("Please input number of times to beep while traveling as an integer: ");
       scanf("%d", &beepnum);
       beeptravel(beepnum);
       commandcount++;
     }    
      
  }while(strcmp(input, "Quit") != 0); //Type "Quit" to exist the program 
  
  printf("Number of commands performed by the robot: %d\n", commandcount);

  rDisconnect();

  return 0; 

}

//Pre-Condition: timelength = length of each movement that makes up the dance
//  			 repetitions = the number of times to repeat the entire dance
//Post-Condition: The robot dances
void dance(double timelength, int repetitions){
  timelength /= 8;
  for(int i = 0; i < repetitions; i++){
     rTurnLeft(timelength, 0.5);
     rTurnRight(timelength, 0.5);
     
     rTurnLeft(timelength, 0.5);
     rTurnRight(timelength, 0.5);

     rTurnLeft(timelength, 0.5);
     rTurnRight(timelength, 0.5);

     rTurnLeft(timelength, 0.5);
     rTurnRight(timelength, 0.5);
  }
     
}

//Pre-Condition: reps = number of times to repeat the US National Anthem
//Post-Condition: The robot sings the US National Anthem the number of times specified by the user
void sing(int reps){
  for(int i = 0; i < reps; i++){
  rBeep(0.5, pitchG5);
  rBeep(0.5, pitchE5);
  rBeep(1.0, pitchC5);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchG5);
  rBeep(2.0, pitchC6);
  rBeep(0.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchFs5);
  rBeep(2.0, pitchG5);
  rBeep(0.5, pitchG5);
  rBeep(0.5, pitchG5);
  rBeep(1.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(1.0, pitchC6);
  rBeep(2.0, pitchB5);
  rBeep(0.5, pitchA5);
  rBeep(0.5, pitchB5);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchG5);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchC5);


  rBeep(0.5, pitchG5);
  rBeep(0.5, pitchE5);
  rBeep(1.0, pitchC5);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchG5);
  rBeep(2.0, pitchC6);
  rBeep(0.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchFs5);
  rBeep(2.0, pitchG5);
  rBeep(0.5, pitchG5);
  rBeep(0.5, pitchG5);
  rBeep(1.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(1.0, pitchC6);
  rBeep(2.0, pitchB5);
  rBeep(0.5, pitchA5);
  rBeep(0.5, pitchB5);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchG5);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchC5);

  
  rBeep(0.5, pitchE6);
  rBeep(0.5, pitchE6);
  rBeep(1.0, pitchE6);
  rBeep(1.0, pitchF6);
  rBeep(1.0, pitchG6);
  rBeep(2.0, pitchG6);
  rBeep(0.5, pitchF6);
  rBeep(0.5, pitchE6);
  rBeep(1.0, pitchD6);
  rBeep(1.0, pitchE6);
  rBeep(1.0, pitchF6);
  rBeep(2.0, pitchF6);
  rBeep(1.0, pitchF6);
  rBeep(1.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(1.0, pitchC6);
  rBeep(2.0, pitchB5);
  rBeep(0.5, pitchA5);
  rBeep(0.5, pitchB5);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchE5);
  rBeep(1.0, pitchFs5);
  rBeep(2.0, pitchG5);

  rBeep(1.0, pitchG5);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchC6);
  rBeep(0.5, pitchC6);
  rBeep(0.5, pitchB5);
  rBeep(1.0, pitchA5);
  rBeep(1.0, pitchA5);
  rBeep(1.0, pitchA5);
  rBeep(1.0, pitchD6);
  rBeep(0.5, pitchF6);
  rBeep(0.5, pitchE6);
  rBeep(0.5, pitchD6);
  rBeep(0.5, pitchC6);
  rBeep(1.0, pitchC6);
  rBeep(1.0, pitchB5);

  rBeep(0.5, pitchG5);
  rBeep(0.5, pitchG5);
  rBeep(1.5, pitchC6);
  rBeep(0.5, pitchD6);
  rBeep(0.5, pitchE6);
  rBeep(0.5, pitchF6);
  rBeep(3.0, pitchG6);
  rBeep(0.5, pitchC6);
  rBeep(0.5, pitchD6);
  rBeep(1.5, pitchE6);
  rBeep(0.5, pitchF6);
  rBeep(1.0, pitchD6);
  rBeep(2.0, pitchC6);
  }

}

//Pre-Condition: none
//Post-Condition: users use the keys WASD to move the robot around. 
/*
 * W key moves robot forward
 * A key turns robot counter-clockwise
 * D key turns robot clockwise
 * S key stops robot
 * Q key exits remotecontrol
 * */
void remotecontrol(){ //non-blocking
	printf("use WASD  to move the robot around. Make sure to press return to send the command to the robot! \n input 'q' to return to the main list of commands\n");
  char userinput = 0;
  while(userinput != 'q'){
    userinput = getchar();
    
    switch(userinput){
    case 'a':
      rTurnLeft(1.0, 0.0);
      break;
    case 'd':
      rTurnRight(1.0, 0.0);
      break;
    case 'w':
      rForward(1.0, 0.0);
      break;
    case 's':
      rBackward(0.0, 0.0);
      break;
    }
  }

  rForward(0.0, 1.0);//stops robot
}


//Pre-Condition: notelength = the length in seconds that will be produced by the robot
//Post-Condition: The robot sings notes A-G, which are determined by the input of the user (by pressing keys A-G), where the length is determined by the entered notelength
//The Q Key exits usersong
// 
void usersong(double notelength){//non-blocking
	printf("Please enter letters a-g to have the robot sing the associated pitches. Input 'q' to return to the main list of commands\n");
  char userinput = 0;
  while(userinput != 'q'){
	  userinput = getchar();
   switch(userinput){
    case 'a':
      rBeep(notelength, pitchA5);
      break;
    case 'b':
      rBeep(notelength, pitchB5);
      break;
    case 'c':
      rBeep(notelength, pitchC5);
      break;
    case 'd':
      rBeep(notelength, pitchD5);
      break;
   case 'e':
     rBeep(notelength, pitchE5);
     break;
   case 'f':
     rBeep(notelength, pitchF5);
     break;
   case 'g':
     rBeep(notelength, pitchG5);
     break;
    }  
}
}

//Pre-Condition: beepnum = the number of times the robot will beep
//Post-Condition: the robot will move forward and beep the number of times inputed by the user for 0.5 seconds each beep
void beeptravel(int beepnum){
 rForward(1.0, 0.0);

 for(int i = 0; i < beepnum; i++)
   rBeep(0.5, pitchA5);
  
 rForward(0.0, 1.0);//stops robot
  
}
