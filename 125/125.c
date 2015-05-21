#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isengchar(char c)
{
	return ((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'));
}

bool issame(char a, char b)
{
	return (a==b || 32==a-b || -32==a-b);
}

bool isPalindrome(char* s) 
{
	if ('\0'==*s)
	{
		return true;
	}

	char * s_end = s+strlen(s);
	char * front = s;
	char * rear = s_end;
	while (1)
	{
		while((!isengchar(*front)) && front<=s_end )
		{
			++front;
		}
		while((!isengchar(*rear)) && rear>=s )
		{
			--rear;	
		}
//		 printf("%c,%c\n",*front,*rear );
		if (front>rear)
		{
			break;
		}
		else if (!issame(*front,*rear))
		{
			return false;
		}
		++front;--rear;
	}
	return true;
}

int main()
{
	char* s;
//	s="A man, a plan, a canal: Panama";
	s="1a2";
//	printf("%i\n", isengchar('A') );
	printf("%i\n",isPalindrome(s));
	
	while(1);
	return 1;
}