/**
 * Application that returns the left-truncatable number on a given position.
 * It works with positions from 1 to 2166
 * Developed by Voicu Potrovita 2014
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * The first 2166 left-truncatable numbers composed of the same amount of
 * digits are never more than 521
 */
#define MAX_FOUND_SIZE 521

/**
 * Arrays of left-truncatable numbers with the same number of digits
 */
int *found, *found1;
/**
 * Pointers to save the allocated memory so it can be freed correctly
 */
int *saved, *saved1;
/**
 * Size of the found array
 */
int found_size; // the size of the found table

/**
 * Check is a given number is prime
 * @param n
 * @return 1 if prime, 0 if not
 */
char is_prime(int n) {
  int i;

  if (n <= 3 || n == 13 || n == 17 || n == 23 || n == 37 || 
      n == 43 || n == 47 || n == 53 || n == 67 ||
      n == 73 || n == 83 || n == 97){
    return n > 1;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return 0;
  } else {
    for (i = 5; i * i < n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) {
        return 0;
      }
    }
    return 1;
  }
  return 1;
}

/**
 * Checks if a given number contains 0
 * (not used in the application, was used for testing)
 * @param n
 * @return 1 contains a zero digit, 0 doesn't contain a 0 digit
 */
// char has_zeros(int n) {
//   int i;
//   int round, prev;
//   if (n < 10) {
//     return 0;
//   }
//   for (i = 10; i < n + 1; i = i * 10) {
//     round = n / i;
//     prev = i / 10;
//     if ((n - (round * i) - n % prev) / prev == 0)
//       return 1;
//   }
//   return 0;
// }

/**
 * Checks if a given number is left truncatable
 * (not used in the application was used for testing)
 * @param n
 * @return 1 is left-truncatable prime, 0 not left-truncatable prime
 */
// char is_left_truncatable_prime(int n) {
//   int i;
//   
//   if (n == 2 || n == 3 || n == 5 || n == 7) {
//     return 1;
//   }
//   if (n < 10) {
//     return 0;
//   }
//   i = n % 10;
//   if (i != 3 && i != 7) {
//     return 0;
//   }
//   if (has_zeros(n)) {
//     return 0;
//   }
//   for (i = 100; i < n * 10; i = i * 10) {
//     if (!is_prime(n % i)) {
//       return 0;
//     }
//   }
//   return 1;
// }

/**
 * Print the usage help for the application
 * @param name
 */
void print_help(char *name) {
  printf("Returns the <number>th left truncatable prime number\nUsage:\n\t%s <number>\n\t<number> has to be greater than 0 and less than 2167\n", name);
}

/**
 * Swap the pointers of the 2 arrays
 * @param array1
 * @param array2
 */
void change_arrays(int **array1, int **array2) {
  int *pointer;
  pointer = *array2;
  *array2 = *array1;
  *array1 = pointer;
}

/**
 * Allocate the memory for the 2 arrays
 * @return 0 on error, 1 on success
 */
char allocate_all(void) {
  if (found != NULL && found1 != NULL) {
    return 0;
  }
  saved = (int*)malloc(sizeof(int) * 521);
  found = saved;
  if (found == NULL) {
    return 0;
  }
  saved1 = (int*)malloc(sizeof(int) * 521);
  found1 = saved1;
  if (found1 == NULL) {
    free(saved);
    return 0;
  }
  return 1;
}

/**
 * Free up allocated 
 */
void free_all(void) {
  if (saved != NULL) {
    free(saved);
    found = NULL;
    saved = NULL;
  }
  if (saved1 != NULL) {
    free(saved1);
    found1 = NULL;
    saved1 = NULL;
  }
}

/**
 * Initialize the found and found1 arrays with the first 54
 * left-truncatable numbers
 * @return 0 in case of error, 1 on success
 */
