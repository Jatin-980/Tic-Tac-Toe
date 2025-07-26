#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void takeinput(char arr[][3],int place , char replace);
void printoutput(char arr[][3]);
int computer_move(char arr[][3] , char inputs[9],int count);
int check_win(char arr[][3]);

int main(){
    
    srand(time(NULL));
    char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int exit=0;
    char place;
    char inputs[9], count=0;;
    printf("Welcome to the game of tic tac toe !! \n");
    printoutput(arr);
    int go=1;
    for(int i=0 ; i<9 ; i++){
        while(go==1){
            go=0;
            printf("Enter place : ");
            scanf("%c",&place); 
            for(int i=0 ; i<count ; i++){
                if(inputs[i]==place){
                    printf("invalid input...try again !!\n");
                    go=1;
                }
            }
            while(getchar()!='\n');
        }
        inputs[count]=place;
        go=1;
        count++;
        takeinput(arr,place,'X');
        printoutput(arr);
        exit = check_win(arr);
        if(exit==1){
            return 0;
        }
        printf("Computer's move !\n");
        computer_move(arr,inputs,count);
        count++;
        printoutput(arr);
        exit = check_win(arr);
        if(exit==1){
            return 0;
        }
    }
    printf("Draw !!\n");
    return 0;
}

int check_win(char arr[][3]){
    for(int i=0 ; i<3 ; i++){
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == arr[i][2] ){
            if(arr[i][0]=='X'){
                printf("You won !! Hurray !!\n");
            }
            else {
                printf("\nComputer won !!");
            }
            return 1;
        }
        if(arr[0][i] == arr[1][i] && arr[1][i]== arr[2][i] && arr[0][i]==arr[2][i]){
            if(arr[0][i]=='X'){
                printf("You won !! Hurray !!\n");
            }
            else {
                printf("\nComputer won !!");
            }
            return 1;
        }
    }
    if(arr[0][0]==arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == arr[2][2]){
        if(arr[0][0]=='X'){
                printf("You won !! Hurray !!\n");
            }
            else {
                printf("\nComputer won !!");
            }
        return 1;
    }
    if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && arr[2][0]== arr[0][2]){
        if(arr[2][0]=='X'){
                printf("You won !! Hurray !!\n");
            }
            else {
                printf("\nComputer won !!");
            }
        return 1;
    }
    return 0;
}

int computer_move(char arr[][3] , char inputs[9] , int count){
    int random_place=0;
    int found=0;
    while(found==0){
        random_place = (rand()%9) + 1; 
        if(random_place!=0){
            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    int n= arr[i][j] - '0';
                    if(random_place == n){
                        arr[i][j] = 'O';
                        switch(random_place){
                            case 1 :  inputs[count]= '1'  ; break ;
                            case 2 :  inputs[count]= '2'  ; break ;
                            case 3 :  inputs[count]= '3'  ; break ;
                            case 4 :  inputs[count]= '4'  ; break ;
                            case 5 :  inputs[count]= '5'  ; break ;
                            case 6 :  inputs[count]= '6'  ; break ;
                            case 7 :  inputs[count]= '7'  ; break ;
                            case 8 :  inputs[count]= '8'  ; break ;
                            case 9 :  inputs[count]= '9'  ; break ;
                        }
                        found = 1;
                    }     
                }
            }
        }
    }   
}

void takeinput(char arr[3][3],int place , char replace){
    switch(place){
        case '1' : arr[0][0] = replace ; break ;
        case '2' : arr[0][1] = replace ; break ;
        case '3' : arr[0][2] = replace ; break ;
        case '4' : arr[1][0] = replace ; break ;
        case '5' : arr[1][1] = replace ; break ;
        case '6' : arr[1][2] = replace ; break ;
        case '7' : arr[2][0] = replace ; break ;
        case '8' : arr[2][1] = replace ; break ;
        case '9' : arr[2][2] = replace ; break ;
    }
}

void printoutput(char arr[][3]){
    printf("---------\n");
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            printf(" %c ",arr[i][j]);
        }
        printf("\n");
    }
    printf("---------\n");
}