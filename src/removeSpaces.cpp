/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#define NULL 0

char removeSpaces(char *str) {
	int i=0, count = 0,flag=0;
	if (str == NULL)
		return '\0';
	while (str[i] != '\0'){
		if (str[i] != ' '&&flag == 1)
			str[i - count] = str[i];
		else if (str[i] == ' '){
			flag = 1;
			count++;
		}
		i++;
	}
	str[i - count] = '\0';
	return '\0';
}