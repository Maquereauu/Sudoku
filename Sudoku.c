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

int main()
{
    int* play = 1;
    while (play) {
        Game(&play);
    }
}


void Game(int* play) {
    int i;
    Case** T = (Case**)malloc(sizeof(Case*) * 9);
    for (i = 0; i < 9; i++) {
        T[i] = (Case*)malloc(sizeof(Case) * 9);
    }
    Init(T);
    while (1) {

    }
}


void Init(Case** T) {
    int i;
    int j;
    int** numbers = (int**)malloc(sizeof(int*) * 9);
    for (i = 0; i < 9; i++) {
        numbers[i] = (int*)malloc(sizeof(int) * 9);
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            T[i][j].value = getRandom(9);

        }
    }
}

int getRandom(int max)
{
    int random = rand() % max;
    return random;
}

int PlayAgain(int* play) {

}