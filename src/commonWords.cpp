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

void strcopy(char *arr1, char *arr2, int l){
	int i = 0;
	while (arr2[l] != '\0'&&arr2[l] != ' '){
		arr1[i] = arr2[l];
		i++;
		l++;
	}
	arr1[i] = '\0';
}

int words(char *str, char **word){
	int i = 0, j = 0, k;
	while (str[j] != '\0'){
		if (str[j] != ' '){
			strcopy(word[i], str, j);
			i++;
			break;
		}
		j++;
	}
	if (str[j] == '\0')
		return 0;
	for (k = j; str[k] != '\0'; k++){
		if (str[k] == ' '&&str[k + 1] != ' '&&str[k + 1] != '\0'){
			strcopy(word[i], str, k + 1);
			i++;
		}
	}
	return i;
}


char ** compare(char **words1, int len1, char *str,char **result){
	int i, j = 0, k = 0, flag = 0, l = 0;
	for (i = 0; i < len1; i++){
		while (str[j] != '\0'){
			if (words1[i][k] == '\0'&&flag == 1)
				result[l++] = words1[i];
			if (str[j] == ' ')
				k = 0;
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
			result[l++] = words1[i];
		}
		j = 0;
		k = 0;
	}
	return result;
}

char ** commonWords(char *str1, char *str2) {
	int i, no_of_words;
	char **result;
	result = (char **)malloc(sizeof(char *)* SIZE);
	for (i = 0; i < SIZE; i++)
		*(result + i) = NULL;
	char **word1;
	word1 = (char **)malloc(sizeof(char *)* SIZE);
	for (i = 0; i < SIZE; i++)
		word1[i] = (char *)malloc(sizeof(char)*SIZE);
	if (str1 == NULL || str2 == NULL)
		return NULL;
	no_of_words = words(str1, word1);
	if (no_of_words == 0)
		return NULL;
	compare(word1, no_of_words, str2,result);
	if (result[0] == NULL)
		return NULL;
	return result;
}