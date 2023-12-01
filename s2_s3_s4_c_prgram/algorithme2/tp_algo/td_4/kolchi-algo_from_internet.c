#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void affichage(int *t, int taille)
{
   int i;

   for(i=0;i<taille;i++)
   {
      printf("%d|",t[i]);
   }
   printf("\n");
}

int max_tableau(int *t, int taille)
{
   int i;
   int max;

   max = 0;

   for(i=0;i<taille;i++)
   {
      if(t[i]>max)
      {
         max = t[i];
      }
   }
   return max;
}


void tri_denombrement(int *t,int taille)
{
   int i,j,k;
   int taillemax;
   int *tComptage; //tableau de comptage

   // on cherche le max du tableau à trier pour connaître la taille du tableau de comptage
   taillemax = max_tableau(t,taille);
   taillemax = taillemax + 1;
   tComptage = (int *) malloc (taillemax *sizeof(int));

   //on initialise le tableu de comptage à 0
   for(i=0;i<taillemax;i++)
   {
      tComptage[i] = 0;
   }

   //on remplit le tableau de Comptage
   for (i=0;i<taillemax;i++) //on parcourt la liste des entiers de 0 à la taille max pour compter le nombre d'éléments par entiers
   {
      for(j=0;j<taille;j++)//on parcourt le tableau initial
      {
         if(t[j]=i)
         {
            tComptage[j] = tComptage[j] + 1;
         }
      }
   }

   //on remplit le tableau avec les valeurs triés
   for(i=0;i<taillemax;i++)
   {
      for(j=0;j<taille;j++)
      {
         if(tComptage[i]=1)
         {
            t[j]=i;
         }
         if(tComptage[i]>1)
         {
            for(k=0;k<tComptage[i];k++)
            {
               t[j]=i;
               j++;
            }
         }
      }
   }                      
}

int main()
{
   int t1[5] = {2,3,2,4,5};
   int taille;

   tri_denombrement(t1,5);
   affichage(t1,5);

   system("PAUSE");
   return 0;
}




////////////////////////////////////////////////////////////////////////


// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
   // Repeat until the pointers low and high meet each other
   while (low <= high) {
      int mid = low + (high - low) / 2;

      if (array[mid] == x)
         return mid;

      if (array[mid] < x)
         low = mid + 1;

      else
         high = mid - 1;
   }

   return -1;
}

int main(void) {
   int array[] = {3, 4, 5, 6, 7, 8, 9};
   int n = sizeof(array) / sizeof(array[0]);
   int x = 4;
   int result = binarySearch(array, x, 0, n - 1);
   if (result == -1)
      printf("Not found");
   else
      printf("Element is found at index %d", result);
   return 0;
}



//////////////////////////////////////////////////////////////////////////////


// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

   // Create L ← A[p..q] and M ← A[q+1..r]
   int n1 = q - p + 1;
   int n2 = r - q;

   int L[n1], M[n2];

   for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
   for (int j = 0; j < n2; j++)
      M[j] = arr[q + 1 + j];

   // Maintain current index of sub-arrays and main array
   int i, j, k;
   i = 0;
   j = 0;
   k = p;

   // Until we reach either end of either L or M, pick larger among
   // elements L and M and place them in the correct position at A[p..r]
   while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
         arr[k] = L[i];
         i++;
      } else {
         arr[k] = M[j];
         j++;
      }
      k++;
   }

   // When we run out of elements in either L or M,
   // pick up the remaining elements and put in A[p..r]
   while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
   }

   while (j < n2) {
      arr[k] = M[j];
      j++;
      k++;
   }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
   if (l < r) {

      // m is the point where the array is divided into two subarrays
      int m = l + (r - l) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      // Merge the sorted subarrays
      merge(arr, l, m, r);
   }
}

// Print the array
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

// Driver program
int main() {
   int arr[] = {6, 5, 12, 10, 9, 1};
   int size = sizeof(arr) / sizeof(arr[0]);

   mergeSort(arr, 0, size - 1);

   printf("Sorted array: \n");
   printArray(arr, size);
}

/////////////////////////////////////////////////////////////////////////////////


// Counting sort in C programming

#include <stdio.h>

void countingSort(int array[], int size) {
   int output[10];

   // Find the largest element of the array
   int max = array[0];
   for (int i = 1; i < size; i++) {
      if (array[i] > max)
         max = array[i];
   }

   // The size of count must be at least (max+1) but
   // we cannot declare it as int count(max+1) in C as
   // it does not support dynamic memory allocation.
   // So, its size is provided statically.
   int count[10];

   // Initialize count array with all zeros.
   for (int i = 0; i <= max; ++i) {
      count[i] = 0;
   }

   // Store the count of each element
   for (int i = 0; i < size; i++) {
      count[array[i]]++;
   }

   // Store the cummulative count of each array
   for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
   }

   // Find the index of each element of the original array in count array, and
   // place the elements in output array
   for (int i = size - 1; i >= 0; i--) {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
   }

   // Copy the sorted elements into original array
   for (int i = 0; i < size; i++) {
      array[i] = output[i];
   }
}

