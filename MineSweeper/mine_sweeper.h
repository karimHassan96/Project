#ifndef MINE_SWEEPER_H_INCLUDED
#define MINE_SWEEPER_H_INCLUDED
extern int x,y,i,j,q,counter_moves, counter_question, counter_flags,flag,numberofmines,n,m,choice;
extern time_t start,endd;
extern double savedtime,total,score;

struct info{
    char player_name[30];
    double player_score;
}player[6],temp,emptyStruct;

void clrscr() {
    system("@cls||clear");
}

void saveBoard(){
FILE*fp=fopen("scoreboard.txt","wb");
for(i=0;i<5;i++){
fwrite(player[i].player_name,sizeof(char),30,fp);
}
for(i=0;i<5;i++){
fwrite(&player[i].player_score,sizeof(double),10,fp);
}

fclose(fp);
}

void loadBoard(){
FILE*fp=fopen("scoreboard.txt","rb");
for(i=0;i<5;i++){

    fread(player[i].player_name,sizeof(char),30,fp);
}
for(i=0;i<5;i++)
    {
    fread(&player[i].player_score,sizeof(double),10,fp);
}
fclose(fp);
}

void sortScoreBoard(struct info player[5]){
     int i,j;
for(i=1;i<=5;i++)
    {
        for(j=0;j<=5-i;j++)
        {
            if(player[j].player_score < player[j+1].player_score)
            {
                struct info temp = player[j];
                player[j] = player[j+1];
                player[j+1] = temp;}}}
 }

int Welcome(){
    while(1){
    printf("1-New Game\n\n2-load Game\n\n3-Show Score Board\n");
    fflush(stdin);
    scanf("%d",&choice);
    printf("\n");
    if(choice==1 || choice==2 || choice==3){
    clrscr();
    break;}}
return choice;}

void timeconverter(double c){
    int a =(int)c%60;
    int d=c/60;
    printf("Your Time is %d : %d\n",d,a);
}

void saveDimensions(){
endd=time(NULL);
FILE*fp=fopen("nm.txt","w");
fprintf(fp,"%d %d %d %d %lf ",n,m,counter_moves,counter_flags,difftime(endd,start));
fclose(fp);
}

void loadDimensions(){
FILE*fp=fopen("nm.txt","r");
fscanf(fp,"%d %d %d %d %lf",&n,&m,&counter_moves,&counter_flags,&savedtime);
fclose(fp);
}

void save(char array1[][m],char array2[][m]){
int i,j;
FILE *fp=fopen("output.txt","w");
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        fprintf(fp,"%c",array1[i][j]);
    }
}
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
       fprintf(fp,"%c",array2[i][j]);
    }
}
fclose(fp);
clrscr();
printf("Your game has been saved\n\n\n\n\n");
}

void load(char array1[][m],char array2[][m]){

int i,j;
FILE *fp=fopen("output.txt","r");
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        array1[i][j]=fgetc(fp);
    }
}
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        array2[i][j]=fgetc(fp);
    }
}
fclose(fp);
}

void openEmptyCells(int i, int j,char arr2[][m], char arr1[][m]){
if(i-1>-1 && j-1>-1 && arr2[i-1][j-1] =='X'){
         if(arr1[i-1][j-1] == ' '){
         arr2[i-1][j-1] = ' ';
         openEmptyCells(i-1,j-1,arr2,arr1);}
        else  arr2[i-1][j-1]=arr1[i-1][j-1];}

        if(i-1>-1 && arr2[i-1][j]=='X'){
         if( arr1[i-1][j] == ' '){
         arr2[i-1][j] = ' ';
         openEmptyCells(i-1,j,arr2,arr1);}
         else arr2[i-1][j]=arr1[i-1][j];}

        if(i-1>-1 && j+1<m && arr2[i-1][j+1] =='X'){
         if(arr1[i-1][j+1] == ' '){
         arr2[i-1][j+1] = ' ';
         openEmptyCells(i-1,j+1,arr2,arr1);}
        else arr2[i-1][j+1]=arr1[i-1][j+1];}

        if(j-1>-1 && arr2[i][j-1] =='X'){
         if(arr1[i][j-1] == ' '){
         arr2[i][j-1] = ' ';
         openEmptyCells(i,j-1,arr2,arr1);}
        else arr2[i][j-1]=arr1[i][j-1];}

        if(j+1<m && arr2[i][j+1] =='X'){
         if(arr1[i][j+1] == ' '){
         arr2[i][j+1] = ' ';
         openEmptyCells(i,j+1,arr2,arr1);}
        else arr2[i][j+1]=arr1[i][j+1];}

        if(i+1<n && j-1>-1 && arr2[i+1][j-1] =='X'){
         if(arr1[i+1][j-1] == ' '){
         arr2[i+1][j-1] = ' ';
         openEmptyCells(i+1,j-1,arr2,arr1);}
        else arr2[i+1][j-1]=arr1[i+1][j-1];}

        if(i+1<n && arr2[i+1][j] =='X'){
         if(arr1[i+1][j] == ' '){
         arr2[i+1][j] = ' ';
         openEmptyCells(i+1,j,arr2,arr1);}
        else arr2[i+1][j]=arr1[i+1][j];}

        if(i+1<n && j+1<m && arr2[i+1][j+1] =='X'){
         if(arr1[i+1][j+1] == ' '){
         arr2[i+1][j+1] = ' ';
         openEmptyCells(i+1,j+1,arr2,arr1);}
        else arr2[i+1][j+1]=arr1[i+1][j+1];}
}

