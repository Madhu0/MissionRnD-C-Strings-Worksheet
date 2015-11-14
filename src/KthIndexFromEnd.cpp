/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#define NULL 0
char KthIndexFromEnd(char *str, int K) {
	int i;
	if (str == NULL||str[0]=='\0')
		return '\0';
	i = str[0];
	for (i = 0; str[i] != '\0'; i++)
		;
	i = i - K-1;
	if (i < 0)
		return '\0';
	return str[i];
}