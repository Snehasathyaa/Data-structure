#include<stdio.h>
int ary1[10],ary2[10], ary4[20];
int size1, size2;
int i, j;
void sort(int ary3[], int size)
{
int temp;
for(i = 0; i < size - 1; i++)
{
for(j = i + 1; j < size; j++)
{
if(ary3[i] > ary3[j])
{
temp = ary3[i];
ary3[i] = ary3[j];
ary3[j] = temp;
}
}
}
}
void merge(int ary1[],int ary2[],int size1,int size2)
{
for(i = 0; i < size1; i++)
{
ary4[i] = ary1[i];
}
for(i = 0; i < size2; i++)
{
ary4[size1 + i] = ary2[i];
}
}
void display(int ary3[], int size)
{
for(i = 0; i < size; i++)
{
printf("%d\t", ary3[i]);
}
}
int main()
{
printf("Enter the number of elements of array 1:\n");
scanf("%d", &size1);
printf("Enter the elements of array 1:\n");
for(i = 0; i < size1; i++)
{
scanf("%d", &ary1[i]);
}
printf("Enter the number of elements of array 2:\n");
scanf("%d", &size2);
printf("Enter the elements of array 2:\n");
for(i = 0; i < size2; i++)
{
scanf("%d", &ary2[i]);
}
printf("the entered unsorted array1\n");
display(ary1,size1);
printf("\nthe entered unsorted array2\n");
display(ary2,size2);
sort(ary1,size1);
sort(ary2,size2);
printf("\nSorted array 1:\n");
display(ary1,size1);
printf("\nSorted array 2:\n");
display(ary2,size2);
int merged_size = size1 + size2;
printf("\nthe merged array:\n");
merge(ary1,ary2,size1,size2);
display(ary4, merged_size);
sort(ary4, merged_size);
printf("\nMerged and sorted array:\n");
display(ary4, merged_size);
return 0;
}
