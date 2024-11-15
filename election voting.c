#include<stdio.h>

void end_vote(int ,int ,int ,int ,int ,int ) ;	//declaring the function

void main(void )

{
int vote_1, vote_2 ,vote_3 ,vote_4, vote_5, vote_spoilt ;
// vote_1 = vote secured by candidate 1

vote_1 = vote_2 = vote_3 = vote_4 = vote_5 = vote_spoilt = 0 ;
int choice ;

do
{
    printf("WELCOME FOR VOTING \n\nPress\n") ;
    printf("1 to vote for candidate 1 \n") ;
    printf("2 to vote for candidate 2 \n") ;
    printf("3 to vote for candidate 3 \n") ;
    printf("4 to vote for candidate 4 \n") ;
    printf("5 to vote for candidate 5 \n") ;
    printf("4321 to stop the code once the voting is finished \n") ;
//Sinply press 0 to stop voting and display the results

    printf("Please enter your choice \n") ;
    scanf("%d",&choice) ;

    switch(choice)

    {
        case 1: printf("Thank you for voting \n") ;
                printf("You voted for candidate 1 \n\n") ;
                ++vote_1 ;
                break ;

        case 2: printf("Thank you for voting \n") ;
                printf("You voted for candidate 2 \n\n") ;
                ++vote_2 ;
                break ;

        case 3: printf("Thank you for voting \n") ;
                printf("You voted for candidate 3 \n\n") ;
                ++vote_3 ;
                break ;

        case 4: printf("Thank you for voting \n") ;
                printf("You voted for candidate 4 \n\n") ;
                ++vote_4 ;
                break ;

        case 5: printf("Thank you for voting \n") ;
                printf("You voted for candidate 5 \n\n") ;
                ++vote_5 ;
                break ;

        case 4321: printf("VOTING STOPPED \n") ;break ;

        default : printf("INVALID CHOICE \n") ;
        ++vote_spoilt ;
        break ;


    }
}while(choice!=4321);

if(choice==4321)
   end_vote(vote_1,vote_2,vote_3,vote_4,vote_5,vote_spoilt) ;
// call to function


}

void end_vote(int vote_1,int vote_2, int vote_3,int vote_4,int vote_5,int vote_spoilt)
//function definition

{
    printf("\n\n") ;
    printf("Votes secured by candidate 1 are %d\n",vote_1) ;
    printf("Votes secured by candidate 2 are %d\n",vote_2) ;
    printf("Votes secured by candidate 3 are %d\n",vote_3) ;
    printf("Votes secured by candidate 4 are %d\n",vote_4) ;
    printf("Votes secured by candidate 5 are %d\n",vote_5) ;
    printf("Spoilt votes are %d\n",vote_spoilt) ;

}
//code working correctly

/*
The code can be made more dynamic & more useful by using the concept of an array to store values instead of using individual
variables. Initially, at the beginning, the code can be made to ask 'how many candidates are contesting election', say n,
so an array of size n will be made, which will store the votes suitably, say vote[2] location will store the votes secured 
by 2nd candidate and so on. 
Be careful while using array to store votes secured by candidates, especially with array 
indexes. At the beginning of the code itself, decide whether you want to consider 0th index
of the array also to store the votes or you want to start storing the votes from index no. 1
in the array, else it might create confusion at the end. In the 1st case, vote[0] will store 
the votes secured by candidate 1, vote[1] will store the votes secured by candidate 2 and so on.
In the 2nd case, vote[1] will store the votes secured by candidate 1 and so on.

According a function can be made which will calculate max value in array, that will be 
the votes of the person/candidate who would secured the highest votes.
*/
