//func_ptr.c -- use pointer on function

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char * s_gets(char * st, int n); 						//process input string
char showmenu(void);
void eatline(void); 									//read only first char
void show(void(*fp)(char *), char * str);
void ToUpper(char *); 									//tranform string to uppercase
void ToLower(char *); 									//tranform string to lowercase
void Tranpose(char *); 									//change place uppercase and lowercase 
void Dummy(char *); 									// do nothing

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choise;

	void(*pfun)(char *); 								//pointer to function that have type 'char *' and do nothing

	puts("Enter string(empty string for exit):");
	while(s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while((choise = showmenu()) != 'n')
		{
			switch(choise)
			{
				case 'u': pfun = ToUpper; break;
				case 'l': pfun = ToLower; break;
				case 't': pfun = Tranpose; break;
				case 'o': pfun = Dummy; break;
			}
			strcpy(copy, line); 						//make copy for show()
			show(pfun, copy); 							//use selected function
		}
		puts("Enter string(empty string for exit):");
	}
	puts("Execution sucessfully");
	return 0;
}

char showmenu(void)
{
	char ans; 											//answer
	puts("Enter	selected var from menu:");
	puts("u) uppercase              l) lowercase");
	puts("t) change case            o) initial case");
	puts("n) next string");
	ans = getchar(); 									//get answer
	ans = tolower(ans); 								//any ans to lowercase
	eatline(); 											// discard remaining part of string

	while(strchr("ulton", ans) == NULL)
	{
		puts("Enter 'u', 'l', 't', 'o', or 'n':");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void ToUpper(char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Tranpose(char * str)
{
	while(*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
														//do nothing
}

void show(void(*fp)(char *), char * str)
{
	(*fp)(str);											//apply selected function toward 'str'
	puts(str);											//show the result
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); 						//search new string
		if (find)
			*find = '\0';								//put here null symbol
		else
			while (getchar() != '\n')
				continue;								//dicard remaining string
	}
	return ret_val;
}