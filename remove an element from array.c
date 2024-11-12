
#include<stdio.h>
void removeMyNum(int [], int, int) ;
void main()
{
    int a[] = {5, 3, 5, 5, 5, 8, 9, 6, 7, 5, 100} ;
    int size = sizeof(a)/sizeof(a[0]) ;
    int rem = 100 ;   //element to be removed

    printf("Actual array size: %d\n", size) ;

    removeMyNum(a, size, rem) ;

} // end of main() function

void removeMyNum(int arr[], int n, int rem)
{
    int i, j ;

    int len_original = n ;
    //original length of the array received by this function

    int counts_removed = 0 ;
    //no. of times the number was encountered and removed

    for(i=0; i<n; ++i)
    {

    if (arr[i]==rem)
    {
        for(j=i; j<n-1; ++j)
        {
            arr[j] = arr[j+1] ;
            //printf("j+1 th val: %d", arr[j+1]) ;
        }
        ++counts_removed ;
        --n ;
        /*When an element is removed, the size of array decreases by 1, so we wrote --n*/
	/*If the last element is to be removed, the program control will not enter the for loop
	written immediately before this.*/

        --i ;
        //adjust the index suitably after removing the value at that index
        /*once the value at i th index was removed, i.e. it was overridden by (i+1)th value, now i th location/index
        has new value and so this index has to be considered again, so we wrote --i*/
    }
    else
        {
        continue ;
        }
    } // end of for loop

    for(i=0; i<n; ++i)
    {
       printf("%d\t",arr[i]) ;
    }

    printf("\n\n") ;
    printf("---------------Summary---------------\n\n") ;
    printf("Original length of the array: %d\n", len_original) ;
    printf("No. of occurrences of %d that were removed: %d\n", rem, counts_removed) ;
    printf("The length of array after removing all the occurrences of %d: %d", rem, (len_original-counts_removed)) ;

} // end of removeMyNum() function

/*
Code working fine for all cases:
Element to be removed is present at:
1. First index [0th index]
2. Last index [(n-1)th index]
3. Anywhere in the array, not on the extremities
4. Element to be removed is present in series i.e. at the consecutive indexes.
5. Present at multiple indexes i.e. a combination of points 1, 2, 3 & 4.

*/

___________________________________________________________________________________________________

/*A better code for the same task.*/


#include<stdio.h>
void removeMyNum(int [], int, int) ;
void main()
{
    int a[] = {100, 5, 3, 5, 5, 100, 5, 8, 9, 6, 7, 5, 100} ;
    int size = sizeof(a)/sizeof(a[0]) ;
    int rem = 100 ;   //element to be removed

    printf("Actual array size: %d\n", size) ;

    removeMyNum(a, size, rem) ;

} // end of main() function

void removeMyNum(int arr[], int n, int rem)
{
    int i, j ;

    int len_original = n ;
    //original length of the array received by this function

    int counts_removed = 0 ;
    //no. of times the number was encountered and removed

    for(i=0; i<n; ++i)
    {

    if(arr[i]==rem && i==(n-1))
    {   
        printf("\nWe are here (path for last element).\n") ;
        --n ;
        ++counts_removed ;
    }
    else if (arr[i]==rem && i!=(n-1))
    {
        for(j=i; j<n-1; ++j)
        {
            //printf("j: %d", j) ;
            //printf("j+1: %d", (j+1)) ;
            //printf("arr[j]: %d", arr[j]) ;
            //printf("arr[j+1]: %d", arr[j+1]) ;
            arr[j] = arr[j+1] ;
        }
        printf("\nThis was executed (regular path).\n") ;
        ++counts_removed ;
        --n ;
        /*When an element is removed, the size of array decreases by 1, so we wrote --n*/

        --i ;
        //adjust the index suitably after removing the value at that index
        /*once the value at i th index was removed, i.e. it was overridden by (i+1)th value, now i th location/index
        has new value and so this index has to be considered again, so we wrote --i*/
    }
    else
        {
        continue ;
        }
    } // end of for loop

    for(i=0; i<n; ++i)
    {
       printf("%d\t",arr[i]) ;
    }

    printf("\n\n") ;
    printf("---------------Summary---------------\n\n") ;
    printf("Original length of the array: %d\n", len_original) ;
    printf("No. of occurrences of %d that were removed: %d\n", rem, counts_removed) ;
    printf("The length of array after removing all the occurrences of %d: %d", rem, (len_original-counts_removed)) ;

} // end of removeMyNum() function

/*
if the number to be removed is (also) present at the last index, so the next number i.e. the number 
after the last value isn't defined i.e. arr[j+1] th value won't exist. This can throw runtime error. 
So, a separaate if statement has been included which explicitly caters to the situation wherein the 
number to be removed is present at the end.


Code working fine for all cases:
Element to be removed is present at:
1. First index [0th index]
2. Last index [(n-1)th index]
3. Anywhere in the array, not on the extremities
4. Element to be removed is present in series i.e. at the consecutive indexes.
5. Present at multiple indexes i.e. a combination of points 1, 2, 3 & 4.

*/
