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
