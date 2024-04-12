#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function to convert all characters in plaintext message to lowercase
void makeLowercase(char *plaintextMessage);

// Function to encrypt message using Caesar Cipher
void encrypt(char * plaintextMessage, char *ciphertextMessage);

// Function to count the frequency of each letter in message
void countLetterFrequency(char *message, int *letterFrequency);

// Function to print frequency results
void printLetterFrequencyResults(int *letterFrequency);

#endif // FUNCTIONS_H
