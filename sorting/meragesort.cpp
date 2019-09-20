#include <iostream>
#include <iomanip>
using namespace std;

void PrintArray(int a[], int last)
{
    for (int i = 0; i < last - 1; i++)
        cout << setw(2) << a[i] << ",";
    cout << setw(2) << a[last - 1] << endl;
}

// Merge two sequential arrays, sorted list starts at left
void merge(int* left, int lsize, int* right, int rsize)
{
    // Uncomment these output statements to see which lists are merged
    //cout << "F = "; PrintArray(F,fcnt);
    //cout << "S = "; PrintArray(S,scnt);
    //cout << endl;

    // Create temporary array to hold sorted list
    int *TempArray = new int[lsize + rsize];
    
    // Track index of next smallest value in each
    int lnext = 0, rnext = 0;

    // In each iteration, place one more sorted value
    for (int i = 0; i < lsize + rsize; i++)
    {
        if (lnext == lsize) // left is empty
        {
            TempArray[i] = right[rnext++];
        }
        else if (rnext == rsize) // right is empty
        {
            TempArray[i] = left[lnext++];
        }
        else if (left[lnext] <= right[rnext]) // choose the smaller value
        {
            TempArray[i] = left[lnext++];
        }
        else // right[rnext] > left[lnext]
        {
            TempArray[i] = right[rnext++];
        }
/*
   This implementation correctly handles the four possible cases, 
   but we can write a more concise solution, 
   replacing the nested if-else blocks above with:

    if( lnext < lsize && (rnext == rsize || left[lnext] <= right[rnext]) )
      TempArray[i] = left[lnext++];
    else
      TempArray[i] = right[rnext++];
   The if block here handles both cases where a value is pulled from left
   and the else block handles both cases for a value pulled from right.
   Either this if-else statement or the nested statements above will work.
*/
    }

    // Now TempArray holds sorted list
    // Copy sorted list back into original memory
    for (int j = 0; j < lsize + rsize; j++)
    {
        left[j] = TempArray[j];
    }

    // Deallocate temporary array
    delete[] TempArray;
}

// At end of function, A points to sorted list
void mergesort(int* A, int size)
{
    if (size <= 1) //if list has 1 element,  list is sorted
        return;
    
    // "Split" array into halves
    int midpt = size / 2;

    int *left = A;
    int lsize = midpt;

    int *right = A + midpt;
    int rsize = size - midpt;

    // Recursively sort each half
    mergesort(left, lsize);
    mergesort(right, rsize);

    // Assume first,second now point to sorted sublists
    // Merge two halves
    merge(left, lsize, right, rsize);
}

int main()
{
    srand(time(NULL));

    int size;
    cout << "How many values? "; cin >> size;

    int* a = new int[size];

    // Use one of these loops to put data into an array for testing,
    //  either in random order, sorted order, or reverse order

    /** RANDOM ***/
    for( int i = 0; i < size; i++ ) {
        a[i] = rand() % (size*size);
    }

    /** ORDERED **
    for( int i = 0; i < size; i++ ) {
        a[i] = i;
    }*/
    

    /** REVERSE **/
    /*
    for (int i = 0; i < size; i++) {
        a[i] = (size - i);
    }*/
    

    cout << "Original list:\n";
    PrintArray(a, size);

    mergesort(a, size);

    cout << "Sorted list:\n";
    PrintArray(a, size);

    delete[] a;
}
