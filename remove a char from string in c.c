
#include <stdio.h>
#include <string.h>

void main()
{
    //char str[10] ;      //writing no is compulsory if string is not initialized
    char str[] = "ddabcddefghd" ; //double quotes are needed if more than 1 chars are present
    //no need to declare the size if we are initializing the string
    
    char rem[] = "d" ;  //prefer double quotes when using square brackets []
    //char rem2 = 'e' ;   // no errors
    //char rem3 = "f" ;   //error
    
    int i = 0 ;
    int len = strlen(str) ;
    int original_len = strlen(str) ;
    int j ;
    //printf("%c", rem[0]);   //d
    
    while(str[i]!='\0')
    {
        if(str[i]==rem[0] && i!=(len-1))
        {
            printf("1st if executed.\n");
            for(j=i; j<len-1; ++j)
            {
                str[j] = str[j+1] ;
            }
            --len ;
            --i ;
        }
        else if(str[i]==rem[0] && i==(len-1))
        {
            printf("2nd if executed.\n");
            --len ;
            break ;
	    /* without this break, the code doesn't work properly if the element to be removed
	    is present at the last position in the string. */
        }

        ++i ;
    } // end of while() loop
    
    for(i=0; i<len; ++i)
    {
        printf("%c\t", str[i]) ;
    }
    printf("\nlen of string after removing character %c: %d", rem[0], len) ;
    
} // end of main() function

/*

Code working fine for all cases:
Element to be removed is present at:
1. First index [0th index]
2. Last index [(n-1)th index]
3. Anywhere in the array, not on the extremities
4. Element to be removed is present in series i.e. at the consecutive indexes.
5. Present at multiple indexes i.e. a combination of points 1, 2, 3 & 4.

*/
