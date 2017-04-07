#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int num)
{
	if (num<2) return false;

	if (2==num) return true;

	if (0==num%2) return false;

	for (int i=3; i*i<=num; i=i+2)
	{
		if (0==num%i)
		{
			return false;
		}
	}

	return true;
}
//My Version of countPrimes
// int countPrimes(int n) 
// {
// 	// short * table = (short*) malloc (n*sizeof(short));

// 	// for (int i=0; i<n; ++i)
// 	// {
// 	// 	if ((i>2 && 0==i%2)||(i>3 && 0==i%3)||(i>5 && 0==i%5))
// 	// 	{
// 	// 		table[i]=0;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		table[i]=-1;
// 	// 	}
// 	// }

// 	int cnt=0;

//     for (int i=2; i<n; ++i)
//     {
//     	if ((i>2 && 0==i%2)||(i>3 && 0==i%3)||(i>5 && 0==i%5))
//     	{
//     		continue;
//     	}
//     	else
//     	{
//     		if(isPrime(i))
//     		{
//     			++cnt;
//     		}
//     	}
//     }
	    
//     return cnt;
// }

//非常牛逼的示例算法!!!
int countPrimes(int n) {
   bool *isPrime = malloc(n*sizeof(bool));
   for (int i = 2; i < n; i++) {
      isPrime[i] = true;
   }
   // Loop's ending condition is i * i < n instead of i < sqrt(n)
   // to avoid repeatedly calling an expensive function sqrt().
   for (int i = 2; i * i < n; i++) {
      if (!isPrime[i]) continue;
      for (int j = i * i; j < n; j += i) {
         isPrime[j] = false;
      }
   }
   int count = 0;
   for (int i = 2; i < n; i++) {
      if (isPrime[i]) count++;
   }
   return count;
}

int main()
{
	int n=0;
	while(1)
	{
		scanf("%i",&n);
		printf("%i\n", countPrimes(n));
	}
	return 1;
}