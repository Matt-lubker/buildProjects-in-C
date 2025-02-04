#include <stdio.h>

int find_max(int array[], int length);

int main(void)
{
  int myarray1[] = {8,7,5,3,9,10,1,2,4};
  int myarray2[] = {9,6,3,1,0,8};

  int max1 = find_max(myarray1, 9);
  int max2 = find_max(myarray2, 6);

  printf("max1: %d\n", max1);
  printf("max2: %d\n", max2);

  return 0;
}

int find_max(int array[], int length)
{
  int max = array[0];

  for (int i = 1; i < length; i++)
  {
    if (array[i] > max) 
    {
      max = array[i];
    }
  }

  return max;
}