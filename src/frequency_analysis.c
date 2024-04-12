#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_LIMIT 100
#define ALPHABET_SIZE 26

int main()
{
    char plaintextMessage[CHAR_LIMIT]; 
    int letterFrequency[ALPHABET_SIZE] = {0};

    // Get user input for message
    printf("Enter a message (up to 100 characters): ");
    fgets(plaintextMessage, sizeof(plaintextMessage), stdin);

    // Convert all characters to lowercase
    makeLowercase(plaintextMessage);

    // Print original message
    printf("\nBefore encryption: %s\n", plaintextMessage);

    // Copy plaintext to ciphertext variable for encryption
    char ciphertextMessage[CHAR_LIMIT] = {0};
    strcpy(ciphertextMessage, plaintextMessage);

    // Encrypt message using caesar cipher
    encrypt(plaintextMessage, ciphertextMessage);

    // Print encrypted message
    printf("After encryption: %s\n", ciphertextMessage);

    // Count frequency of each letter for plaintext message
    countLetterFrequency(plaintextMessage, letterFrequency);

    // Display the results for plaintext message
    printLetterFrequencyResults(letterFrequency);

    // Count frequency of each letter for ciphertext message
    countLetterFrequency(ciphertextMessage, letterFrequency);

    // Display the results for ciphertext message
    printLetterFrequencyResults(letterFrequency);

    return 0;
}
