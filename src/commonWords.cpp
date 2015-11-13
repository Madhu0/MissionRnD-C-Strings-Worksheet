/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int words(char *str, char **word){
	int i = 0, j = 0;
	while (str[j] != '\0'){
		if (str[j] != ' '){
			word[i++] = &str[j];
			break;
		}
		j++;
	}
	if (str[j] == '\0')
		return 0;
	for (; str[j] != '\0'; j++){
		if (str[j] == ' '&&str[j + 1] != ' '){
			word[i++] = &str[j + 1];
			str[j] = '\0';
		}
	}
	return i;

}

void compare(char **words1, int len1, char **result,char *str){
	int i, j = 0, k = 0, flag = 0, pos = 0, l = 0;
	for (i = 0; i < len1; i++){
		while (str[j] != '\0'){
			if (words1[i][k] == '\0'&&flag == 1){
				result[l++] = &str[pos];
				pos = j + 1;
			}
			if (str[j] == ' '){
				pos = j + 1;
				k = 0;
			}
			if (words1[i][k] == str[j]){
				k++;
				flag = 1;
			}
			else{
				k = 0;
				flag = 0;
			}
			j++;
		}
		if (words1[i][k] == '\0'&&flag == 1){
			result[l++] = &str[pos];
		}
		j = 0;
		k = 0;
		pos = 0;
	}
}

char ** commonWords(char *str1, char *str2) {
	int i, no_of_words;
	char **result;
	char **word1;
	result = (char **)malloc(sizeof(char *)* SIZE);
	word1 = (char **)malloc(sizeof(char *)* SIZE);
	for (i = 0; i < SIZE; i++)
		result[i] = NULL;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	no_of_words = words(str1, word1);
	for (i = 0; i < no_of_words; i++)
		printf("%s ", word1[i]);
	if (no_of_words == 0)
		return NULL;
	compare(word1, no_of_words, result, str2);
	for (i = 0; str2[i] != '\0'; i++){
		if (str2[i] == ' ')
			str2[i] = '\0';
	}
	if (result[0] == NULL)
		return NULL;
	return result;
}