// Function to print an array
void printArray(int array[], int size) {
   for (int i = 0; i < size; ++i) {
      printf("%d  ", array[i]);
   }
   printf("\n");
}

// Driver code
int main() {
   int array[] = {4, 2, 2, 8, 3, 3, 1};
   int n = sizeof(array) / sizeof(array[0]);
   countingSort(array, n);
   printArray(array, n);
}


///////////////////////////////////////////////////////////////////////////


// Quick sort in C

#include <stdio.h>

// Function to swap position of elements
void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {

   // Select the pivot element
   int pivot = array[high];
   int i = (low - 1);

   // Put the elements smaller than pivot on the left 
   // and greater than pivot on the right of pivot
   for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
         i++;
         swap(&array[i], &array[j]);
      }
   }

   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

void quickSort(int array[], int low, int high) {
   if (low < high) {

      // Select pivot position and put all the elements smaller 
      // than pivot on left and greater than pivot on right
      int pi = partition(array, low, high);

      // Sort the elements on the left of pivot
      quickSort(array, low, pi - 1);

      // Sort the elements on the right of pivot
      quickSort(array, pi + 1, high);
   }
}

// Function to print eklements of an array
void printArray(int array[], int size) {
   for (int i = 0; i < size; ++i) {
      printf("%d  ", array[i]);
   }
   printf("\n");
}

// Driver code
int main() {
   int data[] = {8, 7, 2, 1, 0, 9, 6};
   int n = sizeof(data) / sizeof(data[0]);
   quickSort(data, 0, n - 1);
   printf("Sorted array in ascending order: \n");
   printArray(data, n);
}




////////////////////////////////////////////////////////////////////


// Recursive C++ program to sort an array 
// using selection sort 
#include <iostream> 
using namespace std; 

// Return minimum index 
int minIndex(int a[], int i, int j) 
{ 
   if (i == j) 
      return i; 

   // Find minimum of remaining elements 
   int k = minIndex(a, i + 1, j); 

   // Return minimum of current and remaining. 
   return (a[i] < a[k])? i : k; 
} 

// Recursive selection sort. n is size of a[] and index 
// is index of starting element. 
void recurSelectionSort(int a[], int n, int index = 0) 
{ 
   // Return when starting and size are same 
   if (index == n) 
      return; 

   // calling minimum index function for minimum index 
   int k = minIndex(a, index, n-1); 

   // Swapping when index nd minimum index are not same 
   if (k != index) 
      swap(a[k], a[index]); 

   // Recursively calling selection sort function 
   recurSelectionSort(a, n, index + 1); 
} 

// Driver code 
int main() 
{ 
   int arr[] = {3, 1, 5, 2, 7, 0}; 
   int n = sizeof(arr)/sizeof(arr[0]); 

   // Calling function 
   recurSelectionSort(arr, n); 

   //printing sorted array 
   for (int i = 0; i<n ; i++) 
      cout << arr[i] << " "; 
   cout << endl; 
   return 0; 
} 



///////////////////////////////////////////////////////////////////////////////


// C/C++ program for recursive implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   // Base case
   if (n == 1)
      return;

   // One pass of bubble sort. After
   // this pass, the largest element
   // is moved (or bubbled) to end.
   for (int i=0; i<n-1; i++)
      if (arr[i] > arr[i+1])
         swap(arr[i], arr[i+1]);

   // Largest element is fixed,
   // recur for remaining array
   bubbleSort(arr, n-1);
}

/* Function to print an array */
void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

// Driver program to test above functions
int main()
{
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr, n);
   printf("Sorted array : \n");
   printArray(arr, n);
   return 0;
}


##############################

#include<stdio.h>
void BubbleSortRecursion(int a[],int num);
main()
{
   int i,j,num,temp;
   printf("Enter number of elements\n");
   scanf("%d",&num);
   int a[num];
   printf("Enter numbers\n");
   for(i=0;i<num;i++)
   {
      scanf("%d",&a[i]);
   }
   BubbleSortRecursion(a,num);
   printf("Given numbers in Ascending order \n");
   for(i=0;i<num;i++)
   {
      printf("%d\n",a[i]);
   }
}
void BubbleSortRecursion(int a[],int num)
{
   int i,j,temp;
   i=num;
   if(i>0)
   {
      for(j=0;j<num-1;j++)
      {
         if(a[j]>a[j+1])
         {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
         }
      }
      BubbleSortRecursion(a,num-1);
   }
   else
   {
      return;
   }
}




/////////////////////////////////////////////////////////////////////////////


// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
   // Base case
   if (n <= 1)
      return;

   // Sort first n-1 elements
   insertionSortRecursive( arr, n-1 );

   // Insert last element at its correct position
   // in sorted array.
   int last = arr[n-1];
   int j = n-2;

   /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
   while (j >= 0 && arr[j] > last)
   {
      arr[j+1] = arr[j];
      j--;
   }
   arr[j+1] = last;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
      cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
   int arr[] = {12, 11, 13, 5, 6};
   int n = sizeof(arr)/sizeof(arr[0]);

   insertionSortRecursive(arr, n);
   printArray(arr, n);

   return 0;
}


