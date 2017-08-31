#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
public:
	ListNode() : removed(false), size(0) {}

public:
	ListNode* up;
	ListNode* down;
	ListNode* left;
	ListNode* right;
	int rowNum;
	int colNum;
	int size;
	bool removed;
};

#endif // LISTNODE_H
