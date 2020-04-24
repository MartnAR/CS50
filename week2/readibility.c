//Load libraries
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

// Function to count the number of letters in a string
int count_letters(string input_text)
{
    // Initiate l-counter and number of letters
    int l;
    int letter_count = 0;

    // Loop through every letter in the string
    for (l = 0; input_text[l] != '\0'; l++)
    {
        // If the letter is within [A-Za-z], add to letter_count
        if ((input_text[l] >= 'a' && input_text[l] <= 'z') || (input_text[l] >= 'A' && input_text[l] <= 'Z'))
        {
            letter_count++;
        }
    }

    // Return the number of letters
    return letter_count;
}

// Function to count the number of words in a string
int count_words(string input_text)
{
    // Initiate w-counter and number of words
    int w = 0;
    int word_count = 1; // Set to 1 because of lack of EOF.

    // While loop through the input_text
    while (input_text[w] != '\0')
    {
        // If the character is a space, new line, or tab, count a word.
        if (input_text[w] == ' ' || input_text[w] == '\n' || input_text[w] == '\t')
        {
            word_count++;
        }
        w++;
    }

    // Return the number of words
    return word_count;
}

// Function to count the number of sentences in a string
int count_sentences(string input_text)
{
    // Initiate s-counter and number of sentences
    int s = 0;
    int sentence_count = 0;

    // While loop through the input_text
    while (input_text[s] != '\0')
    {
        // If the character is a period, exclamation point, question mark, or new line, count a sentence.
        if (input_text[s] == '.' || input_text[s] == '!' || input_text[s] == '?' || input_text[s] == '\n')
        {
            sentence_count++;
        }
        s++;
    }

    // Return the number of sentences
    return sentence_count;
}

// Main function
int main(void)
{
    // Prompt the user for a text
    string text = get_string("Text: ");

    // Calculate the number of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate Coleman-Liau index
    double L = letters * 100.0 / words;
    double S = sentences * 100.0 / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Return the Grade-level of the text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
