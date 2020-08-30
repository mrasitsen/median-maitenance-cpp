# median-maitenance-program-c++
a small program to keep track of median maintenance in a flow of integers

there is a list of integers in "numbers.txt" file. 
these integers from 0 up to 10000 in unsorted way.
program will get the numbers by one by and after each number get inside it will find the median
in each step it will keep track of medians and gonna sum all the medians then will find (mod)10000 (ie. last 4 digits)

lets say the number of integers is "k"
if number of integers is odd then the median is (k+1)/2
if number of integers is even then the median is k/2
