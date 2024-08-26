# Read Line from File and Count Word

### Due Sept. 17 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that reads in a file,
identifies all the words, counts how many times each word occurs,
and reports the result.

You will learn to
* Read lines and store as strings
* Compare strings
* Dynamically allocate memory (to an extent)

Count Words in a File
===================================

This assignment counts the number of words in a file,
allocates space for a list of these words, then goes
back through the file to identify all the distinct words
and count how many times each distinct word occurs.

For example, given a file containing the phrase:
> Fool me once, shame on you.  Fool me twice, shame on me.

The program would count the words.  There are twelve words.
Then it would make space for a table of twelve words and numbers.
Then it would go through the file and look at each word:
* "Fool" would be added to the table with count 1.
* "Me" would be added to the table with count 1.
* "Once" would be added to the table with count 1.
* "Shame" would be added to the table with count 1.
* "On" would be added to the table with count 1.
* "You" would be added to the table with count 1.
* "Fool", already being in the table, would get count 2.
* "Me", already being in the table, would get count 2.
* "Twice" would be added to the table with count 1.
* "Shame", already being in the table, would get count 2.
* "On", already being in the table, would get count 2.
* "Me", already being in the table with count 2, would get count 3.

The program would then print out:
fool 2
me 3
once 1
shame 2
on 2
you 1
twice 1

You may notice that the phrase input has punctuation and capital letters,
while the table of output does not.  A function is provided to convert
all words (that is, blocks of characters separate by spaces) into their
dictionary form (lowercase letters only).

This output will be sorted (that is to say, the lines will be alphabetized)
before being compared with a correct answer, so it's okay if your program
prints things in a different order.

What To Do
==========

You need to write two functions.  The first is called  `int totalWordCount(char * filename, int max_word_length)`.  It opens a file named filename, counts the words in it using `fscanf`, and returns that count.
Words are defined as blocks of characters separated by whitespace, which is what `fscanf("%40s")` yields.  If `fopen()` fails, return -1, and **DO NOT** fclose.
The second is called `void eachWordCount(char * filename, int max_word_length, int total_word_count)`.  It reads the file again, adding words to a dynamically allocated table and counting the occurrences of each.  It then prints out all the words and their counts.
Further instructions are in the comments in the function in file `filestr.c`.


Check Memory Leak
=================

Your program must not crash and must not leak memory.   The leaked bytes will
accumulate across all test cases in each assignment. If your program
leaks memory, it is very likely that you will receive zero.  Please
use `valgrind` to check memory errors. A program that leaks memory is
like an airplane that leaks fuel. Neither can be accepted.

WHAT TO SUBMIT
==============

Submit the following files to gradescope as a zip file: 'main.c', 'filestr.c', 'filestr.h'.

Efficiency
==========
It may seem like your program takes up a lot of empty space with its word table, and searches
inefficiently through that table to see if a word has already been added.  In ECE 368, you'll
learn about more advanced data structures and algorithms that will help conserve space and time.

Test Inputs
===========

The test inputs are famous speeches