void printarray(char arr[][m]){
    clrscr();
    printf("Number of moves = %d\n\n",counter_moves);
    printf("Number of remaining flags = %d\n\n",(numberofmines-counter_flags));
    printf("Number of question marks = %d\n\n",counter_question);
    int i,j,k,l;
    printf("    ");
    for(l=0;l<n;l++){
        printf("%d |  ",l);
    }
    printf("\n");
     for (k=0;k<=2*m+1;k++){
           printf("--");
       }
        printf("\n");
    for (i = 0; i < n; i++){
        printf("%d |",i);
      for (j = 0; j < m; j++){
        printf(" %c | ", arr[i][j]);
      }
       printf("\n");
       for (k=0;k<=2*m+1;k++){
           printf("--");
       }
        printf("\n");}}



char count_flags(char arr[][m]){
    int counterofflags=0;
    char charcounterofflags;

        if(x-1>-1 && y-1>-1 && arr[x-1][y-1] == 'F')
         counterofflags++;
        if(x-1>-1 && arr[x-1][y] == 'F')
         counterofflags++;
        if(x-1>-1 && y+1<m && arr[x-1][y+1] == 'F')
        counterofflags++;
        if(y-1>-1 && arr[x][y-1] == 'F')
        counterofflags++;
        if(y+1<m && arr[x][y+1] == 'F')
        counterofflags++;
        if(x+1<n && y-1>-1 && arr[x+1][y-1] == 'F')
        counterofflags++;
        if(x+1<n && arr[x+1][y] == 'F')
        counterofflags++;
        if(x+1<n && y+1<m && arr[x+1][y+1] == 'F')
        counterofflags++;

        charcounterofflags = counterofflags+'0';           //int to char
       return charcounterofflags;
}

void randomize_mines(char arr[][m]) {

 int i,a,b;
  srand(time(NULL));
 for(i = 0; i < numberofmines;i++){
         a = rand() % n ;
         b = rand() % m;
         if(arr[a][b] != '*'){
         arr[a][b] = '*';
    }
    else{
         i--;
}}}

void initialize_grid(char arr[][m]) {
  int i,j;

       for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           arr[i][j]=' ';
}}}

void initialize_interact(char arr[][m]) {
  int i,j;

       for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          arr[i][j]='X';}}}

void count_mines(char arr[][m]) {
    int counterOfMines=0,i,j;
    char charcounterOfMines;

    for(i=0;i<n;i++){
    counterOfMines =0;
    for(j=0;j<m;j++){
     counterOfMines=0;
    if(arr[i][j] == '*'){
    continue;}

    else{
        if(i-1>-1 && j-1>-1 && arr[i-1][j-1] == '*')
         counterOfMines++;
        if(i-1>-1 && arr[i-1][j] == '*')
         counterOfMines++;
        if(i-1>-1 && j+1<m && arr[i-1][j+1] == '*')
        counterOfMines++;
        if(j-1>-1 && arr[i][j-1] == '*')
        counterOfMines++;
        if(j+1<m && arr[i][j+1] == '*')
        counterOfMines++;
        if(i+1<n && j-1>-1 && arr[i+1][j-1] == '*')
        counterOfMines++;
        if(i+1<n && arr[i+1][j] == '*')
        counterOfMines++;
        if(i+1<n && j+1<m && arr[i+1][j+1] == '*')
        counterOfMines++;
        }
        if(counterOfMines==0){arr[i][j]=' ';}
        else{

        charcounterOfMines = counterOfMines+'0';           //int to char
        arr[i][j]=charcounterOfMines;
}}}}

void lost(char a[][m],char b[][m]){
      clrscr();
      endd=time(NULL);
        total=savedtime+difftime(endd,start);
        int i,j;
        timeconverter(total);
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j]=='F'&&a[i][j]!='*'){
                a[i][j]='-';
            }
            if(b[i][j]=='X'&&a[i][j]=='*'){
                a[i][j]='M';
            }}}
     for(i=-1;i<2;i++){
        for(j=-1;j<2;j++){

        if(b[x+i][y+j]!='F'&&a[x+i][y+j]=='M'){
        a[x+i][y+j]='!';
     }
        }}
     printarray(a);}

