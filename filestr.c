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
# ifdef TOTALCOUNTWORD
// Inputs:
  // char * filename      The name of the input file
  // int max_word_length  The longest any word is allowed to be
int totalWordCount(char * filename, int max_word_length) {
  // Open the file
  // If the file cannot be found, return -1

  // Dynamically allocate a string of length max_word_length
  // Read words to that string, using fscanf, and count the words
  // Close the file and free the string
  // Return the word count
}
#endif

#ifdef EACHCOUNTWORD
// Inputs:
  // char * filename      The name of the input file
  // int max_word_length  The longest any word is allowed to be
  // int total_word_count The total number of words in the file
void eachWordCount(char * filename, int max_word_length, int total_word_count)
{
  // Open the file
  // If fopen fails, return

  // Dynamically allocate space for your table of words, both words and ints to act as word counts
    // Hint:  you may want to use pointer arithmetic to navigate your table of words
    // Hint:  you may need a variable to track how many rows of your "table" are real data

  // Read in words from the file
    // convert them to lowercase using the `tidyString`
    // if the word does not appear in the table, add it and give it a count of 1
    // if the word does appear in the table, increment its count
      // Hint:  you can use "strcmp" to compare if two strings are identical

  // Close the file
  
  // Print out words and their counts

  // Free all dynamically allocated memory
}
#endif
