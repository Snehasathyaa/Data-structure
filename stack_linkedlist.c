#include <stdio.h>
#include <stdlib.h>
#define max 5
struct Node {
 int data;
 struct Node *link;
};
struct Node *top = NULL;
int size = 0;
struct Node *createNode(int data) {
 struct Node *newnode = malloc(sizeof(struct Node));
 newnode->data = data;
 newnode->link = NULL;
 return newnode;
}
void push(int data) {
 if (size == max) {
 printf("Stack overflow! Cannot push %d into stack\n");
 return;
 }
 struct Node *newnode = createNode(data);
 if (top == NULL) {
top = newnode;
 } else {
newnode->link = top;
top = newnode;
 }
 size++;
 printf("Inserted value: %d\n", data);
}
void pop() {
 if (top == NULL) {
printf("Stack is empty\n");
 } else {
struct Node *ptr = top;
top = top->link;
printf("Deleted value: %d\n", ptr->data);
free(ptr);
size--;
 }
}
void traversal() {
 struct Node *ptr = top;
 if (ptr == NULL) {
printf("Stack is empty\n");
 } else {
printf("Stack elements: ");
while (ptr != NULL) {
 printf("%d ", ptr->data);
 ptr = ptr->link;
}
printf("\n");
}
}
int main() {
int opt, data;
do {
printf("\n..................\n1) PUSH\n2) POP\n3) TRAVERSAL\n4) EXIT\n ");
printf("Enter your choice : ");
scanf("%d", &opt);
switch (opt) {
 case 1:
printf("\nEnter value to push: ");
scanf("%d", &data);
push(data);
break;
 case 2:
pop();
break;
 case 3:
traversal();
break;
 case 4:
printf("Exit...\n");
exit(0);
 default:
printf("\nInvalid option! Try again...\n");
}
 } while (1);
 return 0;
}
