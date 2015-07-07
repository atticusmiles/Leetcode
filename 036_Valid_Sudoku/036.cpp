#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<string>& board);
    bool isValidSudoku(vector<vector<char>>& board) 
    {
    	vector<set<char>> rows (9);
    	vector<set<char>> cols (9);
    	vector<set<char>> blocks (9);

    	for(int row =0; row<9; ++row)
    	{
    		for(int col = 0; col<9; ++col)
    		{
    			if ('.'!=board[row][col])
    			{
    				int block_num = (row/3)*3+(col/3);

    				if ((rows[row].insert(board[row][col])).second==false) 
    				{
    					return false; 
    				}
    				if ((cols[col].insert(board[row][col])).second==false) 
    				{
    					return false;
    				}
    				if ((blocks[block_num].insert(board[row][col])).second==false) 
    				{
    					return false; 
    				}
    			}
    		}
    	}
    	return true;
    }
};

bool Solution::isValidSudoku(vector<string>& board) 
    {
    	vector<set<char>> rows (9);
    	vector<set<char>> cols (9);
    	vector<set<char>> blocks (9);

    	for(int row =0; row<9; ++row)
    	{
    		for(int col = 0; col<9; ++col)
    		{
    			if ('.'!=board[row][col])
    			{
    				int block_num = (row/3)*3+(col/3);

    				if ((rows[row].insert(board[row][col])).second==false) 
    				{
    				    cout<<endl<<"row error\t"<<row<<"\t"<<col<<"\t"<<board[row][col]<<endl;
    					return false; 
    				}
    				if ((cols[col].insert(board[row][col])).second==false) 
    				{
    				    cout<<endl<<"col error\t"<<row<<"\t"<<col<<"\t"<<board[row][col]<<endl;
    					return false;
    				}
    				if ((blocks[block_num].insert(board[row][col])).second==false) 
    				{
    					cout<<endl<<"block error\t"<<row<<"\t"<<col<<"\t"<<board[row][col]<<"\t"<<block_num<<endl;
                        cout<<"block"<<block_num<<"\t";
                        for(auto c: blocks[block_num])
                        {
                            cout<<c<<"\t";
                        }
    					return false; 
    				}
                    cout<<board[row][col]<<"\t";
                    
    			}
    			else
    			{
    				cout<<"."<<"\t";
    			}
    		}
    		cout<<endl;
    	}
    	return true;
    }

int main()
{
	vector<string> board (9);
	board[0]=".87654321";
	board[1]="1........";
	board[2]="2........";
	board[3]="3........";
	board[4]="4........";
	board[5]="5........";
	board[6]="6........";
	board[7]="7........";
	board[8]="8........";

	Solution slt;
	cout<<slt.isValidSudoku(board);
	while(1);
}
