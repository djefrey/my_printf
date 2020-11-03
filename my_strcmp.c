/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare characters between two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int difference;

    for (int i = 0; s1[i] && s2[i]; i++) {
        difference = s1[i] - s2[i];
        if (difference != 0)
            return (difference);
    }
    return (difference);
}