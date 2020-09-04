#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stdlib.h>
#include <Query.h>
using namespace std;

//�ж�һ�����Ƿ�Ϊ��ȫ������

//���۵�ǰ�����û�к��ӣ����������Һ��������
//���õ���һ��ΪNULL�Ľ��ʱ���ж϶�������û�зǿս��
//����еĻ��Ͳ�����ȫ������
bool LevelOrder(Tree& T){
	if (T == NULL){
		return 0;
	}
	queue<TreeNode*> q;
	q.push(T);
	while (!q.empty()){
		TreeNode* node = q.front();
		q.pop();
		if (node != NULL){
			q.push(node->left);
			q.push(node->right);
		}
		else{//��nodeΪ��ʱ�����������Ƿ��зǿս��
			while (!q.empty()){
				node = q.front();
				q.pop();
				if (node != NULL)
		//�������зǿս�㣬������ȫ������
					return false;
			}
		}
	}
	return true;

}

int main(){

	system("pause");
	return 0;
}