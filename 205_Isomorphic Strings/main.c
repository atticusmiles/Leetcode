//
//  main.c
//  Test
//
//  Created by Desmond on 15-5-21.
//  Copyright (c) 2015年 Desmond. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
bool isIsomorphic(char* s, char* t)
{
    int Cypher[256];
    
    for (int i=0; i<256; ++i)
    {
        Cypher[i]=-1;
    }
    
    while ('\0'!=*s)
    {
        if (-1==Cypher[(int)*s])
        {
            Cypher[(int)*s]=(int)*t;
            ++s;
            ++t;
        }
        else
        {
            if (*t!=Cypher[(int)*s])
            {
                return false;
            }
            else
            {
                ++s;
                ++t;
            }
        }
    }
    return true;
}

int main()
{
    char *s;
    char *t;
    s="abc";
    t="abc";
    printf("%i\n", isIsomorphic(s,t));
    while(1);
}