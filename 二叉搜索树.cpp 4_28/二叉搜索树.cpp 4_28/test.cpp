#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
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
		typedef BSTNode<T> Node;//���
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
				if ( kv < cur->_kv)
					cur = cur->_left;
				else if (kv > cur->_kv)
					cur = cur->_right;
				else
					return false;
				//���򣬴��ڸý�㣬����false
			}
			//3.λ���ҵ�����ʱ��curΪ�գ�������Ԫ��
			cur = new Node(kv);
			if (kv < parent->_kv)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}

		void Print()
		{
			_inorder(root);
		}

		//ɾ��
		bool Erase(const T& kv)
		{
			//1.��Ϊ�գ�ɾ��ʧ��
			if (root == nullptr)
				return false;
	        //2.����Ϊ�գ���λ��
			Node* cur = root;
			Node* parent = nullptr;
			while(cur)
			{
				if (cur->_kv == kv)
				{
					break;
				}
				else if (kv < cur->_kv)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					parent = cur;
					cur = cur->_right;
				}
			}
			//��ʱcurΪ�գ���ʾû�ҵ�
			if (cur == nullptr)
				return false;

			//3.ɾ��Ԫ��
			//������Ϊ�գ�����ָ���������
			if (cur->_left == nullptr)
			{
				if (cur == root)//���Ϊ���ڵ�
					root = cur->_right;
				else
				{
					if (cur == parent->_left)//����ڸ��׵����
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;//����ڸ��׵��ұ�
				}
				delete cur;
			}
			//������Ϊ�գ�����ָ�������
			else if (cur->_right == nullptr)
			{
				if (cur == nullptr)
					root = cur->_left;
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				delete cur;
			}
			//�������Ҷ���Ϊ�գ�������������������������С�����Ϊ�滻���
			else
			{
				Node* replace = cur->_right;
				Node* preplace = nullptr;
				while (replace->_left)
				{
					preplace = replace;
					replace = replace->_left;
				}
				cur->_kv = replace->_kv;
				if (replace == preplace->_left)
					preplace->_left = nullptr;
				else
					preplace->_right = nullptr;
				delete replace;
				replace = nullptr;
			}
			return true;
		}

		//����
		Node* Find(const T& kv)
		{
			Node* cur = root;
			while (cur)
			{
				if (kv == cur->_kv)
					return cur;
				else if (kv < cur->_kv)
					cur = cur->_left;
				else
					cur = cur->_right;
			}
			return nullptr;
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

		void _inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_inorder(root->_left);
			cout << root->_kv << " ";
			_inorder(root->_right);
			cout << endl;
		}

		pNode root;
	};


int main()
{
	using  std::cout;
	using  std::endl;
	BSTree<int> T;
	T.Insert(1);
	T.Insert(1);
	T.Insert(3);
	T.Insert(1);
	T.Insert(6);
	T.Insert(9);
	T.Print();

	T.Erase(1);
	T.Print();
	T.Erase(9);
	T.Print();

	cout << T.Find(3) << endl;
	system("pause");
	return 0;
}