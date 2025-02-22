#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "global.h"

void print_rules(){
    printf("Welcome to the Hangman!");
    printf("Select category and difficulty");
    printf("You have 6 guesses");
    printf("Have fun!");
}

void print_progress_bar(int tries_left){
    if (tries_left == 6){
        printf("+------------+\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|     0      |\n");
        printf("|    /|\\     |\n");
        printf("|    / \\     |\n");
        printf("+------------+\n");
    }
    if (tries_left == 5){
        printf("+------------+\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|     0      |\n");
        printf("| |  /|\\     |\n");
        printf("|/|\\ / \\     |\n");
        printf("+------------+\n");
    }
    if (tries_left == 4){
        printf("+------------+\n");
        printf("|            |\n");
        printf("| |           |\n");
        printf("| |           |\n");
        printf("| |           |\n");
        printf("| |    0      |\n");
        printf("| |  /|\\     |\n");
        printf("|/|\\ / \\     |\n");
        printf("+------------+\n");
    }
    if (tries_left == 3){
        printf("+------------+\n");
        printf("|  _________  |\n");
        printf("| |           |\n");
        printf("| |           |\n");
        printf("| |           |\n");
        printf("| |    0      |\n");
        printf("| |  /|\\     |\n");
        printf("|/|\\ / \\     |\n");
        printf("+------------+\n");
    }
    if (tries_left == 2){
        printf("+------------+\n");
        printf("|  _________  |\n");
        printf("| |         | |\n");
        printf("| |           |\n");
        printf("| |           |\n");
        printf("| |    0      |\n");
        printf("| |  /|\\     |\n");
        printf("|/|\\ / \\     |\n");
        printf("+------------+\n");
    }
    if (tries_left == 1){
        printf("+------------+\n");
        printf("|  _________  |\n");
        printf("| |         | |\n");
        printf("| |    _____| |\n");
        printf("| |    |      |\n");
        printf("| |    0      |\n");
        printf("| |  /|\\     |\n");
        printf("|/|\\ / \\     |\n");
        printf("+------------+\n");
    }
}

void print_game_state(game_t *game){
    
    printf("level - %d\n", game->level);
    printf("category - %s\n", game->category);
    printf("guesses left - %d\n", game->tries_left);
    print_progress_bar(game->tries_left);
    for (int i = 0; i < strlen(game->word); i++) {
        int found = 0;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (game->word[i] == game->chosen_alphas[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("%c ", game->word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
    for (char i = 'a'; i <= 'z'; i++) {
        printf("%c", i);
    }
    printf("\n");

    for (char c = 'a'; c <= 'z'; ++c) {
        int found = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (game->chosen_alphas[i] == c) {
                found = 1;
                break;
            }
        }
        
        if (found) {
            printf("X");
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int main(){
    game_t test_game;

    test_game.level = 1;
    test_game.hangman_state = 2;

    test_game.tries_left = 5;

    strcpy(test_game.category, "Животные");
    strcpy(test_game.word, "cat");
    strcpy(test_game.guessed_word, "");
    for(int i=0;i<ALPHABET_SIZE;i++) test_game.chosen_alphas[i]= '\0';
    test_game.chosen_alphas[0] ='c'; 
    test_game.chosen_alphas[1] ='a';
    print_game_state(&test_game);

    return 0;
}