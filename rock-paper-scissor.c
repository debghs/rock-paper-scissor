//rock-paper-scissor game (player vs computer)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void judgement( int a, int b, int *x,int *y);
void print_result( int a , int b );
int main()
   {
    char s1[5]="rock";
    char s2[6]="paper";
    char s3[8]="scissor";
    char p_guess[8];
    char g_guess[8];
    char buf;
    int n,j,r,p_score=0,g_score=0;
    
    printf("\n       ______ROCK-PAPER-SCISSOR______   \n\n");
    printf("\n     WELCOME TO THIS WONDERFUL GAME.   ");
    printf("\n\n     THE GOAL HERE IS TO GUESS ONE FROM EITHER 'ROCK','PAPER, OR 'SCISSOR', AND BET ON THAT, AS WOULD THE GAME. ");
    printf("\n\n     IF THE GUESSES MATCH, THEN IT IS A DRAW. ");
    printf("\n\n     BUT IF THEY DON'T, THEN EITHER YOU OR THE GAME GETS ON TOP. ");
    printf("\n\n     CHOOSE THE NUMBER OF ROUNDS YOU WISH TO PLAY AND GAME ON. ");
    printf("\n\n     MAY THE MOST INTUITIVE WIN. ");
    
    printf("\n\n\n     Enter Number of Round(s): ");
    scanf("%d",&r);
    scanf("%c",&buf);
    system("clear");
    for(int a=0 ; a<r ; a++ )
    {
     srand(time(0));
     n = (rand() % 3)+1;
     //printf("%d",n);
     
    if(n==1)
      {
       strncpy(g_guess,s1,5);
      }
    if(n==2)
      {
       strncpy(g_guess,s2,6);
      }
    if(n==3)
      {
       strncpy(g_guess,s3,8);
      }
      
     printf("\n\n      Enter Your Guess: ");
     scanf("%s", p_guess);
     scanf("%c",&buf);  //to counter stdin buffer
     for( int i = 0; i < (strlen(p_guess)); i++)  //to handle weird inputs 
        {
         p_guess[i] = tolower(p_guess[i]);
        }
     while(strcmp(p_guess,s1)!=0 && strcmp(p_guess,s2)!=0 && strcmp(p_guess,s3)!=0)  //to ensure legit command
          {
           printf("\n\n      Enter Your Guess: ");
           scanf("%s", p_guess);
           scanf("%c",&buf);
           for( int i = 0; i < (strlen(p_guess)); i++)  //to handle weird inputs 
              {
               p_guess[i] = tolower(p_guess[i]);
              }
          }
    

     if( strcmp(p_guess,s1) == 0 )
       {
        j=1;
       }
     if( strcmp(p_guess,s2) == 0 )
       {
        j=2;
       }
     if( strcmp(p_guess,s3) == 0 )
       {
        j=3;
       }
    
     printf("\n      Your guess: %s , Game's guess: %s \n", p_guess, g_guess);
     printf("\n      Status: ");
     
     judgement( n , j , &p_score , &g_score );
    } 
   
    print_result( p_score , g_score );

    return 0;
   }

void print_result( int n1 , int n2 )
    {
     printf("\n\n      Player's Score = %d , Game's Score = %d ", n1 , n2);
    
    if(n1>n2)
      {
       printf("\n\n      Player Wins! ");
      }
  else if(n1==n2)  
      {
       printf("\n\n      It's A Draw! ");
      }
  else
      {
       printf("\n\n      Game wins! ");
      }

    }
    
void judgement( int p, int q, int *plr ,int *gm )
    {
     if(p==q)
       {
        printf(" Draw(0)");
       }
     if(p==1 && q==2)
       {
        printf(" Win(+1)");
        (*plr)++;
       } 
     if(p==1 && q==3)
       {
        printf(" Loss(-1)");
        (*gm)++;
       }
     if(p==2 && q==1)
       {
        printf(" Loss(-1)");
        (*gm)++;
       }
     if(p==2 && q==3)
       {
        printf(" Win(+1)");
        (*plr)++;
       }
     if(p==3 && q==1)
       {
        printf(" Win(+1)");
        (*plr)++;
       }
     if(p==3 && q==2)
       {
        printf(" Loss(-1)");
        (*gm)++;
       }

    }