void win(struct info player[6],char arr[][m]){

                        clrscr();
                        printf("                Congratulations , You Won ! \n\n");
                        endd=time(NULL);
                        timeconverter(difftime(endd,start));
                        printarray(arr);
                        score=((pow(n,4)*pow(m,4))/(difftime(endd,start)*counter_moves));
                        printf("Your score is %.1lf\n",score);
                        printf("Enter your name please!: ");
                        getchar();
                        gets(player[5].player_name);
                        strlwr(player[5].player_name);
                        player[5].player_score=score;
                        for(i=0;i<5;i++){
                            if(strcmp(player[5].player_name,player[i].player_name) == 0){
                                player[5]=emptyStruct;
                                player[i].player_score+=score;

                            break;
        }}}

void printScoreBoard(){
    for(i=0;i<6;i++){
                printf("%s %.1lf \n",player[i].player_name,player[i].player_score);
            }

}

void get_ready(char arr1[][m],char arr2[][m]){
    initialize_grid(arr2);
    initialize_interact(arr1);
    randomize_mines(arr2);
    count_mines(arr2);
    printarray(arr1);
    }

void openOpenedCells(char arr1[][m],char arr2[][m]){

    if(x-1>-1 && y-1>-1 && arr1[x-1][y-1] != 'F'){
                if(arr2[x-1][y-1]=='*'){flag=1;}
                else {arr1[x-1][y-1]=arr2[x-1][y-1];}}

                if(x-1>-1 && arr1[x-1][y] != 'F'){
                if(arr2[x-1][y]=='*'){flag=1;}
                else {arr1[x-1][y]=arr2[x-1][y];}}

                if(x-1>-1 && y+1<m && arr1[x-1][y+1] != 'F'){
                if(arr2[x-1][y+1]=='*'){flag=1;}
                else {arr1[x-1][y+1]=arr2[x-1][y+1];}}

                if(y-1>-1 && arr1[x][y-1] != 'F'){
                if(arr2[x][y-1]=='*'){flag=1;}
                else {arr1[x][y-1]=arr2[x][y-1];}}

                if(y+1<m && arr1[x][y+1] != 'F'){
                if(arr2[x][y+1]=='*'){flag=1;}
                else {arr1[x][y+1]=arr2[x][y+1];}}

                if(x+1<n && y-1>-1 && arr1[x+1][y-1] != 'F'){
                if(arr2[x+1][y-1]=='*'){flag=1;}
                else {arr1[x+1][y-1]=arr2[x+1][y-1];}}

                if(x+1<n && arr1[x+1][y] != 'F'){
                if(arr2[x+1][y]=='*'){flag=1;}
                else {arr1[x+1][y]=arr2[x+1][y]; }}

                if(x+1<n && y+1<m && arr1[x+1][y+1] != 'F'){
                if(arr2[x+1][y+1]=='*'){flag=1;}
                else {arr1[x+1][y+1]=arr2[x+1][y+1];}}

                if (flag==0){counter_moves++; printarray(arr1);}
                if (flag==1){lost(arr2,arr1); }}

