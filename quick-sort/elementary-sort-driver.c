#include <stdio.h>
#include <stdlib.h>
typedef int Item; //how does item work here?
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) { Item t = A; A = B; B = t;}
#define compexch(A,B) if(less(B,A)) exch(A,B)
#define M 10

// Array printing utility
void printArray(int a[], int l, int r) {
    for (int i = l; i <= r; i++) printf("%d ", a[i]);
    printf("\n");
}
// partioning operation
int partition(Item a[], int l, int r)
{
  int i = l-1, j = r; Item v = a[r];
  printf("[PARTITION] Pivot selected: %d\n", v);
  for(;;)
  {
    while(less(a[++i], v)) printf("Moving right: %d < Pivot (%d)\n", a[i], v);
    while(less(v,a[--j])){printf("Moving left: %d > Pivot (%d)\n", a[j], v); if(j==l) break;}
    if(i >= j) break; // what happens here and why does it prevent segfault
    printf("Swapping a[%d] (%d) with a[%d] (%d)\n", i, a[i], j, a[j]);
    exch(a[i],a[j]);
    printArray(a,l,r);
  }
  printf("Placing pivot %d at index %d\n", v, i);
  exch(a[i], a[r]);
  return i;
}
void quicksort(Item a[], int l, int r){
  int i;
  if(r<=l) return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}

void insertion_sentinel(Item a[], int l, int r)
{
  int i;
  // find lowest value for sentinel key, and place in first index
  printf("\nPlace smallest element at front as sentinel key:\n");
  for(i=r; i>l; i--) compexch(a[i-1],a[i]);
  printArray(a,l,r);
  // main work of insertion sort
  for(i=l+2; i<=r; i++) // assume first entry sorted, second element becomes first selection compared to 2nd element 
  {int j=i; Item key = a[j];
  printf("\nKey: %d \n", key);
  printArray(a,l,r);
    // setting with while loop like this creates an adaptive sort
    // cutting off comparisons once comparison fails
    // as all remaining comparisons will also be equal or smaller
    
    while(less(key, a[j-1]))
      {printf("index: %d val: %d > key %d, move over next index %d value %d\n",(j-1), a[j-1], key, j, a[j]);
      a[j] = a[j-1]; j--;
      printArray(a, l, r); printf("\n");}
    a[j] = key; printf("\nAssign Key: %d to index: %d\n", key, j);
    printArray(a,l,r);}
}


// quick sort with median of 3 partitioning and sublist cutoff
void quicksortMedian(Item a[], int l, int r)
{int i;
//cutoff search for small sublists and finish with alternate methodn
  if(r-l<=M){printf("Switching to insertion sort for range [%d - %d]\n", l, r); return;}

// Median-of-Three Pivot Selection
  printf("\n[MEDIAN-OF-THREE STEP] Before:\n");
  printArray(a, l, r);
  
  printf("\n[Move Middle to Penultimelement] Before:\n");
  exch(a[(l+r)/2], a[r-1]);
  printArray(a, l, r);

  
  printf("\n[Swap middle element with first if smaller:\n");
  compexch(a[l],a[r-1]);
  printArray(a, l, r);

  printf("\n[Swap first element (or middle) with last if larger:\n");
  compexch(a[l],a[r]);
  printArray(a, l, r);

  printf("\n[Swap middle element (or first) with last if smaller:\n");
  compexch(a[r-1], a[r]);
  printArray(a, l, r);
  
  // find partioning element
  i = partition(a, l+1, r-1);
  printf("[PARTITION] Pivot placed at index %d\n", i);
  printArray(a, l, r);
  

  printf("quicksort(%d , %d)\n", l, (i-1));
  quicksortMedian(a,l,i-1);
  printf("quicksort(%d , %d)\n", (i+1), r);
  quicksortMedian(a,i+1,r);
}

void sort(Item a[], int l, int r)
{
  // quicksort with median of 3 partitioning
  // cutoff when called sublist length > M
  // leaves a mostly sorted list
  quicksortMedian(a,l,r);
  printArray(a,l,r);
  printf("[FINAL SORT] Final Cleanup with Insertion Sort\n");
  // use insertio sort for remaining list
  // insertion sort is fast for small files and files that are mostly sorted
  // so will be called if list is small (<M) for entire list which willbe small
  // or will sort remaining unsorted elements, since list will be mostly sorted it will aslo be fast
  insertion_sentinel(a,l,r);
  printArray(a,l,r);
}

int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = malloc(N*sizeof(int));
    if(sw){
      for (i=0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
      for (i = 0; i < N; i++) printf("%3d ", a[i]);
      printf("\n");
    }
    else{
      int count = 0;
      while (count < N && scanf("%d", &a[count]) == 1) count++;
      }
    sort(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n");
    return 0;
  }

