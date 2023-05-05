#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char player_s (){ 
    char action ;
    printf ("[r]ock [p]aper [s]cissors [q]uit : \n ");
    scanf("%c",&action);
    return action ;
    }
char computer_s(){
    char s [] = {'r', 'p' , 's'} ;
    return s[rand()%3] ;
}

int main () {

    srand(time(NULL));

    char player , computer ;

    player = player_s();

    while (player !='q'){

    computer = computer_s();
    
    printf ("player : %c VS computer : %c \n",player,computer);
    
        if (player == computer ) {

            printf(" you draw \n");
        }
        else {

            if ((player == 'r' && computer == 's') || (player == 'p' && computer == 'r') || (player == 's' && computer == 'p')){
                
            printf(" you win \n");

            }
            else{

            printf(" you lose \n");

            }
        }
  
    player = player_s(); 
    } 
}
