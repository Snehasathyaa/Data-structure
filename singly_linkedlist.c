#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
 struct Node *link;
};
struct Node *header = NULL;
struct Node *CreateNode(int data) {
 struct Node *newnode;
 newnode = malloc(sizeof(struct Node));
 newnode->data = data;
 newnode->link = NULL;
 return newnode;
}
void insertAtFront(int data) {
 struct Node *newnode = CreateNode(data);
 if (header == NULL) {
 header = newnode;
 } else {
 newnode->link = header;
 header = newnode;
 }
}
void insertAtLast(int data) {
 struct Node *ptr;
 struct Node *newnode = CreateNode(data);
if (header == NULL) {
 header = newnode;
 return;
 }
 ptr = header;
 while (ptr->link != NULL) {
 ptr = ptr->link;
}
 ptr->link = newnode;
}
void insertAtAny(int key, int data) {
 struct Node *ptr = header;
 struct Node *newnode;
while (ptr != NULL && ptr->data != key) {
 ptr = ptr->link;
 }
 if (ptr == NULL) {
 printf("Key not found, insertion not possible\n");
 return;
 }
newnode = CreateNode(data);
 newnode->link = ptr->link;
 ptr->link = newnode;
}
void traverseList() {
 struct Node *ptr = header;
 while (ptr != NULL) {
 printf("%d -> ", ptr->data);
 ptr = ptr->link;
 }
 printf("NULL\n");
}
void deleteAtFront() {
 struct Node *ptr;
 if (header == NULL) {
 printf("List is empty\n");
 return;
 }
ptr = header;
 header = header->link;
 free(ptr);
}
void deleteAtEnd() {
 if (header == NULL) {
 printf("List is empty\n");
 return;
 }
if (header->link == NULL) {
 free(header);
 header = NULL;
 return;
 }
struct Node *ptr = header;
 struct Node *ptr1 = NULL;
 while (ptr->link != NULL) {
 ptr1 = ptr;
 ptr = ptr->link;
 }
 ptr1->link = NULL;
 free(ptr);
}
void deleteAtAny(int key) {
 if (header == NULL) {
 printf("List is empty\n");
 return;
 }
 struct Node *ptr = header;
 struct Node *prev = NULL;
while (ptr != NULL && ptr->data != key) {
 prev = ptr;
 ptr = ptr->link;
 }
if (ptr == NULL) {
 printf("Key not found, deletion not possible\n");
 return;
 }
if (prev == NULL) {
 header = ptr->link;
 } else {
 prev->link = ptr->link;
 }
free(ptr);
 printf("Node with key %d deleted\n", key);
}
void searchNode(int key) {
 struct Node *ptr = header;
 while (ptr != NULL) {
 if (ptr->data == key) {
 printf("Key %d found in the list\n", key);
 return;
 }
 ptr = ptr->link;
 }
 printf("Key %d not found in the list\n", key);
}
int main() {
int choice, data, key;
do {
printf("\nMenu:\n1. Insert at front\n2. Insert at last\n3. Insert at any position\n4.
Delete at front\n5. Delete at end\n6. Delete a specific node\n7. Search for a
node\n8. Traverse the list\n9. Exit\n ");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data to insert at front: ");
 scanf("%d", &data);
 insertAtFront(data);
 break;
 case 2:
 printf("Enter data to insert at last: ");
 scanf("%d", &data);
 insertAtLast(data);
 break;
 case 3:
 printf("Enter key to insert after and data to insert: ");
 scanf("%d %d", &key, &data);
 insertAtAny(key, data);
 break;
 case 4:
 deleteAtFront();
 break;
 case 5:
 deleteAtEnd();
 break;
 case 6:
 printf("Enter key to delete: ");
 scanf("%d", &key);
 deleteAtAny(key);
 break;
 case 7:
 printf("Enter key to search: ");
 scanf("%d", &key);
 searchNode(key);
 break;
 case 8:
 printf("Current List: ");
 traverseList();
 break;
 case 9:
 printf("Exiting program...\n");
 break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } while (choice != 9);
 return 0;
}
