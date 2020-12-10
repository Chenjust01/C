 /***********************************************************************
     * Name(s): Priyank Shah & Justin Chen                                 *
     * Box(s): 4453 & 3293                                                 *
     * Assignment name: Robot actions project                              *
     * Assignment for 09-26-2018                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used: none                                 *
     *   Help obtained: Tal (Class mentor)                                 *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

#include <stdio.h>
#include <MyroC.h>
#include <eSpeakPackage.h>



int main(){
  rConnect ("/dev/rfcomm0");
  eSpeakConnect();
  
  movement();
  rDisconnect();
  return 0;
}

void movement(){
  int n = 0;
  int x = 1;
  int counter = 0;
  int lastTurn, currentTurn;
 // infinite loop for the movement of the robot (Exit program manually) 
 while(x > 0){
   //Go backwards if there is an obstacle in the front
    if ((rGetIRTxt("left", 3)) && (rGetIRTxt("right", 3)))
            {
              eSpeakTalk("Moving backward");
              rBackward(1, 1);
              printf("Backward\n");
              n++;
              lastTurn = 0;
            }
    // Turn right if there is an obstacle on the left
    else if(rGetIRTxt("left", 3))
              {
                currentTurn = 1;
                eSpeakTalk ("Obstacle. Turn right.");
                rTurnRight(2, .5);
                printf ("Turn right.\n");
                //if the robot turns right two times, then beep 
                if(lastTurn == currentTurn){
                  rBeep(1.0, 1000);
                }
                n++;
                lastTurn = 1;
              }
    // Turn left if there is an obstacle on the right
    else if(rGetIRTxt("right", 3))
                {
                  currentTurn = 2;
                  eSpeakTalk ("Obstacle. Turn left.");
                  rTurnLeft(2, .5);
                  printf ("Turn left.\n");
                  //if the robot turns left two times, then beep
                  if(lastTurn == currentTurn){
                  rBeep(1.0, 1000);
                }
                  n++;
                  lastTurn = 2;
                  
                }
    // If there are no obstacles on the front, left, or right then go forward
    else {
      eSpeakTalk("FORWARD MARCH!!!");
      rForward(1,1);
      printf("Forward\n");
      n++;
          lastTurn = 0;
  }
    // if the robot performs 10 actions then do a dance
    if(n % 10 == 0){
      dance();
    }
 }
}

void dance(){
  eSpeakTalk ("Robot will now perform a dance.");
  //Do the action three times with increasing speed for the turn
  for(int i = 0; i < 3; i++){
    for(double j = 0.2; j < 1; j += 0.2){
  rTurnLeft(j,0.2);
  rTurnRight(j, 0.2);
  rTurnLeft(j,0.2);
  rTurnRight(j, 0.2);
  rTurnLeft(j,0.2);
    }
  }
}
