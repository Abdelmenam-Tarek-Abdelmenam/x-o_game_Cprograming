#include <stdio.h>
#include <stdlib.h>




char ground[9] = {'-'}; //play ground area


int main()
{
    char current_player_symbol ;
    int current_player =0 ;
    char p1s; // player 1 symbol x-o
    char p2s; //player 2 symbol x-o
    int ans=0 ,win=0;


//draw the play ground
for(int i=0 ;i<=9 ; i++){
    ground[i]='-';
}


     printf("\t\t\t    x&o game \n\t\t\t");


// print a guide for positions to play in
  for(int i=1;i<=3;i++)
  {
      printf("%d\t",i);
  }
  printf("\n\t\t\t");
   for(int i=4;i<=6;i++)
  {
      printf("%d\t",i);
  }
   printf("\n\t\t\t");
   for(int i=07;i<=9;i++)
  {
      printf("%d\t",i);
  }


// take the user input symppols
while (1) {
  printf("\nenter player 1 sympol(x/o)..");
  label:;
  scanf("%s",&p1s);


if ( p1s == 'x' || p1s == 'X'){
    p1s = 'x' ;
    p2s = 'o' ;
    break ;
}
else if ( p1s == 'o' || p1s == 'O' ){
     p1s = 'o' ;
     p2s = 'x' ;
    break ;
}
else{
    printf("sorry you can enter only x or o try again");
}
}


current_player_symbol = p1s ; //


for(int i=0 ;i<9 ; i++)
{
intro(p1s,p2s,current_player);  //function for ui


while(1){
printf(" \n its player %d turn \n",current_player+1);
 scanf("%d",&ans);  //get the playing position
 if(ground[ans]!='-'){
   printf("this place is already played\n") ;
   continue ;
 }
 break ;
}


ground[ans]=current_player_symbol;
intro(p1s,p2s);


checkwin(&win,p1s,p2s);


if(win==1){
  printf("\a\n\t\t player 1 win /who played with %c",p1s); printf("\n") ; printf(" \n\t\t that was a nice game  \n");
        printf("do you want to play again...?(y/n)");
      scanf("%s",&p1s);
       if (p1s=='y'|| p1s=='Y'){ system("cls");return main();}
      else{return 0;
      }
}
else if(win==2){
   printf("\a\n\t\t player 2 win /who played with %c",p2s); printf("\n") ; printf(" \n\t\t that was a nice game  \n");
        printf("do you want to play again...?(y/n)");
      scanf("%s",&p1s);
      if (p1s=='y'|| p1s=='Y'){ system("cls");return main();}
      else{return 0;
      }
}
  ground[ans]=current_player_symbol;
  current_player = !current_player ;
  if(current_player_symbol == 'x')
    {
        current_player_symbol='o';
    }
    else if(current_player_symbol == 'o')
    {
        current_player_symbol='x';
    }
}
  printf("\n no one win");


    return 0;
}
void intro(char p1s,char p2s , int currentolayer){


   system("cls");
  printf("\n\t\t\t    x&o game \n\t");
 printf("player 1 :...%c\n \t",p1s);
  printf("player 2 :...%c\n ",p2s);
   printf("\n shoose the number of the place you want from here");
  printf("\n\t");
  for(int i=1;i<=3;i++)
  {
      printf("%d\t",i);
  }
  printf("\n\t");
   for(int i=4;i<=6;i++)
  {
      printf("%d\t",i);
  }
   printf("\n\t");
   for(int i=7;i<=9;i++)
  {
      printf("%d\t",i);
  }
    printf("\n\t\t\t");
  for(int i=1;i<=3;i++)
  {
      printf("%c\t",ground[i]);
  }
  printf("\n\t\t\t");
   for(int i=4;i<=6;i++)
  {
      printf("%c\t",ground[i]);
  }
   printf("\n\t\t\t");
   for(int i=7;i<=9;i++)
  {
      printf("%c\t",ground[i]);
  }
}


void checkwin(int *win ,char p1s,char p2s)
{
  if(ground[1] == ground[2] && ground[1]==ground[3]){
      if(ground[1]==p1s)
          *win= 1;
      else if(ground[1]==p2s)
          *win= 2;
  }
  else if(ground[4] == ground[5] && ground[4]==ground[6]){
      if(ground[4]==p1s)
          *win= 1;
      else if(ground[4]==p2s)
          *win= 2;
  }
  else if(ground[9] == ground[7] && ground[7]==ground[8]){
      if(ground[9]==p1s)
          *win= 1;
      else if(ground[9]==p2s)
          *win= 2;
  }
  else if(ground[1] == ground[4] && ground[4]==ground[7]){
      if(ground[7]==p1s)
          *win= 1;
      else if(ground[7]==p2s)
          *win= 2;
  }
  else if(ground[2] == ground[5] && ground[5]==ground[8]){
      if(ground[5]==p1s)
          *win= 1;
      else if(ground[5]==p2s)
          *win= 2;
  }
  else if(ground[3] == ground[6] && ground[6]==ground[9]){
      if(ground[3]==p1s)
          *win= 1;
      else if(ground[3]==p2s)
          *win= 2;
  }
  else if(ground[1] == ground[5] && ground[5]==ground[9]){
      if(ground[1]==p1s)
          *win= 1;
      else if(ground[1]==p2s)
          *win=2;
  }
  else if(ground[3] == ground[5] && ground[5]==ground[7]){
      if(ground[7]==p1s)
          *win= 1;
      else if(ground[7]==p2s)
          *win= 2;
  }
  return 0;
}
