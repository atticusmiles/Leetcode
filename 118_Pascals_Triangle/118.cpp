#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
		vector<int> core_line{1};
		vector<int> tmp_line;
		vector<vector<int>> dst;

		if (1==numRows) 
		{
			dst.push_back(core_line);
			return dst;
		}
		dst.push_back(core_line);
		core_line.push_back(1);

		for (int i=1; i<numRows; ++i)
		{
			dst.push_back(core_line);
			tmp_line.push_back(1);
			for (auto iter = core_line.begin(); iter<(core_line.end()-1); ++iter)
			{
				tmp_line.push_back(*iter+*(iter+1));
			}
			tmp_line.push_back(1);
			core_line.swap(tmp_line);
			tmp_line.clear();
		}    

		return dst;
    }
};

int main()
{
	Solution slt;
	vector<vector<int>> result;
	result = slt.generate(5);
	for (auto &line: result)
	{
		for (auto &num: line)
		{
			cout<<num<<"\t"<<flush;
		}
		cout<<endl;
	}
	while(1);
}