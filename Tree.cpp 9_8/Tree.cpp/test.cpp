#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//�������ֵܱ�ʾ�����Ĳ�α���
class Solution {
public:
	void LevelOrder(TreeNode* T){
		if (T == NULL)
			return;
		queue<TreeNode*> q;
		TreeNode* p;
		q.push(T);
		while (!q.empty()){
			p = q.front();
			q.pop();
			cout << p->val << " ";
			p = p->left;
			while (p != NULL){
				q.push(p);
				p = p->right;
				//�ֵܺ��Լ�������ͬһ��
			}
		}
	}
};


int main(){

	system("pause");
	return 0;
}