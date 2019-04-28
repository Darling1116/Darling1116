#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
namespace GXR{
	template <class T>
	struct BSTNode
	{
		BSTNode(const T& kv = T())
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		{}


		BSTNode<T>* _left;
		BSTNode<T>* _right;
		T _kv;
	};

	template <class T>
	class BSTree
	{
		typedef BSTNode<T>* Node;//���
		typedef Node* pNode;//ָ�����ָ��
	public:
		//����
		BSTree()
			:root(nullptr)
		{}

		//����
		~BSTree()
		{
			_Destroy(root);
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newroot = new Node(root->_kv);
			newroot->_left = Copy(root->left);
			newroot->_right = Copy(root->_right);
			return newroot;
		}
		//����
		BSTree(const BSTree<T>& tree)
		{
			root = Copy(tree.root);
		}
		//����
		BSTree<T>& operator = (const BSTree<T>& tree)
		{
			if (this != &tree)
			{
				_Destroy(this->root);
				this->root = Copy(tree->root);
				return *this;
			}
		}

		//BSTree<T>& operator = (const BSTree<T>& tree)
		//{
		//	swap(this->root, tree->root);
		//	return *this;
		//}

		//����
		bool Insert(const T& kv)
		{
			//1.�����Ϊ�գ�ֱ�Ӳ�����ڵ�
			if (root == nullptr)
			{
				root = new Node(kv);
				return true;
			}
			//2.����Ϊ�գ��Ҳ���λ��
			Node* cur = root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (kv < cur->_kv)
					cur = cur->_left;
				else if (kv > cur->_kv)
					cur = cur->_right;
				else
					return false;
			}
			//3.λ���ҵ�����ʱ��curΪ�գ�������Ԫ��
			cur = new Node(kv);
			if (kv < parent->_kv)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;
		}

	private:


		void _Destroy(pNode& root)
		{
			if (root)
			{
				_Destroy(root->_left);
				_Destroy(root->_right);
				root = nullptr;
			}
		}

		pNode root;
	};
}

