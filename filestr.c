// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// This function is provided to convert words to a form consisting of
// only lowercase letters, provided for your convenience.  DO NOT modify it.
void tidyString(char * messyString) {
  char * tidyString = malloc(sizeof(char)*(strlen(messyString) + 1));
  if (!tidyString) return;
  char * addToString = tidyString;
  char * takeFromString = messyString;
  while (*takeFromString) {
    if (*takeFromString > 96 && *takeFromString < 123) *(addToString++) = *takeFromString;
    if (*takeFromString > 64 && *takeFromString < 91) *(addToString++) = *takeFromString + 32;
    ++takeFromString;
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
  // If the file cannot be found, return -1

  // Dynamically allocate a string of length max_word_length
  // Read words to that string, using fscanf, and count the words
    // Hint:  fscanf(file_ptr, "%39s", my_string) will retrieve everything up to the next whitespace (up to 39 characters), add a null terminator, and place it in "my_string"
  // Close the file and free the string
  // Return the word count
}

// Inputs:
  // char * filename      The name of the input file
  // int max_word_length  The longest any word is allowed to be
  // int total_word_count The total number of words in the file
void eachWordCount(char * filename, int max_word_length, int total_word_count)
{
  // Open the file
  // If fopen fails, return

  // Dynamically allocate space for your table of words, both words and ints to act as word counts
    // Hint:  you can use pointer arithmetic or double pointers to navigate your table of words
    // Hint:  you may want a variable to track how many rows of your table contain real data

  // Read in words from the file
    // convert them to lowercase using the `tidyString`
    // if the word does not appear in the table, add it and give it a count of 1
    // if the word does appear in the table, increment its count
      // Hint:  you can use "strcmp" to compare if two strings are identical

  // Close the file
  
  // Print out words and their counts

  // Free all dynamically allocated memory
}
