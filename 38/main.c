#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char GetLastNum (int *num)
// {
// 	char c='0';
// 	int i=0;
// 	if (*num <0) 
// 	{
// 		return '\0';
// 	}
// 	else
// 	{
// 		i= *num %10;
// 		*num = (int) *num/10;
// 		return (char) (c+i) ;
// 	}
// }

// char * Num2Char (int i)
// {
// 	char *tmp=(char*)malloc(20*sizeof(char));
// 	int num =i;
// 	int cnt=0;

// 	if (num<=0)
// 	{
// 		if (0==num)
// 		{
// 			tmp="0";
// 		}
// 		else
// 		{
// 			tmp="";
// 		}
// 	}
// 	else
// 	{
// 		while(num>0)
// 		{
// 			*(tmp+cnt)=GetLastNum(&num);
// 			++cnt;
// 		}
// 		*(tmp+cnt)='\0';
// 	}

// 	char *out=(char*)malloc(20*sizeof(char));

// 	for (int k=0; k<cnt; k++)
// 	{
// 		*(out+k)=*(tmp+cnt-k-1);
// 	}
// 	*(out+cnt)='\0';
// 	free(tmp);
// 	return out;
// }

char* getNext(char *num) 
{
	char *tmp=(char*)malloc(10000*sizeof(char));
	char *out=(char*)malloc(10000*sizeof(char));
	char c = *num;
	int num_cnt=0;
	while ('\0'!=*num)
	{
		if (c==*num)
		{
			++num_cnt;
			++num;
		}
		else
		{
			sprintf(tmp,"%i%c",num_cnt,c);
			strcat(out,tmp);
			num_cnt=1;
			c=*num;
			++num;
		}
	}
	sprintf(tmp,"%i%c",num_cnt,c);
	strcat(out,tmp);
	free(tmp);
//	free(num);
	return out;
	
}

char* countAndSay(int num) 
{
	if (1==num)
	{
		return "1";
	}
	else
	{
		return getNext(countAndSay(num-1));
	}	
}


int main()
{
//	char *s;
	char *out;
	for (int i=1;i<25;++i)
	{
		out=countAndSay(i);
		printf("%i\t%s\n", i, out );
	}
	while(1);
}
