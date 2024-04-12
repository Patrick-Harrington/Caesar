#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_LIMIT 100
#define ALPHABET_SIZE 26

// Function to convert all characters in plaintext message to lowercase
void makeLowercase(char *plaintextMessage)
{
    for (int i = 0; plaintextMessage[i] != '\0'; i++)
    {
        plaintextMessage[i] = tolower(plaintextMessage[i]);
    }
}

// Function to encrypt message using Caesar Cipher
void encrypt(char * plaintextMessage, char *ciphertextMessage)
{
    for (int i = 0; i < sizeof(plaintextMessage); i++)
    {
        if (isalpha(ciphertextMessage[i]))
        {
            int index = ciphertextMessage[i] - 'a';
            index = (index + 3) % 26;
            ciphertextMessage[i] = 'a' + index;
        }
    }
}

// Function to count the frequency of each letter in message
void countLetterFrequency(char *message, int *letterFrequency)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            int index = message[i] - 'a';   // Convert character to index 0-25
            letterFrequency[index]++;
        }
    }
}

// Function to print frequency results
void printLetterFrequencyResults(int *letterFrequency)
{
    //Count Frequency
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("%c: %d\n", 'a' + i, letterFrequency[i]);
    }
    // Reset Frequency to 0
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        letterFrequency[i] = 0;
    }
}
