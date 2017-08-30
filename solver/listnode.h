#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
	ListNode();
	void remove();
	void unremove();

public:
	ListNode* up;
	ListNode* down;
	ListNode* left;
	ListNode* right;
	int size;
	int rowNum;
	int colNum;
	bool removed;
};

#endif // LISTNODE_H
