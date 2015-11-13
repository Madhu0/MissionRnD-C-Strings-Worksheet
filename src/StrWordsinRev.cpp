/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void stringrev(char *str, int strt, int end){
	char temp;
	while (strt < end){
		temp = str[strt];
		str[strt] = str[end];
		str[end] = temp;
		strt++;
		end--;
	}
}

void str_words_in_rev(char *input, int len){
	int i,j=-1,flag=0;
	stringrev(input, 0, len - 1);
	for (i = 0; i <= len; i++){
		if (input[i] != ' '&&j == -1)
			j = i;
		if (input[i] == ' '||input[i]=='\0'){
			if (j != -1){
				stringrev(input, j, i - 1);
				flag = 1;
				j = -1;
			}
		}
	}
	if (flag == 0)
		stringrev(input, 0, len - 1);
}