char initialize_all(void) {
  if (found == NULL || found1 == NULL) {
    return 0;
  }

  found[0] = 113;
  found[1] = 137;
  found[2] = 167;
  found[3] = 173;
  found[4] = 197;
  found[5] = 223;
  found[6] = 283;
  found[7] = 313;
  found[8] = 317;
  found[9] = 337;
  found[10] = 347;
  found[11] = 353;
  found[12] = 367;
  found[13] = 373;
  found[14] = 383;
  found[15] = 397;
  found[16] = 443;
  found[17] = 467;
  found[18] = 523;
  found[19] = 547;
  found[20] = 613;
  found[21] = 617;
  found[22] = 643;
  found[23] = 647;
  found[24] = 653;
  found[25] = 673;
  found[26] = 683;
  found[27] = 743;
  found[28] = 773;
  found[29] = 797;
  found[30] = 823;
  found[31] = 853;
  found[32] = 883;
  found[33] = 937;
  found[34] = 947;
  found[35] = 953;
  found[36] = 967;
  found[37] = 983;
  found[38] = 997;

  found1[0] = 2;
  found1[1] = 3;
  found1[2] = 5;
  found1[3] = 7;
  found1[4] = 13;
  found1[5] = 17;
  found1[6] = 23;
  found1[7] = 37;
  found1[8] = 43;
  found1[9] = 47;
  found1[10] = 53;
  found1[11] = 67;
  found1[12] = 73;
  found1[13] = 83;
  found1[14] = 97;

  return 1;
}

/**
 * Main application function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv) {
  int count; // used to count the found numbers
  int number, to_add, multiplier; // the number to be checked, digit to add, multiplier used to add digit
  int index, index1; // found arrays index
  int result = 2; // the result

  // check that the application is launched with the correct number of parameters
  // and show usage if not
  if (argc != 2) {
    print_help(argv[0]);
    return 0;
  }
  count = atol(argv[1]); // initialize the count variable

  // check that the count variable is within allowed parameters
  // if not show usage
  if (count < 1 || count > 2166) {
    print_help(argv[0]);
    return 0;
  }

  // allocated the required memory, quit on error
  if (!allocate_all()) {
    printf("Error allocating required memory!\n");
    return -1;
  }

  // initialize the found arrays
  initialize_all();
  
  // if the required number is below 16 the result is in the found1 array
  if (count < 16) {
    result = found1[count - 1];
  // if the result is between 16 and 55 the result is in the found array
  } else if (count < 55) {
    result = found[count - 16];
  } else {
    // initialize iteration variables
    index = 0;
    index1 = 0;
    to_add = 1;
    found_size = 39;
    multiplier = 1000;
    count = count - 54;

    // run the loop while count is higher or equal to 1
    while (count >= 1) {
      // generate the number to be checked by adding a digit to it's left
      number = to_add * multiplier + found[index];
      // check if the generated number is prime
      if (is_prime(number)) {
        // if it is prime, save it for the next iteration in found1 array
        found1[index1] = number;
        index1 = (index1 + 1) % 522;
        // decrease count as a left-truncatable was found
        count--;
      }
      // move on to the next number in the found array
      index++;
      // check if found array limit was reached
      if (index == found_size) {
        // check if all possible digits were used to generate possible numbers
        if (to_add == 9) {
          // swap the arrays to start over with adding a digit to the found numbers
          change_arrays(&found, &found1);
          // set correct found array size
          found_size = index1;
          // reset iteration variables and increase multiplier as we added
          // a digit to the numbers in the array
          index = 0;
          index1 = 0;
          to_add = 1;
          multiplier = multiplier * 10;
        } else {
          // increase the digit to be added to the left of the numbers
          // and start from the first number in the found array
          to_add++;
          index = 0;
        }
      }
    }
    // we found the number we are looking for
    result = number;
  }
  
  // print the result
  printf("result is: %ld\n", result);

  // free up the memory
  free_all();

  // exit
  return 0;
}
