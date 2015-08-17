#include "../data_type.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
    	unordered_map<RandomListNode* , RandomListNode* > node_pairs;

    	if(NULL==head) return NULL;
    	RandomListNode* ptrIter = head;
    	while(ptrIter)
    	{
    		node_pairs.insert({ptrIter,new RandomListNode(ptrIter->label)});
    		ptrIter = ptrIter->next;
    	}
    	ptrIter = head;
    	while(ptrIter)
    	{
    		node_pairs[ptrIter]->next = ptrIter->next? node_pairs[ptrIter->next]:NULL;
    		node_pairs[ptrIter]->random = ptrIter->random? node_pairs[ptrIter->random]: NULL;
    		ptrIter = ptrIter->next;
    	}
    	return node_pairs[head];
    }
};