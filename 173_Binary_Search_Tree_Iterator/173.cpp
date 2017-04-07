#include "../data_type.h"
#include <vector>
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
    {
        path.push_back(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        TreeNode* this_node = path.back();
        if(NULL==this_node) return false;
        if(this_node->right) return true;
        for(auto riter=path.rbegin(); riter < path.rend(); ++riter)
        {
        	if(*riter>this_node) return true;
        }
        return false;
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* this_node = path.back();
        if(this_node->right) return this_node->right->val;
        for(auto riter=path.rbegin(); riter < path.rend(); ++riter)
        {
        	if(*riter>this_node) return true;
        }
        return false;
    }
private:
	vector<TreeNode*> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */