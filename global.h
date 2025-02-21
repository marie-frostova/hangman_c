#pragma once

#define ALPHABET_SIZE 26
#define MAX_WORD_LEN 50
#define MAX_WORDS_LEVEL_SIZE 10
#define MAX_LVL 3
#define MAX_CATEGORIES_CNT 5
#define MAX_TRIES 6

typedef struct {
    int level;
    int hangman_state;
    int tries_left;
    char category[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    char guessed_word[MAX_WORD_LEN];
    char chosen_alphas[ALPHABET_SIZE];
} game_t;

typedef struct {
    char words[MAX_WORDS_LEVEL_SIZE][MAX_WORD_LEN];
    int words_cnt;
} words_level_t;

typedef struct {
    char category[MAX_WORD_LEN];
    words_level_t words_lvls[MAX_LVL];
} category_words_t;

typedef struct {
    category_words_t category_words[MAX_CATEGORIES_CNT];
    int categories_cnt;
} categories_t;