#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Case {
    int isHidden;
    int value;
}Case;

void Game();
void Init();
int getRandom();
int PlayAgain();
void ShowGrid();
int VerifWin();

int main()
{
    int* play = 1;
    while (play) {
        Game(&play);
    }
}


void Game(int* play) {
    int i;
    int x;
    int y;
    int number;
    int verif;
    Case** T = (Case**)malloc(sizeof(Case*) * 9);
    for (i = 0; i < 9; i++) {
        T[i] = (Case*)malloc(sizeof(Case) * 9);
    }
    Init(T);
    while (1) {
        verif = VerifWin(T);
        ShowGrid(T);
        if (verif == 1) {
            PlayAgain(play);
            for (i = 0; i < 9; i++) {
                free(T[i]);
            }
            free(T);
            break;
        }
        puts("Quelle case souhaitez vous tenter");
        while (1) {
            if (scanf_s("%d/%d", &x, &y)) {
                break;
            }
        }
        puts("Quelle chiffre souhaitez-vous y inserer");
        while (1) {
            if (scanf_s("%d", &number)) {
                break;
            }
        }
        if (T[y][x].value == number) {
            T[y][x].isHidden = 0;
        }
        else {
            printf("Dommage\n");
        }
    }
}


void Init(Case** T) {
    int i;
    int j;
    int random;
    int random2;
    int** numbers = (int**)malloc(sizeof(int*) * 9);
    for (i = 0; i < 9; i++) {
        numbers[i] = (int*)malloc(sizeof(int) * 9);
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            numbers[i][j] = j;
        }
    }
    for (i = 0; i < 9; i++) {
        random = getRandom(9);
        for (j = 0; j < 9; j++) {
            random2 = getRandom(9);
            T[i][j].value = numbers[i][random2];
            while (1) {
                if (random2 + 1 < 9) {
                    numbers[i][random2] = numbers[i][random2 + 1];
                    break;
                }if (random2 - 1 > 0){
                    numbers[i][random2] = numbers[i][random2 - 1];
                    break;
                }
            }
            T[i][j].isHidden = 1;
        }
        T[i][random].isHidden = 0;
    }
}

int getRandom(int max)
{
    int random = rand() % max;
    return random;
}

int VerifWin(Case** T) {
    int i;
    int j;
    int counter = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (T[i][j].isHidden == 0) {
                counter++;
            }
        }
    }
    if (counter == 9 * 9) {
        return 1;
    }
    return 0;
}



void ShowGrid(Case** T) {
    int i;
    int j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (T[i][j].isHidden) {
                printf("X ");
            }
            else {
                printf("%d ", T[i][j].value);
            }
        }
        printf("\n");
    }
}

int PlayAgain(int* play) {
    int yes;
    puts("Voulez vous rejouer?");
    while (1) {
        if (scanf_s("%d", &yes)) {
            if (yes) {
                break;
            }
            else {
                *play = 0;
                break;
            }
        }
    }
}