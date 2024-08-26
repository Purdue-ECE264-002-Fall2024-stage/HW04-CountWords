// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// This function is provided to convert words to a form consisting of
// only lowercase letters, provided for your convenience.  DO NOT modify it.
void tidyString(char * messyString) {
  const char * tidyString = malloc(sizeof(char)*(strlen(messyString) + 1));
  if (!tidyString) return;
  char * addToString = tidyString;
  while (*messyString) {
    if (*messyString > 96 && *messyString < 123) *(addToString++) = *messyString;
    if (*messyString > 64 && *messyString < 91) *(addToString++) = *messyString + 32;
    ++messyString;
  }
  *addToString = 0;
  strcpy(messyString, tidyString);
  free(tidyString);
}

// The functions below contain instructions for you.  You MUST modify them.
// Inputs:
  // char * filename      The name of the input file
  // int max_word_length  The longest any word is allowed to be
int totalWordCount(char * filename, int max_word_length) {
  // Open the file
  FILE * fptr = fopen(filename, "r");
  // If the file cannot be found, return -1
  if (!fptr) return -1;

  // Dynamically allocate a string of length max_word_length
  char * word = malloc(sizeof(char)*max_word_length);
  // Read words to that string, using fscanf, and count the words
  int count = 0;
  while (fscanf(fptr, "%40s", word)) {
    ++count;
  }
  
  // Close the file and free the string
  fclose(fptr);
  free(word);
  return count;
}

// Inputs:
  // char * filename      The name of the input file
  // int max_word_length  The longest any word is allowed to be
  // int total_word_count The total number of words in the file
void eachWordCount(char * filename, int max_word_length, int total_word_count)
{
  // Open the file
  FILE * fptr = fopen(filename, "r");
  // If fopen fails, return
  if (!fptr) return;

  // Dynamically allocate space for your table of words, both words and ints to act as word counts
  const char * words = malloc(sizeof(char)*max_word_length*total_word_count);
  int * word_counts = malloc(sizeof(int)*total_word_count);
  char * next_word = words;
  int * next_word_count = word_counts;

  char * dict_word;

  // Read in words from the file
  char * word = malloc(sizeof(char)*max_word_length);
  while (fscanf(fptr, "%40s", word)) {
    // convert them to lowercase using the `tidyString`
    tidyString(word);
    // if the word does not appear in the table, add it and give it a count of 1
    dict_word = next_word - max_word_length;
    while (dict_word >= words && !strcmp(dict_word, word)) {
      dict_word -= max_word_length;
    }
    if (dict_word < words) {
      strcpy(word, next_word);
      *next_word_count = 1;
      next_word += max_word_length;
      ++next_word_count;
    }
    // if the word does appear in the table, increment its count
    else {
      word_counts[(dict_word - words) / max_word_length] += 1;
    }
  }

  // Close the file
  fclose(fptr);
  
  // Print out words and their counts
  while (next_word > words) {
    next_word -= max_word_length;
    --next_word_count;
    printf("%s %d", next_word, *next_word_count);
  }

  // Free all dynamically allocated memory
  free(words);
  free(word_counts);
}
