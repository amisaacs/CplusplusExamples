#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class NodeType
{
	//Start here!!!  add setData, setRlink, setLlink
private:
	T data;
	NodeType<T> * llink;
	NodeType<T> * rlink;
public:
	NodeType() { llink = nullptr; rlink = nullptr; }
	NodeType(T t)
	{
		data = t;
		llink = nullptr; 
		rlink = nullptr;
	}
	void setData(T info) { data = info; }
	void setLlink(NodeType<T> *n) { llink = n; }
	void setRlink(NodeType<T> *n) { rlink = n; }
	T getData() { return data; }
	NodeType<T>* getLlink () { return llink; }
	NodeType<T>* getRlink() { return rlink; }
	bool operator > (NodeType<T> *rhs) { return this->data > rhs->data; }
};

template<typename T>
class BinaryTreeType
{
private:	//What is the benefit of this being private vs. protected?
	NodeType<T> *root;
public:
	/*  The auxillary functions enable access to the private data member root.*/
	BinaryTreeType() { root = nullptr; }
	void insert(const T& item);
	void preOrder(NodeType<T> *p) const;  //auxillary function for preOrderPrint()
	void postOrder(NodeType<T> *p) const; //auxillary function for postOrderPrint()
	void inOrder(NodeType<T> *p) const;	  //auxillary function for inOrderPrint()
 	void preOrderPrint() const;
	void postOrderPrint() const;
	void inOrderPrint() const;
	int treeHeight(NodeType<T> *p);	//auxillary function for getHeight();
	int getTreeHeight();
	int treeLeaves(NodeType<T> *p, int& count);		//auxillary function for countTreeLeaves.
	int countTreeLeaves();
};

template<typename T>
void BinaryTreeType<T>::insert(const T& item)
{
	NodeType<T> *nuNode = new NodeType<T>;
	NodeType<T> *curr, *trail;

	nuNode->setData(item);
	nuNode->setLlink(nullptr);
	nuNode->setRlink(nullptr);

	//case 1 - insert into empty tree
	if (root == nullptr)
	{
		root = nuNode;
		cout << item << " ";
	}
	else //case 2 - traverse tree for place to insert
	{
		curr = root;
		trail = nullptr;
		while (curr != nullptr)
		{
			trail = curr;
			if (item == curr->getData())
			{
				//cout << "No duplicates allowed - " << curr->getData() << "has already been inserted." << endl;
				return;
			}
			if (item > curr->getData())
				curr = curr->getRlink();
			else
				curr = curr->getLlink();
		}

		//after traversing add the node to the left or the right.
		if (nuNode->getData() > trail->getData())
		{
			trail->setRlink(nuNode);
			cout << item << " ";
		}
		else
		{
			trail->setLlink(nuNode);
			cout << item << " ";
		}
	}//end else case 2
}

template<typename T>
void BinaryTreeType<T>::preOrder(NodeType<T> *p) const
{
	if (p != nullptr)
	{
		cout << p->getData() << " ";
		preOrder(p->getLlink());
		preOrder(p->getRlink());
	}
}

template<typename T>
void BinaryTreeType<T>::postOrder(NodeType<T> *p) const
{
	if (p != nullptr)
	{
		postOrder(p->getLlink());
		postOrder(p->getRlink());
		cout << p->getData() << " ";
	}
}

template<typename T>
void BinaryTreeType<T>::inOrder(NodeType<T> *p) const
{
	if (p != nullptr)
	{
		inOrder(p->getLlink());
		cout << p->getData() << " ";
		inOrder(p->getRlink());
	}
}

template<typename T>
void BinaryTreeType<T>::preOrderPrint() const
{
	preOrder(root);
}
template<typename T>
void BinaryTreeType<T>::postOrderPrint() const
{
	postOrder(root);
}
template<typename T>
void BinaryTreeType<T>::inOrderPrint() const
{
	inOrder(root);
}
template<typename T>
int BinaryTreeType<T>::treeHeight(NodeType<T> *p)
{
	if (root == NULL) return 0;	//tree is empty, height is 0

	if (p->getLlink() != nullptr && p->getRlink() != nullptr)
		return (1 + max(treeHeight(p->getLlink()), treeHeight(p->getRlink())));

	if (p->getLlink() == nullptr && p->getRlink() != nullptr)
		return (1 + treeHeight(p->getRlink()));

	if (p->getLlink() != nullptr && p->getRlink() == nullptr)
		return(1 + treeHeight(p->getLlink()));

	return 1;

}

template<typename T>
int BinaryTreeType<T>::getTreeHeight()
{
	return treeHeight(root);
}

template<typename T>
int BinaryTreeType<T>::treeLeaves(NodeType<T> *p, int &c)
{
	/*This counts the leaves postOrder because preOrder and inOrder 
	would return before all the leaves were counted.*/
	
	if(p != nullptr)
	{
		c++;
		treeLeaves(p->getLlink(),c);
		treeLeaves(p->getRlink(),c);
			
	}

	return c;
}
template<typename T>
int BinaryTreeType<T>::countTreeLeaves()
{
	int count = 0;
	return treeLeaves(root, count);
}
