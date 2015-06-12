// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

#include <stdlib.h>
#include <stdio.h>

void getNextLine(int* prevLine, int * curLine ,int size)
{
	//if previous line is full then copy it to current line	
	if (0!=*(prevLine+size-1))
	{
		for (int k=0; k<size; ++k)
		{
			*(curLine+k)=*(prevLine+k);
		}
	}
	else//scan the previous line and generate the current line
	{	
		int i=0;
		while(0!=*(prevLine+i))
		{
			*(curLine+i)=(0==i)? 1 : ( *(prevLine+i) + *(prevLine+i-1));
			++i;
		}
		*(curLine+i)=1;
	}
	return;
}

int* getRow(int rowIndex, int* returnSize) 
{
    int size = rowIndex+1;    
    *returnSize = size;

    int* prevLine = malloc(size*sizeof(int));
    int* curLine = malloc(size*sizeof(int));
    int* tempLine;
//	初始化第一行
    for (int i=0; i<size; ++i)
    {
    	*(prevLine+i)=0;
    }
    *prevLine=1;

    while (0==*(prevLine+size-1))
    {
    	getNextLine(prevLine,curLine,size);
    	tempLine=curLine;
    	curLine=prevLine;
    	prevLine=tempLine;
    }
    // free(curLine);
    return prevLine;
}

int main()
{
	int* size=malloc(sizeof(int));
	int num;
	while(1)
	{
		scanf("%i",&num);
		int * arr = getRow(num,size);
		for (int i=0; i<=num; ++i)
		{
			printf("%i\t", *(arr+i) );
		}
		printf("\n");
	}
	
}