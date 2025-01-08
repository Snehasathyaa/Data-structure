#include <stdio.h>
#include <stdlib.h>
int adjMatrix[4][4] = {
 {0, 0, 1, 0},
 {1, 0, 0, 0},
 {0, 0, 0, 1},
 {0, 1, 1, 0}
};
int visited[4] = {0, 0, 0, 0};
int queue[4];
int front = -1, rear = -1;
void enqueue(int vertex) {
 if (rear == 4) {
 printf("Queue is full!\n");
 return;
 }
 if (front == -1) {
 front = 0;
 }
 rear++;
 queue[rear] = vertex;
}
int dequeue() {
 if (front == -1) {
 printf("Queue is empty!\n");
 return -1;
 }
 int vertex = queue[front];
 front++;
 if (front > rear) {
 front = rear = -1;
 }return vertex;
}
void BFS(int startVertex) {
 for (int i = 0; i < 4; i++) {
 visited[i] = 0;
 }
 printf("Breadth-First Search starting from vertex %d:\n", startVertex);
 visited[startVertex - 1] = 1;
 enqueue(startVertex);
 while (front != -1) {
 int currentVertex = dequeue();
 printf("%d ", currentVertex);
 for (int i = 0; i < 4; i++) {
 if (adjMatrix[currentVertex - 1][i] == 1 && !visited[i]) {
 visited[i] = 1;
 enqueue(i + 1);
 }
 }
 }
 printf("\n");
}
int main() {
 BFS(1);
 return 0;
}
