/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str,int afterdecimal){
	int i, j,k=0,flag=0;
	char temp;
	for (i = 0; i < afterdecimal; i++)
		number = number * 10;
	if (number < 0){
		str[k++] = '-';
		number = number*-1;
		flag = 1;
	}
	j = (int)number;
	while (j != 0){
		i = j % 10;
		if (afterdecimal == 0){
			str[k++] = '.';
			afterdecimal--;
		}
		else{
			afterdecimal--;
		}
		str[k++] = i + '0';
		j = j / 10;
	}
	if (flag == 1)
		i = 1;
	else
		i = 0;
	j = k-1;
	for (; i < j; i++){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
	}
	str[k] = '\0';
}
