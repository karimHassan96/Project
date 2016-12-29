#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "mine_sweeper.h"
int x,y,i,j,q,counter_moves, counter_question, counter_flags,flag,numberofmines,n,m,choice;
time_t start,endd;
double savedtime,total,score;

int main(){
    system("COLOR 70");
    choice=Welcome();
    if (choice==1){
            startgame();
            }
    else if(choice==2){
            loadgame();
            }
    else if (choice==3){
            loadBoard();
            printScoreBoard();
      }
    return 0;
 }
