#include <stdio.h>


void printarray(int arr[], int size)
{
  printf("Array: ");
  for(int i = 0; i<=size; i++)
  {
    printf("%d,",arr[i]);
  }
  printf(" size: %d\n",size);
}

void mergesort(int arr[], int bindex, int eindex)
{
    if (arr[bindex] > arr[eindex])
    {
        printf("mergesort\n");
        int temp = arr[bindex];
        arr[bindex] = arr[eindex];
        arr[eindex] = temp;
    }
}


void split(int arr[], int bindex, int eindex)
{
  int middle;

  if(bindex == eindex) return;

  middle  = (int)((bindex + (eindex-1)) /2);

  printf("split b%d e%d m%d \n", bindex, eindex, middle);

  printarray( &arr[bindex], eindex-bindex);

  split(arr, bindex, middle);
  split(arr, middle +1, eindex);
  mergesort(arr, bindex, eindex);

}

int main(void) {
    int test[8]= {3,1,5,4,2,9,8,6};
    int size = sizeof(test)/sizeof(test[0]);
    printf("size %d\n", size);
    //printarray(test, size);
    split(test, 0,size-1);
    printarray(test, size-1);
  return 0;
}



// 3 1 5 4 2 9 8 6
// [3 1 5 4]   [2 9 8 6]
// [31]   [54]    [29]    [86]
// [13]   [45]    [29]    [68]
// [1345] [2689]
// [12345689]
// 
// 
// 
// 
// 
