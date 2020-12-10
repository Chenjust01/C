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
char * pop (stringQueue * queue);

int main(){
  stringQueue queue;

  int j = 0;
  char arr[50];
  //char  ch = getchar();
  char  ch;

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
  // printf("j = %d \n", j);
  initializeQueue(&queue);


  // printf("%d \n", j);
  for(int i = 0; i < j; i++){
    enqueue(&queue, arr[i]);


     //printf("%s",queue);
  }
  print(queue);

  dequeue(&queue);

  
  // printf("After enqueue: first = %d, last = %d, count = %d\n", queue.first, queue.last, queue.count);

  
  print(queue);

  dequeue(&queue);
  //printf("after dequeue: first = %d, count = %d\n", queue.first, queue.count);
  printf ("After dequeue: ");
  print(queue);


  dequeue(&queue);
  printf ("After dequeue: ");
  print(queue);

  enqueue(&queue, 'a');
  printf ("After equeue \'a\' : ");
  print(queue);

  pop (&queue);
  printf ("After pop: ");
  print(queue);

  pop (&queue);
  printf ("After pop: ");
  print(queue);

  enqueue(&queue, 'x');
  printf ("After equeue \'x\' : ");
  print(queue);

  pop (&queue);
  printf ("After pop: ");
  print(queue);

  dequeue(&queue);
  printf ("After dequeue: ");
  print(queue);

    //dequeue(&queue);
  //print(queue);

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
  else if (isEmpty (*queue)) // NEED TO ADD THIS ONE
  {
      queue->queueArray[0] = item;
      queue->count++;
      // printf ("EMPTY: ");
      // printf("first = %d, last = %d, count = %d, item = %c\n",
       //  queue->first, queue->last, queue->count, queue->queueArray[0]);

       return queue->queueArray[0];
  }
  else {
      /*x
      char ite[2];
      ite[0]= item;
      ite[1]= 0;
      */
      // int prevIndex = queue->count;  THIS LINE IS WRONG
      int prevIndex = queue->last+1;
      queue->queueArray[prevIndex] = item;
      //  queue->last = (queue->last + 1) % MaxQueue;
      queue->count++;
      queue->last++;
      //printf("COUNT %d \n", queue->count);
      // printf("%d \n", prevIndex);
      //printf("%c \n",(queue->queueArray[prevIndex]) );
      // printf("%d \n", prevIndex);

      // printf ("NON EMPTY: ");
      // printf("first = %d, last = %d, count = %d, item = %c\n",
       //  queue->first, queue->last, queue->count, queue->queueArray[prevIndex]);

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
      queue->first++;

      // printf("TESTING first: %d \n",queue->first );
      // printf("TESTING before: %d \n",queue->count );

      queue->count--;

      //printf("TESTING after: %d \n",queue->count );
      //printf("%s \n",&(queue->queueArray[queue->first]));
      // return &(queue->queueArray[queue->first]);
      // printf("Inside dequeue: first = %d, count = %d\n", queue->first, queue->count);

      return &(queue->queueArray[queue->first]);
    }
}


char  *pop (stringQueue * queue)
{
  if (isEmpty (*queue))
    {
      return 0;
    }else{
       queue->last--;
       queue->count--;

      //printf("TESTING after: %d \n",queue->count );
      //printf("%s \n",&(queue->queueArray[queue->first]));
      // return &(queue->queueArray[queue->first]);
      // printf("Inside dequeue: first = %d, count = %d\n", queue->first, queue->count);

      return &(queue->queueArray[queue->first]);
    }
}

/* print elements on the queue
 */
void print (stringQueue queue)
{
  printf ("the elements on the queue are:\n");

  // for (int i = 0; i < queue.count; i++) THIS LINE ISWRONG
  // printf("Inside print: first = %d, last = %d, count = %d\n", queue.first, queue.last, queue.count);

  for (int i = queue.first; i <= queue.last; i++)
    {
      printf (" %c", queue.queueArray[i]);

    }
  printf ("\n    end of queue\n");

}



