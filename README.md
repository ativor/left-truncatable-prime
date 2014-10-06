A prime number is an integer greater than 1 that has no integer divisors other than itself and 1.
 
A left-truncatable prime is a prime number which contains no 0s and remains prime when any contiguous sequence of left-most digits is removed.
 
For example: 5167 is a left-truncatable prime, since 5167, 167, 67 and 7 are all prime; ∙ 2179 is not a left-truncatable prime, even though 2179, 179 and 79 are prime, since 9 is not prime. There are 2166 left-truncatable primes under 1,000,000,000.
 
Write a program in C for an embedded system that reads in a single integer, n (1 ≤ n ≤ 2166), and outputs the nth left-truncatable prime.
 
For example: The input 10 should give the output 47; the input 100 should give the output 5167; the input 1000 should give the output 8391283.

The applications needs to meet 2 conditions:

1. return the number within 0.5 seconds
2. Use less than 8kB of memory

This is the fastest way of returning the given number. On a virtual machine with one core it returns the 2166th lfet-truncatable prime 999.962.683 in 0.037 seconds.

The application is distributed under the Apache 2.0 license

To compile on linux just run the below command:

> gcc -o main main.c
