#include "substring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * check_words - Vérifie un ensemble de mots une permutation dans `words`
 * @s: la chaîne à vérifier
 * @words: tableau contenant les mots à comparer
 * @nb_words: le nombre de mots dans le tableau `words`
 * @word_len: la longueur de chaque mot
 *
 * Return: 1 si les mots correspondent, 0 sinon
 */

static int check_words(const char *s, const char **words,
				 int nb_words, int word_len)
{
	int *word_used = calloc(nb_words, sizeof(int));

	if (!word_used)
		return (0);

	int match = 1;

	for (int j = 0; j < nb_words; j++)
	{
		int found = 0;

		for (int k = 0; k < nb_words; k++)
		{
			if (!word_used[k] && strncmp(s + j * word_len, words[k], word_len) == 0)
			{
				word_used[k] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			match = 0;
			break;
		}
	}
	free(word_used);
	return (match);
}
/**
 * find_substring - Trouve toutes les sous-chaînes possibles la liste de mots
 * @s: la chaîne à analyser
 * @words: le tableau de mots dont les sous-chaînes une concaténation
 * @nb_words: le nombre d'éléments dans le tableau `words`
 * @n: pointeur pour stocker le nombre d'éléments dans le tableau retourné
 *
 * Return: tableau contenant chaque index dans `s`sous-chaîne est trouvée
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]);
	int substr_len = word_len * nb_words;
	int s_len = strlen(s);
	int *indices = malloc(s_len * sizeof(int));
	int count = 0;

	if (!indices)
		return (NULL);

	for (int i = 0; i <= s_len - substr_len; i++)
	{
		if (check_words(s + i, words, nb_words, word_len))
			indices[count++] = i;
	}

	*n = count;
	return (indices);
}
