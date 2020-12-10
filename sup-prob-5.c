#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxQueue 50  /* size of all queue arrays */
#define MaxStack 50  /* MaxStack stands for the size of all stack arrays */
#define StringLength 5 /* maximum length of string on stack */

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
void print (stringQueue queue);

//stack

int main(){
  stringQueue queue;
  stringQueue queue2;
  int j = 0;
  char arr[50];
  char  ch = getchar();

  
  //int length = 0;
  // int flag;
  
  printf("Make sure to press enter before entering your word\n");
  printf("Please enter your word: ");
  //ch = getchar();
  
  //read in the array
  while((ch = getchar()) != '\n'){
    arr[j] = ch;
    // printf("TEST: %c \n", arr[j]);
    //enqueue(&queue, arr);
    j++;
  }
  initializeQueue(&queue);
  

  // printf("%d \n", j);
  for(int i = 0; i < j; i++){
    enqueue(&queue, arr[i]);
    enqueue(&queue2, arr[i]);

     //printf("%s",queue);
  }
 


    
  print(queue);

  dequeue(&queue);
  print(queue);
  
  dequeue(&queue);
  print(queue);
  
  /*  
  for(int i = 0; i< length; i++){
    push()
  }
  
  

  for(int i = 0; i < length; i++){
    if(arr[i] != arr[length - i -1]){
      flag = 1;
      break;
    }
  }

  if(flag){
    printf("%s is not a palindrome \n", arr);
  }else{
    printf("%s is a palindrome \n", arr);
  }
 
  */

}
  
void initializeQueue (stringQueue * queue)
{
  queue->first = 0;

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
  return (queue.count == MaxQueue);
}
  

/* insert given item into back of the queue
   pre:  the specified queue is initialized
   returns:  -1 if queue is full
   otherwise, length of item, if item added
*/

//not dealing with string so no char *
char  enqueue (stringQueue * queue, char item)
{
  if (isFull (*queue))
    {
      return -1;
    }
  else
    {
      /*x
      char ite[2];
      ite[0]= item;
      ite[1]= 0;
      */
      int prevIndex = queue->count;
      queue->queueArray[prevIndex] = item;
      //  queue->last = (queue->last + 1) % MaxQueue;
      queue->count++;
      //printf("COUNT %d \n", queue->count);
      // printf("%d \n", prevIndex);
      //printf("%c \n",(queue->queueArray[prevIndex]) );
      // printf("%d \n", prevIndex);
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
    }else{
    //queue->first = (queue->first + 1) % MaxQueue;
      queue->first = queue->first + 1;
      
      printf("TESTING first: %d \n",queue->first );
      printf("TESTING before: %d \n",queue->count );
      
      queue->count--;
      
      printf("TESTING after: %d \n",queue->count );
      printf("%s \n",&(queue->queueArray[queue->first]));
      return &(queue->queueArray[queue->first]);
    }
}

char * pop(stringQueue * queue){
  if (isEmpty (*queue))
    {
      return 0;
    }else{
    //queue->first = (queue->first + 1) % MaxQueue;
      queue->first = queue->first + 1;
      
      printf("TESTING first: %d \n",queue->first );
      printf("TESTING before: %d \n",queue->count );
      
      queue->count--;
      
      printf("TESTING after: %d \n",queue->count );
      printf("%s \n",&(queue->queueArray[queue->first]));
      return &(queue->queueArray[queue->first]);
}
/* print elements on the queue 
 */
void print (stringQueue queue)
{
  printf ("the elements on the queue are:\n");

  for (int i = 0; i < queue.count; i++)
    {
      printf (" %c", queue.queueArray[i]);
      
    }
  printf ("\n    end of queue\n");

}
 


