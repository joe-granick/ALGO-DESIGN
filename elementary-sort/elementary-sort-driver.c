#include <stdio.h>
#include <stdlib.h>
typedef int Item; //how does item work here?
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) { Item t = A; A = B; B = t;}
#define compexch(A,B) if(less(B,A)) exch(A,B)

// insertion sort implementation

void insertion_sort(Item a[], int l, int r)
  {
    int i, j;
    for(i=l+1; i <= r; i++)
      for(j = i; j > l; j--)
        compexch(a[j-1], a[j]);
  }


/*
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

  for(i=l+2; i<=r; i++)
  {
    int j=i; Item key = a[j];
    while(less(key, a[j-1]))
      {a[j] = a[j-1]; j--;}
    a[j] = key;
  }
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
