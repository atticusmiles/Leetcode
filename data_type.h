#ifndef DATA_TYPE
#define DATA_TYPE

#include <stdlib.h>
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode():ListNode(0){};
	void print()
	{
		std::cout<<val<<"->"<<std::flush;
		if(next) next->print();
		else std::cout<<"NULL"<<std::endl;
	};
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
	TreeNode(): TreeNode(0) {};
	void print()
	{
		std::vector<TreeNode*> thisLevel{this};
		std::vector<TreeNode*> nextLevel;
		while(!thisLevel.empty())
		{
			for(auto ptr: thisLevel)
			{
				if(ptr) 
				{
					std::cout<<ptr->val<<"----";					
					nextLevel.push_back(ptr->left);
					nextLevel.push_back(ptr->right);
				}
				else
				{
					std::cout<<"#----";
				}
			}
			std::cout<<std::endl;
			nextLevel.swap(thisLevel);
			nextLevel.clear();
		}
	}
 };


	// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


// Definition for undirected graph.
struct UndirectedGraphNode 
{
	int label;
	std::vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


#endif
