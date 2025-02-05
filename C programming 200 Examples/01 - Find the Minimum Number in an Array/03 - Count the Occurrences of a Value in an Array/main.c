#include <stdio.h>

int occurrences(int array[], int length, int to_find);

int main(void)
{
  int myarray1[] = {4,9,5,5,5,5,6,2,1,5};
  int myarray2[] = {0,0,1,1,0,2,0,3};

  int findarr1_5 = occurrences(myarray1, 10, 5);
  int findarr2_0 = occurrences(myarray2, 8, 0);

  printf("# of 5s found in myarray1: %d\n", findarr1_5);
  printf("# of 0s found in myarray2: %d\n", findarr2_0);

  return 0;
}

int occurrences(int array[], int length, int to_find)
{
  int count = 0;

  for (int i = 0; i < length; i++)
    if (array[i] == to_find) count++;

  return count;
}