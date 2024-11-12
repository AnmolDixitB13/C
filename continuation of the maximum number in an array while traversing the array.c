//Continuation of the max no in the array while traversing the array

/*
EXAMPLE 1
I/P array = {1, 4, 5, 3, 2, 1, 3, 18, 2, 23, 1, -8, 45}
Expected O/P = {4, 5, 5, 5, 5, 3, 18, 18, 23, 23, 23, 45, 45}

EXAMPLE 2
I/P array = {11, 4, 5, 3, 2, 1, 3, 18, 2, 23, 1, -8, 45}
Expected O/P: = {11, 5, 5, 5, 5, 3, 18, 18, 23, 23, 23, 45, 45}
*/

/*
logic = compare 2 elements of the I/P array, say 4th & 5th elements. If the 5th element > 4th element, value of O/P element in the
O/P array will be equal to the 5th element of the I/P array. If the condition is false, the value at that index in the O/P array will
be equal to the value of the previous element in the O/P array.

*For 1st element (0th index) in the O/P array, compare 0th and 1st elements as usual in the I/P array. But, if 1st value > 0th value
in the I/P array, 0th index in the O/P array will get the value of the index 1 of the I/P (REFER EXAMPLE 1), else the 1st value i.e.
0th index value in the O/P array will be equal to the 0th index value in the I/P array (REFER EXAMPLE 2).
*/


#include <stdio.h>

void newArr(int [], int ) ;

void main() {

//int arr[13] = {1, 4, 5, 3, 2, 1, 3, 18, 2, 23, 1, -8, 45} ;
int arr[] = {1, 4, 5, 3, 2, 1, 3, 18, 2, 23, 1, -8, 45} ;

int size ;

size = sizeof(arr)/sizeof(arr[0]) ;

printf("Size of I/P array: %d", size) ;

newArr(arr, size) ;

}

void newArr(int arr[], int n)
{   
    printf("\n\n n here: %d", n) ;

    int i ;
    int new_arr[n] ;
    
    for(i=0; i<n; ++i)
{   
    printf("%d", i) ;
    
    if (i == 0)
    {
        if(arr[i+1] > arr[i])
        {
            new_arr[i] = arr[i+1] ;
        }
        else
        {
            new_arr[0] = arr[0] ;
        }
	/*
	This is done to ensure if the condition arr[i+1] > arr[i] is not met for the 1st element 
	i.e. 0th index, the garbage value is assigned to new_arr[0]. To ensure this doesn't happen,
	new_arr[0] = arr[0] ; has been written for cases when the condition arr[i+1] > arr[i] 
	won't be met.
	*/
    } //end of outer if() statement
    
    else{
    if(arr[i+1] > arr[i])
    {
        new_arr[i] = arr[i+1] ;
    }
    else
    {
        new_arr[i] = new_arr[i-1] ;
    }
    } //end of outer else
} // end of for() loop

    printf("\n_______________________________________\n") ;

    //print the 2 arrays

    for(i=0; i<n; ++i)
    {
        printf("%d\t", arr[i]) ;
    }
        printf("\n---------------------------------------\n") ;
    
    for(i=0; i<n; ++i)
    {
        printf("%d\t", new_arr[i]) ;
    }
}
