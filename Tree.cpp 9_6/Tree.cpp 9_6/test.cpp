#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		long pre = LONG_MIN;
		//���ķ�Χ���
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (!s.empty() || p != NULL){
			//�����ǰ���û���к��ӣ�ջ�ﻹ��Ԫ�أ����ٴ�ȡջ��Ԫ��
			while (p != NULL){
				s.push(p);
				p = p->left;
				//�ߵ�������
			}
			p = s.top();//ȡջ��Ԫ��
			s.pop();
			if (p->val <= pre)
				return false;
			pre = p->val;
			p = p->right;
		}
		return true;
	}
};


int main(){
	system("pause");
	return 0;
}