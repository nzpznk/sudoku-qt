#include "listnode.h"

ListNode::ListNode()
{
	removed = false;
}

void ListNode::remove()
{
	this->left->right = this->right;
	this->right->left = this->left;
	this->up->down = this->down;
	this->down->up = this->up;
	this->removed = true;
}

void ListNode::unremove()
{
	this->left->right = this;
	this->right->left = this;
	this->up->down = this;
	this->down->up = this;
	this->removed = false;
}
