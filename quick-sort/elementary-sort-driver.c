#include <stdio.h>
#include <stdlib.h>
typedef int Item; //how does item work here?
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) { Item t = A; A = B; B = t;}
#define compexch(A,B) if(less(B,A)) exch(A,B)
#define M 10

// insertion sort implementation
int partition(Item a[], int l, int r)
{
  int i = l-1, j = r; Item v = a[r];
  for(;;)
  {
    while(less(a[++i], v)); 
    while(less(v,a[--j])) if(j==l) break;
    exch(a[i],a[j]);
  }
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
void insertion_sort(Item a[], int l, int r)
  {
    int i, j;
    for(i=l+1; i <= r; i++)
      for(j = i; j > l; j--)
        compexch(a[j-1], a[j]);
  }


/* Insertion Sort w/ Sentinel Key
 * Properties:
 *  Time Complexity 
 *    Worst O(n^2)
 *    Average O(n^2)
 *    Best O(n)
 *  Space Complexity 
 *    Worst() 
 *    Average O()
 *    Best O()
 *  Stable: Y
 *  In Place: Y
 *  Adaptive: Y
 *
 * this version of insertion sort improves upon the previous implementation in 3 ways
* 1. sentinel key is created by sorting the smallest element into the first index 
* 2. exchange removed from inner loop, just using a single assignment avoidng the overhead ops of compexch
* 3. converted to an adpative search terminating inner loop when element inserted 
* */
void insertion_sentinel(Item a[], int l, int r)
{
  int i;
  // find lowest value for sentinel key, and place in first index
  for(i=r; i>l; i--) compexch(a[i-1],a[i]);
  // main work of insertion sort
  for(i=l+2; i<=r; i++) // assume first entry sorted, second element becomes first selection compared to 2nd element 
  {int j=i; Item key = a[j];
    // setting with while loop like this creates an adaptive sort
    // cutting off comparisons once comparison fails
    // as all remaining comparisons will also be equal or smaller
    while(less(key, a[j-1]))
      {a[j] = a[j-1]; j--;}
    a[j] = key;}
}

/* Bubble Sort 
 * Properties:
 *  Time Complexity 
 *    Worst O(n^2)
 *    Average O(n^2)
 *    Best O(n)
 *  Space Complexity 
 *    Worst O()
 *    Average O()
 *    Best O()
 *  Stable: Y
 *  In Place: Y
 *  Adaptive: N
* */

void bubble_sort(Item a[], int l, int r)
{
  for (int i = l; i < r; i++)
    for(int j = r; j > l; j--)
      compexch(a[j-1], a[j]);
}

/* Selection Sort 
 * Properties:
 *  Time Complexity 
 *    Worst O(n^2)
 *    Average O(n^2)
 *    Best O(n^2)
 *  Space Complexity 
 *    Worst O()
 *    Average O()
 *    Best O()
 *  Stable: Y
 *  In Place: Y
 *  Adaptive: N
 */
void selection_sort(Item a[], int l, int r)
{
  for(int i = l; i < r; i++){
      int min = i;
    for (int j = i+1; j <= r; j++)
      if(less(a[j], a[min])) min = j;
    exch(a[i], a[min]);
    }
}

//void bubble_adaptive(Item a[], int l, int r)

//void shell_sort(Item a[], int l, int r)

void quicksortMedian(Item a[], int l, int r)
{int i;
  if(r-l<=M) return;

  exch(a[(l+r)/2], a[r-1]);
  compexch(a[l],a[r-1]);
  compexch(a[l],a[r]);
  compexch(a[r-1], a[r]);

  i = partition(a, l+1, r-1);
  quicksort(a,l,i-1);
  quicksort(a,i+1,r);
}

void sort(Item a[], int l, int r)
{
  quicksortMedian(a,l,r);
  insertion_sentinel(a,l,r);
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
    insertion_sentinel(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n");
    return 0;
  }

