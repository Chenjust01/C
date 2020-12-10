
    /***********************************************************************
     * Name(s)  Justin Chen                                                *
     * Box(s):                                                             *
     * Assignment name:   Supplemental  Problem 5: Palindromes             *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <due date>                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    None                                                             *
     *   Help obtained                                                     *
     *         None                                                        *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:  Justin Chen                                           *
     ***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxQueue 50  

typedef struct {
   int first;
   int last;
   int count;
   char queueArray [MaxQueue];
} stringQueue;

//Queue
void initializeQueue (stringQueue * queue);
int isFull (stringQueue queue);
char  enqueue (stringQueue * queue, char item);
char * dequeue (stringQueue * queue);

//stack
char * pop (stringQueue * queue);

int main(){
  
  stringQueue queue;
  stringQueue queue2;
  int j = 0;
  char arr[50];
  char arr2[50];
  char original[50];
  
  // if flag is 1 then the word is a palindrome
  int flag = 0;
  char  ch;

  //prompt the user
  printf("This program will check whether or not your word is a palindrome! \n");
  printf("Please do not enter a phrase.\n");
  printf("Please enter your word: ");

  //read in the array
  while((ch = getchar()) != '\n'){
    arr[j] = tolower(ch);
    arr2[j] = tolower(ch);
    original[j] = ch;
    j++;
  }
  // intitialize the queue
  initializeQueue(&queue);
  initializeQueue(&queue2);
  
  // enqueue the characters into the array
  for(int i = 0; i < j; i++){
    enqueue(&queue, arr[i]);
    enqueue(&queue2, arr2[i]);
  }

  // check if the word is a palindrome  
  for(int i = 0; i < j; i++){
     dequeue(&queue);
     pop(&queue2);
    if( queue.queueArray[i]!= queue2.queueArray[j- i -1]){
      flag = 1;
    }
  }
  // if true then say the word is a palindrome
  if(flag){
    printf("%s is not a palindrome \n",  original);
  }else{
    printf("%s is a palindrome \n",  original);
  }
}

/* pre:  queue is an initialized queue 
   first last and count are all equal to 0
*/
void initializeQueue (stringQueue * queue)
{
  queue->first = 0;
  queue->last = 0;
  queue->count = 0;

}

/* return whether the queue is empty
   pre:  queue is an initialized queue
   post: returns 1 (true) if queue is empty;
   0 otherwise
*/
int isEmpty (stringQueue queue)
{
  return (queue.count == 0);
}

/* return whether the queue is full
   pre:  queue is an initialized queue
   post: returns 1 (true) if an additional item
   cannot be added to the queue;
   0 otherwise
*/
int isFull (stringQueue queue)
{
  // if the count is equal to 50 return true
  return (queue.count == MaxQueue);
}

/* insert given item into back of the queue
   pre:  the specified queue is initialized
   returns:  -1 if queue is full
   otherwise, the char
*/
char  enqueue (stringQueue * queue, char item)
{
  if (isFull (*queue))
    {
      return -1;
    }
  else if (isEmpty (*queue))
  {
      queue->queueArray[0] = item;
      queue->count++;
       return queue->queueArray[0];
  }
  else {
     
      int prevIndex = queue->last+1;
      queue->queueArray[prevIndex] = item;
     
      queue->count++;
      queue->last++;
      return queue->queueArray[prevIndex];
    }
}

/* removes front item from queue referenced by parameter
   pre:  the specified queue is initialized
   returns:  0 if queue is empty
   otherwise, pointer to the item removed
*/

char  *dequeue (stringQueue * queue)
{
  if (isEmpty (*queue))
    {
      return 0;
      // otherwise decrement count but increment first
    }else{
      queue->first++;
      queue->count--;
      // return the pointer of the item that is removed
       return &(queue->queueArray[queue->first]);
    }
}

/* removes taik item from queue referenced by parameter
   pre:  the specified queue is initialized
   returns:  0 if queue is empty
   otherwise, pointer to the item removed
*/

char  *pop (stringQueue * queue)
{
  // if it is empty then return 0
  if (isEmpty (*queue))
    {
      return 0;
      // otherwise decrement last and count
    }else{
       queue->last--;
       queue->count--;
       // return the pointer of the item that is removed
        return &(queue->queueArray[queue->first]);
    }
}




