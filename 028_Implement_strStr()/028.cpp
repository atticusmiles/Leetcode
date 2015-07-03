#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) 
    {
    	if (haystack.size()==0 && needle.size()==0)
    		return 0;
    	
    	auto iter=haystack.begin();

     	while(iter!=haystack.end())
     	{
     		auto needle_ptr = needle.begin();
 			auto haystack_ptr = iter;

 			while(haystack_ptr!= haystack.end())
 			{
 				if(*haystack_ptr==*needle_ptr)
 				{
 					++haystack_ptr;
 					++needle_ptr;
 				}
 				else
 				{
 					break;
 				}

 				if(needle.end()==needle_ptr)
 				{
 					return iter-haystack.begin();
 				}
 			}

 			if (haystack_ptr == haystack.end()) 
 			{
 				return -1;
 			}
 			else
 			{
 				++iter;
 			} 
 		}
 		return -1;
    }
};


int main()
{
	string src;
	string dst;
	Solution slt;
	while(1)
	{
		cin>>src;
		cin>>dst;
		cout<<slt.strStr(src,dst)<<endl;
	}

	return 1;
}