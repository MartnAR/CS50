// Load libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// function to check if there are unique characters
int isUnique(char* c)
{
    int count = 1;
    // loops through characters in the key to check whether there are any duplicate characters
    for (int i = 0; i < strlen(c); i++)
    {
        for (int j = i + 1; j < strlen(c); j++)
        {
            if(c[i] == c[j] && strcmp(&c[i], ""))
            {
                count++;
                c[j] = '0';
            }
        }
        // returns 1 if the count of duplicate characters is greater than 1
        if (count > 1 && c[i] != '0')
        {
            return 1;
        }
    }
    return 0;
}

// function to check if there are any invalid characters
int isInvalid(char* c)
{
    int count = 1;

    // loops through the characters in the key and if these are not alphabetic, adds to the count
    for (int i = 0; i < strlen(c); i++)
    {
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        {
            count += 0;
        }
        else
        {
            count ++;
        }
    }

    // if the count is greater than 1, then returns an error
    if (count > 1)
    {
        return 1;
    }

    return 0;
}

// function to encode a text
int cipher(string cipher_key, char* input)
{
    // starts a new key string
    string key = cipher_key;
    int key_length = strlen(cipher_key);

    // lowers the case of all characters in the key for key translation
    for (int j = 0; j < key_length; j++)
    {
        key[j] = tolower(cipher_key[j]);
    }

    // gets the original alphabet as orig_key to make 1-to-1 switch
    string orig_key = "abcdefghijklmnopqrstuvwxyz";
    char* output = input;

    int input_len = strlen(input);

    // loops through each letter in the plaintext, compares it to the original key and replaces with the key
    for (int i = 0; i < input_len; i++)
    {
        // finds location of the character
        const char* ch = strchr(orig_key, tolower(input[i]));
        int char_index = ch - orig_key;

        // changes the character in the text using the key
        if (ch && char_index >= 0)
        {
            output[i] = isupper(input[i]) ? toupper(key[char_index]) : key[char_index];
        }
        // if the character is not in the key, it leaves it alone
        else
        {
            output[i] = input[i];
        }
    }

    // returns the ciphered text
    output[input_len] = '\0';
    printf("ciphertext: %s\n", output);
    return 0;
}

int main(int argc, string argv[])
{
    // If no command-line argument or more than one command-line argument, return 1
    if (argc != 2)
    {
        printf("You must provide one argument.\n");
        return 1;
    }
    // If key doesn't contain 26 characters, contains numbers, or there are repeating letters, return 1
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // checks if there are duplicate characters
    else if (isUnique(argv[1]) == 1)
    {
        printf("Key must not have duplicate keys.\n");
        return 1;
    }
    // checks if there are invalid characters
    else if (isInvalid(argv[1]) == 1)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    // runs convertion if all is ok
    else
    {
        // Encrypt the message.
        char* plain = get_string("plaintext: ");
        cipher(argv[1], plain);
        return 0;
    }
}
