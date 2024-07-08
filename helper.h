/* Function which if passed:
(1) An array of integers
(2) Number of elements in array
(3) An integer
Returns 1 if integer is in the array,
0 otherwise.
*/ 
int in_array(int nums[], int nums_length, int num){
    int length; // store number of elements in array
    for (int i = 0; i < nums_length; i++){
        if (nums[i] == num){
            return 1;
        }
    }
    return 0;
}

/* Function which if passed:
(1) A single char
Returns 0 if char is alphabetical,
1 otherwise.
*/
int is_alpha(char character){
    if (character >= 65 && character <= 90){
        return 0;
    }
    else if (character >= 97 && character <= 122){
        return 0;
    }
    return 1;
}

/* Function which if passed:
(1) A single alphabet
Returns uppercase of alphabet.
*/
char to_upper(char alphabet){
    if (alphabet >= 97 && alphabet <= 122){
        return alphabet - 32;
    }
    return alphabet;
}

/* Function which if passed:
(1) An array of type char : plaintext
(2) Length of array
(3) An array of type char, containing a 26 letter key in uppercase
(4) An array of type char, with same length as in (2), to store scrambled text
Will do the following:
(1) For every ith-indexed char in the array(1), let char be the nth character in the alphabet.
(2) Assign the nth-indexed char in array(3) to array(4)[i]
*/
void scramble(char plaintext[], int length, char key[], char scrambled_text[]){
    for (int i = 0; i < length; i++){
        // If uppercase, simply assign key
        if (plaintext[i] >= 65 && plaintext[i] <= 90){
            scrambled_text[i] = key[plaintext[i] - 65];
        }
        // If lowercase assign key, and convert to lower.
        else if (plaintext[i] >= 97 && plaintext[i] <= 122){
            scrambled_text[i] = key[plaintext[i] - 97] + 32;
        }
        // If not alphabetical, no change
        else {
            scrambled_text[i] = plaintext[i];
        }
    }
}

/* Function which if passed:
(1) An array of type char : scrambled text
(2) Length of array
(3) An array of type char, containing a 26 letter key in uppercase
(4) An array if type char, with same length as in (2), to store plaintext
Will do the following:
(1) For every ith-indexed char in the array(1), obtain the index n of corresponding char in key.
(2) Assign the nth alphabet to the ith-indexed char in array(4)
*/
void unscramble(char scrambled[], int length, char key[], char plaintext[]){
    for (int i = 0; i < length; i++){
        // For each character in scrambled text, obtain index in key
        for (int index = 0; index < 26; index++){
            // If uppercase
            if (scrambled[i] == key[index]){
                plaintext[i] = index + 65;
                break;
            }
            // If lowercase, convert scrambled to upper for comparison, then convert to lower.
            else if (scrambled[i] - 32 == key[index]){
                plaintext[i] = index + 97;
                break;
            }
            // If not alphabetical, no change
            else if (index == 25) {
                plaintext[i] = scrambled[i];
            }
        }
    }
}

/* Function which if passed:
(1) An array of type char : key input by user
(2) An array to store validated key
Returns 0 if key is valid, 1 otherwise.
Converts validated key to uppercase.
*/
int validate_key(char user_input[], char key[]){
    int alphabet_count = 26; // Store number of unique alphabets
    int used_letters[alphabet_count]; // to store chars used
    for (int i = 0; i < alphabet_count; i++){
        // Check if char is alphabetical and char is not duplicated
        if (is_alpha(user_input[i]) == 0 && in_array(used_letters, alphabet_count, user_input[i]) == 0){
            key[i] = to_upper(user_input[i]); // Store uppercase for consistency
            used_letters[i] = user_input[i];
        }
        else{
            printf("%i - indexed char is invalid.\n", i);
            printf("Key must consist of 26 unique alphabets.\n");
            return 1;
        }
    }
    return 0;
}
