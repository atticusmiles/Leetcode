#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int height = board.size();
        int width = board.front().size();

        for(int y=0; y<height; ++y)
        {
        	for(int x=0; x<width; ++x)
        	{
        		if(findWord(board,word,x,y,-1)) return true;
        	}
        }
        return false;
    }
    bool findWord(vector<vector<char>>& board, string &word, int x, int y, int progress)
    {
    	if(progress == word.size() -1) return true;
    	if(board[y][x]!=word[progress+1]) return false;
    	if(x<0 || x>=board.front().size() || y<0 || y>=board.size()) return false;
    	
		char tmp = '0';
		swap(tmp,board[y][x]);
		if(findWord(board,word,x+1,y,progress+1) ||
			findWord(board,word,x,y+1,progress+1) ||
			findWord(board,word,x-1,y,progress+1) ||
			findWord(board,word,x,y-1,progress+1)
			)
		{
			swap(tmp,board[y][x]);
			return true;
		}
			
		swap(tmp,board[y][x]);
		return false;
    }
};

int main()
{
	vector<char> line0{'A','B','C','E'};
	vector<char> line1{'S','F','C','S'};
	vector<char> line2{'A','D','E','E'};
	vector<vector<char>> board{line0,line1,line2};
	Solution slt;
	string s;
	while(cin>>s)
	{
		cout<<slt.exist(board, s)<<endl;
	}

}