#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//��д�㷨���������ֵܱ�ʾ�����ĸ߶�


//�����ֵܱ�ʾ���ĸ��ڵ�û���Һ���
//������߶Ⱦ����������ĸ߶ȼ�1
//��һ�����ӵ����������ֵܣ��ĸ߶Ⱥ͵�һ�����ӵĸ߶�����ͬ��
//���ԱȽ��������ĸ߶�+1  �� �������ĸ߶ȹ�ϵ
//���������ĸ߶�+1 > �������ĸ߶ȣ�ȡǰ�ߣ�����ȡ����
int Height(TreeNode* root){
	if (root == NULL)
		return 0;
	return Height(root->left) + 1 > Height(root->right) ? Height(root->left) + 1 : Height(root->right);

}

int main(){
	system("pause");
	return 0;
}