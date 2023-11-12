#include <stdio.h>
#include <math.h>

struct WordIndices
{
    int max_index;
    int min_index;
};

int string_length(char str[20]);
int longest_word(char words[10][20]);
int shortest_word(char words[10][20]);
int vowel_counter(char word[20]);
struct WordIndices maxmin_word(char words[10][20]);

int main(void)
{

    char words[10][20];

    int smallest, largest;

    for (int i = 0; i < 10; i++)
    {
        printf("Enter word %d: ", i + 1);
        scanf("%s", &words[i]);
    }

    struct WordIndices result = maxmin_word(words);

    printf("Smallest word: %s | Number of vowels: %d\n", words[result.min_index], vowel_counter(words[result.min_index]));
    printf("Largest word: %s | Number of vowels: %d\n", words[result.max_index], vowel_counter(words[result.max_index]));
}

int string_length(char str[20])
{
    // Initialize length of the string
    int length = 0;

    // Keep adding 1 to the length until it comes across a null character at the end of the string
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

struct WordIndices maxmin_word(char words[10][20])
{
    // initialize the index the longest word is in
    int max_index = 0, max_length = 0;
    int min_index = 0, min_length = 0;

    struct WordIndices result;

    for (int i = 0; i < 10; i++)
    {
        const int length = string_length(words[i]);

        // if it comes across a word with a bigger length then it upates the max_length and max_index
        if (length > max_length)
        {
            max_length = length;
            max_index = i;
        }

        // if it comes across a word with a shorter length then it upates the min_length and min_index
        if (length < length)
        {
            min_length = length;
            min_index = i;
        }
    }

    result.max_index = max_index;
    result.min_index = min_index;

    return result;
}

int vowel_counter(char word[20])
{
    int num_of_vowels = 0;

    for (int i = 0; i < string_length(word); i++)
    {
        char current_char = tolower(word[i]);

        switch (current_char)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            num_of_vowels++;
            break;
        }
    }

    return num_of_vowels;
}
