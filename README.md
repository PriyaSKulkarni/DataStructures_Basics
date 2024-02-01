# Data Structures and Algorithms Basics
CSE-5311-006-Design and Analysis of Agorithms

Implemented:

1. insertion sort

2. selection sort

3. bubble sort

4. Argument on selection sort correctness.

3. Benchmarked the runtime of each algorithm. included information about computer (ram, cpu etc.) and run with various input sizes; from small (array of size 5,10,20) all the way up to large arrays (where your computer is struggling).  ploted a graph of time vs input size n. 
--------------------------------------------------------------------------------------------------------------------------------

function x = f(n)
   x = 1;
   for i = 1:n
        for j = 1:n
             x = x + 1;
Find the runtime of the algorithm mathematically (I should see summations).
Time this function for various n e.g. n = 1,2,3.... You should have small values of n all the way up to large values. Plot "time" vs "n" (time on y-axis and n on x-axis). Also, fit a curve to your data, hint it's a polynomial. 
Find polynomials that are upper and lower bounds on your curve from #2. From this specify a big-O, a big-Omega, and what big-theta is.
Find the approximate (eye ball it) location of "n_0" . Do this by zooming in on your plot and indicating on the plot where n_0 is and why you picked this value. Hint: I should see data that does not follow the trend of the polynomial you determined in #2.
If I modified the function to be:
x = f(n)
   x = 1;
   y = 1;
   for i = 1:n
        for j = 1:n
             x = x + 1;
        y = i + j;
4. Will this increate how long it takes the algorithm to run (e.x. you are timing the function like in #2)? 

5. Will it effect your results from #1?

6. Implement merge sort, upload your code to github and show/test it on the array [5,2,4,7,1,3,2,6].

--> HandsOn DOC.docx, HandsOn.ipynb , Merge_Sort.ipynb contains the answer.

