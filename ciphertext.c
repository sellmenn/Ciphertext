#include <stdio.h>
#include <string.h>
#include "helper.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Command line usage: ./ciphertext 26-letter-key\n");
        return 1;
    }
    char key[27];
    if (validate_key(argv[1], key) == 1){
        return 1;
    }
    printf("\nEncryption key: %s\n", key);
    printf("Select option:\n(1) Encrypt\n(2) Decrypt\n\nEnter option '1' or '2: ");
    int option;
    scanf("%i", &option);
    char buffer[2]; // Store \n in buffer
    fgets(buffer, 2, stdin);
    if (option == 1){
        char plaintext[100]; // Create array to store plaintext
        printf("Plaintext: "); // Prompt user
        int length_plaintext = sizeof(plaintext)/sizeof(plaintext[0]);
        fgets(plaintext,length_plaintext, stdin); // Store input in array
        char scrambledtext[length_plaintext]; // Create array to store scrambled text
        scramble(plaintext, length_plaintext, key, scrambledtext); // Scramble plaintext using key
        printf("Scrambled text: %s", scrambledtext);
        return 0;
    }
    else if (option == 2){
        char scrambled[100]; // Create array to store scrambled text
        printf("Scrambled text: "); // Prompt user
        int length_scrambled = sizeof(scrambled)/sizeof(scrambled[0]);
        fgets(scrambled,length_scrambled, stdin); // Store input in array
        char plaintext[length_scrambled]; // Create array to store plaintext
        unscramble(scrambled, length_scrambled, key, plaintext); // Unscramble text using key
        printf("Plain text: %s", plaintext);
    }
}