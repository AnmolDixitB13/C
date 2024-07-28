#include<stdio.h>

void main()
{
    //int data[] = {3, 6, 2, 4, 5, 3, 6, 9, 2, 7, 5, 4, 3, 6} ;
    int data[] = {3, 6, 9, 2, 4, 5, 3, 6, 9, 2, 7, 5, 4, 3, 6, 3, 6, 9, 2, 4, 6, 0, 1, 3, 6, 9, 2} ;
    int pattern[] = {3, 6, 9, 2} ;
    
    int i, j, k ;
    int count = 0 ;
    
    int start, stop ;
    
    int size_data = sizeof(data)/sizeof(data[0]) ;
    int size_pattern = sizeof(pattern)/sizeof(pattern[0]) ;
    
    printf("Data array size: %d\n", size_data) ;
    printf("Pattern array size: %d\n", size_pattern) ;
    
    for(i=0; i<size_data; ++i)
    {   printf("Entered 1st for.\n") ;
        if(data[i]==pattern[0])
        
        {   /*1st element of the pattern has already been matched outside, so now start comparing the 
            next element in input array (i+1) th element of the data array with 2nd ELEMENT OF PATTERN i.e. at k=1 and not k=0*/
            
            for(j=i+1, k=1; j<size_data, k<size_pattern; ++j, ++k)
            {
                if(data[j] == pattern[k])
                {   
                    printf("Entered inner if.\n") ;
                    ++count ;
                }
                else
                {   
                    count = 0 ;//reinitialize count to 0
                    //--i ; 
                    // do not use it, code enters infinite loop
                    break ;
                }
                //--i ;
                //do not use it, code enters infinite loop
                
            }
            if(count == (size_pattern-1))
            /*1st element is matched outside the 2nd for loop, so count value will be < 1 wrt size_pattern*/
            {
                printf("Pattern is present at indexes from %d to %d.\n", (j-size_pattern), (j-1)) ;
                //value of j starts from i+1, so we subtract 1 to get the proper limits
                count = 0 ;     //reinitialize count to 0
                
                start = j-size_pattern ;
                stop = j-1 ;
                printf("\nj: %d", j) ;
                printf("\nStart: %d", start) ;
                printf("\nStop: %d\n\n", stop) ;
                
                for(i=start; i<=stop; ++i)
                {
                    for(j=start; j<size_data-1; ++j)
                    {
                        data[j] = data[j+1] ;
                    }
                    --size_data ;
                }
               
                --i ; // new addition
                //--i ; // new addition
                
            }
        }
        else
        {
            continue ;
            --i ;
            //count = 0 ;     //new addition
            
        }
    }
    printf("Final array:\n") ;
    for(i=0; i<size_data; ++i)
    {
        printf("%d\t", data[i]) ;
    }
}

/*
This code is working fine, but for 1 input array (written below), it is not working fine. It is 
removing 3 out of 4 occurrences of the pattern to be removed from the input array.

{3, 6, 9, 2, 4, 5, 3, 6, 9, 2, 7, 5, 4, 3, 6, 3, 6, 9, 2, 4, 6, 0, 1, 3, 6, 9, 2} ;
*/
________________________________________________________________________________________

//Improved version of the code

#include <stdio.h>

void main() {
    int data[] = {3, 6, 9, 2, 4, 5, 3, 6, 9, 2, 7, 5, 4, 3, 6, 3, 6, 9, 2, 4, 6, 0, 1, 3, 6, 9, 2};
    int pattern[] = {3, 6, 9, 2};
    
    int size_data = sizeof(data) / sizeof(data[0]);
    int size_pattern = sizeof(pattern) / sizeof(pattern[0]);
    
    int i, j, k;
    int found;
    
    for (i = 0; i <= size_data - size_pattern; ++i) {
        found = 1;
        for (j = 0; j < size_pattern; ++j) {
            if (data[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        
        if (found) {
            // Shift elements left to overwrite the pattern
            for (j = i; j < size_data - size_pattern; ++j) {
                data[j] = data[j + size_pattern];
            }
            size_data -= size_pattern;  // Adjust size_data accordingly
            i -= 1;  // Backtrack i to recheck current position
        }
    }
    
    printf("Final array:\n");
    for (i = 0; i < size_data; ++i) {
        printf("%d\t", data[i]);
    }
}