void startgame(){

loadBoard();
while(1){
     clrscr();
     printf("Enter Dimensions : ");
     fflush(stdin);
     scanf("%d %d",&n,&m);
     printf("\n");
     if(n<=30 && n>=2 && m<=30 && m>=2){
     break;}}
     start=time(NULL);

    char grid[n][m],interact[n][m],operation;

    numberofmines=1+(n*m)/10;

    get_ready(interact,grid);

   while(flag==0){


    while(1){
     printf("\nEnter Operation ( O , F , ? , U , Z , S ) and location : \n");
     fflush(stdin);
     scanf(" %c",&operation);
     if(operation=='S'){break;}
     scanf("%d %d",&x,&y);

     printf("\n");
    if(x<n && x>-1 && y<m && y>-1 && (operation=='O' || operation=='F' || operation=='?' || operation=='U' || operation=='S' || operation=='Z')){
        break;
    }}

        switch(operation){

       case 'O':
                if(counter_moves==0 && grid[x][y]=='*'){

                    while(grid[x][y]=='*'){
                        initialize_grid(grid);
                        randomize_mines(grid);
                        count_mines(grid);
            }
                        counter_moves++;
                        interact[x][y]=grid[x][y];
                        printarray(interact);
       }
                else{if(interact[x][y]=='X'){
                    if(grid[x][y]==' '){
                        counter_moves++;
                        openEmptyCells(x,y,interact,grid);
                        printarray(interact);
            }
                else if(grid[x][y]=='*'){
                    counter_moves++;
                    lost(grid,interact);  flag=1;

            }
                else if(grid[x][y]!='*'){
                    counter_moves++;
                    interact[x][y]=grid[x][y];
                    printarray(interact);
            }}}
            break;

      case 'F': if(interact[x][y]=='X'){
                interact[x][y] = 'F';
                counter_flags++;
                counter_moves++;
                printarray(interact);
                break;}
                else continue;

      case '?': if(interact[x][y]=='X'){
                    interact[x][y] = '?';
                    counter_moves++;
                    counter_question++;
                    printarray(interact);
                    break;}
                else continue;

      case 'U': if(interact[x][y]=='F' || interact[x][y]=='?'){
                    if(interact[x][y]=='F'){counter_flags--;}
                    else if(interact[x][y]=='?'){counter_question--;}
                        interact[x][y] = 'X';
                        counter_moves++;
                        printarray(interact);
                        break; }
                else continue;

      case 'Z':
               if(interact[x][y]!='X'&&interact[x][y]!='F'){
                    if(count_flags(interact)==grid[x][y] && ((interact[x][y]>='1' && interact[x][y]<='100') || (interact[x][y]==' '))){
                        openOpenedCells(interact,grid);
                        break;}}
               else continue;


      case 'S':
               save(grid,interact);
               saveDimensions(n,m);
               flag=1;

        }

                if(flag==0){
                    int i,j,countwin=0;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            if (grid[i][j]==interact[i][j]){
                                countwin++;
                }
                            if (grid[i][j]=='*'&&interact[i][j]=='F'){
                                countwin++;
                }}}

                    if(countwin==n*m){
                        win(player,interact);
                        flag=1;
                        sortScoreBoard(player);
                        saveBoard();
}}
    }}

void loadgame(){
        loadDimensions();
        char interact[n][m],grid[n][m];
        load(grid,interact);
        printarray(interact);
        start=time(NULL);
        char operation;

        while(flag==0){
            while(1){
                printf("\nEnter Operation ( O , F , ? , U , S ) : \n");
                fflush(stdin);
                scanf(" %c",&operation);
                printf("\nEnter x,y :\n ");
                scanf("%d %d",&x,&y);
                printf("\n");
                if(x<n && x>-1 && y<m && y>-1 && (operation=='O' || operation=='F' || operation=='?' || operation=='U' || operation=='S')){
                    break;
    }}

       switch(operation){

       case 'O':
                if(counter_moves==0 && grid[x][y]=='*'){

                    while(grid[x][y]=='*'){
                        initialize_grid(grid);
                        randomize_mines(grid);
                        count_mines(grid);
            }
                        counter_moves++;
                        interact[x][y]=grid[x][y];
                        printarray(interact);
       }
                else{if(interact[x][y]=='X'){
                    if(grid[x][y]==' '){
                        counter_moves++;
                        openEmptyCells(x,y,interact,grid);
                        printarray(interact);
            }
                else if(grid[x][y]=='*'){
                    counter_moves++;
                    lost(grid,interact);  flag=1;

            }
                else if(grid[x][y]!='*'){
                    counter_moves++;
                    interact[x][y]=grid[x][y];
                    printarray(interact);
            }}}
            break;

      case 'F': if(interact[x][y]=='X'){
                interact[x][y] = 'F';
                counter_flags++;
                counter_moves++;
                printarray(interact);
                break;}
                else continue;

      case '?': if(interact[x][y]=='X'){
                    interact[x][y] = '?';
                    counter_moves++;
                    counter_question++;
                    printarray(interact);
                    break;}
                else continue;

      case 'U': if(interact[x][y]=='F' || interact[x][y]=='?'){
                    if(interact[x][y]=='F'){counter_flags--;}
                    else if(interact[x][y]=='?'){counter_question--;}
                        interact[x][y] = 'X';
                        counter_moves++;
                        printarray(interact);
                        break; }
                else continue;

      case 'Z':
               if(interact[x][y]!='X'&&interact[x][y]!='F'){
                    if(count_flags(interact)==grid[x][y] && ((interact[x][y]>='1' && interact[x][y]<='100') || (interact[x][y]==' '))){
                        openOpenedCells(interact,grid);
                        break;}}
               else continue;


      case 'S':
               save(grid,interact);
               saveDimensions(n,m);
               flag=1;
       }
                if(flag==0){
                    int i,j,countwin=0;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            if (grid[i][j]==interact[i][j]){
                                countwin++;
                }
                            if (grid[i][j]=='*'&&interact[i][j]=='F'){
                                countwin++;
                }}}

                    if(countwin==n*m){
                       win(player,interact);
                sortScoreBoard(player);
                saveBoard();
}}
}}


#endif // MINE_SWEEPER_H_INCLUDED