############################


#include <stdio.h>
void recursiveInsertionSort(int arr[], int n){
   if (n <= 1)
      return;
   recursiveInsertionSort( arr, n-1 );
   int nth = arr[n-1];
   int j = n-2;
   while (j >= 0 && arr[j] > nth){
      arr[j+1] = arr[j];
      j--;
   }
   arr[j+1] = nth;
}
int main(){
   int array[] = {34, 7, 12, 90, 51};
   int n = sizeof(array)/sizeof(array[0]);
   printf("Unsorted Array:\t");
   for (int i=0; i < n; i++)
      printf("%d ",array[i]);
   recursiveInsertionSort(array, n);
   printf("\nSorted Array:\t");
   for (int i=0; i < n; i++)
      printf("%d ",array[i]);
   return 0;
}


#################################



///////////////////////////////////////////////////////////////////



// C++ implementation to sort the matrix row-wise 
// and column-wise 
#include <bits/stdc++.h> 

using namespace std; 

#define MAX_SIZE 10 

// function to sort each row of the matrix 
void sortByRow(int mat[MAX_SIZE][MAX_SIZE], int n) 
{ 
   for (int i = 0; i < n; i++) 

      // sorting row number 'i' 
      sort(mat[i], mat[i] + n); 
} 

// function to find transpose of the matrix 
void transpose(int mat[MAX_SIZE][MAX_SIZE], int n) 
{ 
   for (int i = 0; i < n; i++) 
      for (int j = i + 1; j < n; j++) 

         // swapping element at index (i, j) 
         // by element at index (j, i) 
         swap(mat[i][j], mat[j][i]); 
} 

// function to sort the matrix row-wise 
// and column-wise 
void sortMatRowAndColWise(int mat[MAX_SIZE][MAX_SIZE], 
      int n) 
{ 
   // sort rows of mat[][] 
   sortByRow(mat, n); 

   // get transpose of mat[][] 
   transpose(mat, n); 

   // again sort rows of mat[][] 
   sortByRow(mat, n); 

   // again get transpose of mat[][] 
   transpose(mat, n); 
} 

// function to print the matrix 
void printMat(int mat[MAX_SIZE][MAX_SIZE], int n) 
{ 
   for (int i = 0; i < n; i++) { 
      for (int j = 0; j < n; j++) 
         cout << mat[i][j] << " "; 
      cout << endl; 
   } 
} 

// Driver program to test above 
int main() 
{ 
   int mat[MAX_SIZE][MAX_SIZE] = { { 4, 1, 3 }, 
      { 9, 6, 8 }, 
      { 5, 2, 7 } }; 
   int n = 3; 

   cout << "Original Matrix:\n"; 
   printMat(mat, n); 

   sortMatRowAndColWise(mat, n); 

   cout << "\nMatrix After Sorting:\n"; 
   printMat(mat, n); 

   return 0; 
} 

############################

// C++ implementation to sort the rows 
// of matrix in ascending order followed by 
// sorting the columns in descending order 
#include <bits/stdc++.h> 
using namespace std; 

#define MAX_SIZE 10 

// function to sort each row of the matrix 
// according to the order specified by  
// ascending. 
void sortByRow(int mat[][MAX_SIZE], int n,  
      bool ascending) 
{ 
   for (int i = 0; i < n; i++) 
   { 
      if (ascending)     
         sort(mat[i], mat[i] + n); 
      else
         sort(mat[i], mat[i] + n, greater<int>()); 
   }       
} 

// function to find transpose of the matrix 
void transpose(int mat[][MAX_SIZE], int n) 
{ 
   for (int i = 0; i < n; i++) 
      for (int j = i + 1; j < n; j++)  

         // swapping element at index (i, j)  
         // by element at index (j, i) 
         swap(mat[i][j], mat[j][i]); 
} 

// function to sort the matrix row-wise 
// and column-wise 
void sortMatRowAndColWise(int mat[][MAX_SIZE], 
      int n) 
{ 
   // sort rows of mat[][] 
   sortByRow(mat, n, true); 

   // get transpose of mat[][] 
   transpose(mat, n); 

   // again sort rows of mat[][] in descending 
   // order. 
   sortByRow(mat, n, false); 

   // again get transpose of mat[][] 
   transpose(mat, n); 
} 

// function to print the matrix 
void printMat(int mat[][MAX_SIZE], int n) 
{ 
   for (int i = 0; i < n; i++) { 
      for (int j = 0; j < n; j++) 
         cout << mat[i][j] << " "; 
      cout << endl; 
   } 
} 

// Driver program to test above 
int main() 
{ 
   int n = 3; 

   int mat[n][MAX_SIZE]  = {{3, 2, 1}, 
      {9, 8, 7},  
      {6, 5, 4}}; 

   cout << "Original Matrix:
      "; 
      printMat(mat, n); 

   sortMatRowAndColWise(mat, n); 

   cout << "
      Matrix After Sorting:
      "; 
      printMat(mat, n); 

   return 0; 
} 





