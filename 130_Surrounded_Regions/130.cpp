#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
    	if(board.size()==0 || board.front().size()==0) return;
        int height = board.size();
        int width = board.front().size();


    	for(int y=0; y<height; ++y)
    	{
    		if(board[y][0]=='O') markZeros(y,0,board);
    	}

    	for(int y=0; y<height; ++y)
    	{
    		if(board[y][width-1]=='O') markZeros(y,width-1,board);
    	}

		for(int x=0; x<width; ++x)
    	{
    		if(board[0][x]=='O') markZeros(0,x,board);
    	}

    	for(int x=0; x<width; ++x)
    	{
    		if(board[height-1][x]=='O') markZeros(height-1,x,board);
    	}

        for(auto &v : board)
        {
        	for( auto &c :v)
        	{
        		if(c=='0')
        		{
        			c='X';
        			continue;
        		}
        		if(c=='A')
        		{
        			c='O';
        			continue;
        		}
        	}
        }
    }

	void markZeros(int y, int x, vector<vector<char>>& board)
    {
    	board[y][x] = 'A';
    	if(y-1>=0 && board[y-1][x]=='O') 
		{
			markZeros(y-1,x,board);
		}
		if(y+1<board.size() && board[y+1][x]=='O') 
		{
			markZeros(y+1,x,board);
		}
		if(x+1<board.front().size() && board[y][x+1]=='O')
		{
			markZeros(y,x+1,board);
		}
		if(x-1>=0 && board[y][x-1]=='O')
		{
			markZeros(y,x-1,board);
		}
    }
};