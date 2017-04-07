#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     string multiply(string num1, string num2) 
//     {
//     	string result;
//     	for(auto c : num2)
//     	{
//     		string mul = multiply_by_char(num1,c);
//     		result=add((result.front()=='0')? "0":result+"0",mul);
//     	}
//     	return result;
//     }

//     string multiply_by_char(string num, char digit)
//     {
//     	int flag = 0;
//     	auto iter1 = num.rbegin();

//     	string result;

//     	while(iter1!=num.rend())
//     	{
//     		int dig1 = (*iter1 - '0');
//     		int res = dig1 * (digit - '0') + flag;
//     		flag = (res/10);
//     		res = res % 10;
//     		result.push_back(res+'0');
//     		++iter1;
//     	}
//     	if (flag) result.push_back('0'+flag);
//     	reverse(result.begin(),result.end());
//     	return result;
//     }

//     string add(string num1, string num2)
//     {
//     	int flag = 0;
//     	auto iter1 = num1.rbegin();
//     	auto iter2 = num2.rbegin();
//     	string result;
//     	while(iter1!=num1.rend() || iter2!=num2.rend())
//     	{
//     		int dig1,dig2;
//     		if(iter1==num1.rend()) 
//     		{
//     			dig1 = 0;
//     		}
//     		else
//     		{
//     			dig1 = *iter1 - '0';
//     			++iter1;
//     		}

//     		if(iter2==num2.rend()) 
//     		{
//     			dig2 = 0;
//     		}
//     		else
//     		{
//     			dig2 = *iter2 - '0';
//     			++iter2;
//     		}
//     		int res = dig1+dig2+flag;
//     		flag = (res>=10);
//     		res = res % 10;
//     		result.push_back(res+'0');
//     	}
//     	if (flag) result.push_back('1');
//     	reverse(result.begin(),result.end());
//     	return result;
//     }
// };
class Solution{
	public:
	string multiply(string num1, string num2) {
	    string sum(num1.size() + num2.size(), '0');

	    for (int i = num1.size() - 1; 0 <= i; --i) {
	        int carry = 0;
	        for (int j = num2.size() - 1; 0 <= j; --j) {
	            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
	            sum[i + j + 1] = tmp % 10 + '0';
	            carry = tmp / 10;
	        }
	        sum[i] += carry;
	    }

	    size_t startpos = sum.find_first_not_of("0");
	    if (string::npos != startpos) {
	        return sum.substr(startpos);
	    }
	    return "0";
	}
};

int main()
{
	Solution slt;
	string s1,s2;
	while(cin>>s1>>s2)
	{
		cout<<slt.multiply(s1,s2)<<endl;
	}
}