#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value)
{
if(rear == MAX - 1)
{
 printf("Queue is full! Cannot insert\n");
 }
 else {
if(front == -1)
{
 front = 0;
}
rear = rear + 1;
Queue[rear] = value;
printf("Inserted %d into queue\n", value);
 }
}
void dequeue()
{
if(front == -1 || front > rear)
{
printf("Queue is empty\n");
}
else {
int dequeue_element = Queue[front];
front = front + 1;
 printf("Deleted %d from queue\n", dequeue_element);
if(front > rear) {
front = rear = -1;
}
 }
}
void traversal()
{
if(front == -1 || front > rear)
{
printf("Queue is empty\n");
}
else {
for(int i = front; i <= rear; i++)
{
printf("Queue element: %d\n", Queue[i]);
}
}
}
int main()
{
int choice, value;
do {
printf("\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n");
scanf("%d", &choice);
switch(choice)
{
case 1:
 printf("Enter element to insert: \n");
 scanf("%d", &value);
 enqueue(value);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 traversal();
 break;
 case 4:
 exit(0);
 break;
 default:
 printf("Invalid choice\n");
 break;
}
} while(choice != 4);
return 0;
}
