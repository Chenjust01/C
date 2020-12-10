    /***********************************************************************
     * Name(s)  Justin Chen and Milo Reynolds                              *
     * Box(s):  3293 and 4357                                              *
     * Assignment name Project: Program a Song                             *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for 9/17/2018                                            *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *http://www.cs.grinnell.edu/~johnsonba/161.fa18/show-lab-project.php?sessionID=16*                         
     *   Help obtained                                                     *
     *      Barbara Johnson, Tal                                           *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

#include <stdio.h>
#include "MyroC.h"
#include "eSpeakPackage.h" //Need to use rBeep command and eSpeak talk 
#include "scale-notes.h" // Need to use within the rBeep command

// Function to be called within main to play the introduction of the song, as well as introduce it with eSpeak
void introduction()
{
  //Use eSpeak to talk about the music that is about to be play
  eSpeakTalk("Now playing the Star Spangled Banner, based on a poem by Francis Scott Key, music by Jon Staffor Smith.");
  eSpeakTalk("Sheet music from music notes dot com.");
  eSpeakTalk("At this moment, please rise and face the flag. Play introduction.");
  // Use rBeep to play a note in a certain duration, pitch, and octive. 
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
  
}

// Function to be called within main to play first partof the song, as well as introduce it with eSpeak
void part1()
{
  //Use eSpeak to introduce part 1 of the song.
  eSpeakTalk("Play part 1.");
  // Use rBeep to play a note in a certain duration, pitch, and octive. 
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
}

// Function to be called within main to play second part of the song, as well as introduce it with eSpeak
void part2()
{
  //Use eSpeak to introduce part 2 of the song.
  eSpeakTalk("Play part 2.");
  //Use rBeep to play duration, octive, and the pitch of the note
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
}

// Function to be called within main to play third part of the song, as well as introduce it with eSpeak
void part3()
{
  // Use eSpeak to introduce part 3 of the song
  eSpeakTalk("Next, play part 3.");
  //Use rBeep to play the duration, pitch and the octive of the note
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
}

// Function to be called within main to play conclusion of the song, as well as introduce it with eSpeak
void conclusion()
{
  //Use eSpeak to introduce the conclusion of the song.
  eSpeakTalk("Finally, play the conclusion.");
  //Use rBeep to play the duration, the pitch, and the octive of the note.
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

// Bring all parts of the song together by calling the 5 different functions above in order. 
int main()
{
  rConnect("/dev/rfcomm0"); //connect to the robot.
  eSpeakConnect(); // connect to eSpeak
  rSetVolume('H'); // Maximize the volume
  // Play each fuction in the correct order
  introduction();
  part1();
  part2();
  part3();
  conclusion();
  eSpeakDisconnect(); // Dissconnect from the eSpeak
  rDisconnect();//Disconnect to the robot
  return 0;  
}

