// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "filestr.h"
#define MAX_WORD_LENGTH 40

int main(int argc, char * * argv)
{
  // argv[1] is the input file name
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  int total = 0;
  total = totalWordCount(argv[1], MAX_WORD_LENGTH);
  if (total < 0)
    {
      return EXIT_FAILURE;
    }
  eachWordCount(argv[1], MAX_WORD_LENGTH, total);
  return EXIT_SUCCESS;
}

