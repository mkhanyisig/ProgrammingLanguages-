Mkhanyisi Gamedze 
CS333 Project 2
9 November 2017

Compiler used: terminal 
macOS Sierra version 10.12.6

*****Part I: File I/O and String in C

To accomplish the task of building a word counter which then returns the top 20 words in a text file. Below is an 
outline of my solution to this problem. 

>Data structures used: Linked List from project 5 & an array that holds a pair struct

I started off my word count file by writing out the code to open the text file and then ask user to input the filename from the command line.
I used fscanf to read in the words from the text file & then process each word before adding it to my linkedlist data structure. 
Given each word, I eliminated punctuation, casted the word into lowercase & then used the ll_add_word function to add it to the linked list. 
The ll_add_word function first checked whether the word is in the linked list and increased its frequency if it existed, otherwise it was pushed into the list. 
My "ll_mapNode(l, mapNode);" function call served as a quality check statement for my read in method. 

To accomplish the second part of my program, which was printing out the top 20 most frequent words from a text file, I created a new "pair" struct to help me. 
Using an array of "pair" struct objects, I created a new function ll_mapArray, which updated each pair object in the array. Each Node corresponded 
to a word-frequency pair on my array list. With a comparator function to complement my objective of sorting the array, using qsort I was able to complete this task efficiently. 

> My output was similar to the expected values, but for "the", I got 16 instead of 17. I am still not sure why, but everything worked fine.   

*****Part II





*****Extenstions



