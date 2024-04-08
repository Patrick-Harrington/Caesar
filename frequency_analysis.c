#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_LIMIT 100
#define ALPHABET_SIZE 26

int main()
{
    char message[CHAR_LIMIT]; 
    int letterFrequency[ALPHABET_SIZE] = {0};

    // Get user input for message
    printf("Enter a message (up to 100 characters): ");
    fgets(message, sizeof(message), stdin);

    // Convert all characters to lowercase
    for (int i = 0; message[i] != '\0'; i++)
    {
        message[i] = tolower(message[i]);
    }

    // Print original message
    printf("\nMessage: %s\n", message);

    // Copy message to caesar for encryption
    char caesar[CHAR_LIMIT] = {0};
    strcpy(caesar, message);

    // Encrypt message using caesar cipher
    for (int i = 0; i < sizeof(message); i++)
    {
        if (isalpha(caesar[i]))
        {
            int index = caesar[i] - 'a';    // Convert character to index 0-25
            index = (index + 3) % 26;       // Shift each character ahead 3 characters
            caesar[i] = 'a' + index;        // Convert index back to character
        }
    }

    // Print encrypted message
    printf("Caesar: %s\n", caesar);

    // Count frequency of each letter for message
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            int index = message[i] - 'a';   // Convert character to index 0-25
            letterFrequency[index]++;
        }
    }

    // Display the results
    printf("\nLetter Frequency in Message:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, letterFrequency[i]);
    }

    // Reset letterFrequency to 0
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
    letterFrequency[i] = 0;
    }

    // Count frequency of each letter for caesar
    for (int i = 0; caesar[i] != '\0'; i++) {
        if (isalpha(caesar[i])) {
            int index = caesar[i] - 'a';   // Convert character to index 0-25
            letterFrequency[index]++;
        }
    }

    // Display the results
    printf("\nLetter Frequency in Caesar:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, letterFrequency[i]);
    }

    return 0;
}
