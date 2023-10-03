#include <stdio.h>
#include <stdlib.h>

void QuickSort(int number[], int first, int last) {
   int i, j, pivot, temp;

   /* Check if there is more than one element in the subarray.*/
   if (first < last) {
      /* Choose the first element as the pivot.*/
      pivot = first;
      i = first;
      j = last;

      /* Partitioning phase: Rearrange elements such that elements smaller than the pivot
         are on the left side, and elements greater than the pivot are on the right side.*/
      while (i < j) {
         /*Find an element greater than or equal to the pivot from the left.*/
         while (number[i] <= number[pivot] && i < last)
            i++;

         /* Find an element less than the pivot from the right.*/
         while (number[j] > number[pivot])
            j--;

         /* Swap elements if they are out of place.*/
         if (i < j) {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      /* Swap the pivot element with the element at index 'j'.*/
      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;

      /* Recursively apply QuickSort to the left and right subarrays.*/
      QuickSort(number, first, j - 1);
      QuickSort(number, j + 1, last);
   }
}

int main() {
    int n, m, i, j, k;
    printf("Input size of matrix: ");
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n][m];
    int b[n * m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 81 - 40;
            printf("%4d ", a[i][j]);
        }
        printf("\n");

    }

    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[k] = a[i][j];
            k++;
        }
    }
printf("\n");
    QuickSort(b, 0, k - 1);
    for(k=0; k<n*m; k++){printf("%d ",b[k]);}

    printf("\n\n");
   int top = 0, bottom = n - 1, left = 0, right = m - 1;
    k= 0;

    while (left <= right && top <= bottom) {

        for ( i = left; i <= right; i++) {
            a[top][i] = b[k]; k++;
        }
        top++;

        for ( i = top; i <= bottom; i++) {
            a[i][right] = b[k]; k++;
        }
        right--;
        if (top <= bottom) {
            for (i = right; i >= left; i--) {
                a[bottom][i] = b[k]; k++;
            }
            bottom--;
        }
        if (left <= right) {
            for ( i = bottom; i >= top; i--) {
                a[i][left] = b[k]; k++;
            }
            left++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
