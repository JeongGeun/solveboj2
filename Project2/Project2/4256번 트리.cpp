#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


/**
	1. ���� ��ȸ�� �� ����� �ε����� �ľ��� �� �ְ�
	2. ���� ��ȸ�� ���� ���鼭 ��Ʈ�� �ε������� ������ �������� ũ�� ���������� ��ȸ�ϸ� Ʈ���� �����Ѵ�
	3. ������ȸ�� �ϸ� ���� ���Ѵ�.
***/
class node {
public:
	int num;
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
		num = 0;
	}
	~node()
	{
		delete this;
	}
};

node* root;
int arr[1001];
int top;

void makeTree(node* p,node* n)
{
	if (arr[p->num] > arr[n->num])
	{
		if (p->left == NULL) p->left = n;
		else makeTree(p->left, n);
	}
	else
	{
		if (p->right == NULL) p->right = n;
		else makeTree(p->right, n);
	}
}
void postorder(node* root)
{
	if (root->left != NULL) postorder(root->left);
	if (root->right != NULL) postorder(root->right);
	if (root->num != top)
		cout << root->num << " ";
	else
		cout << root->num ;

}

int main()
{

	int t;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		root = new node();
		vector<int>pre;
		vector<int>in;
		top = 0;

		for (int i = 1; i <= n; i++)
		{
			int b;
			cin >> b;
			pre.push_back(b);
			if (i == 1) top = b;
		}

		for (int i = 1; i <= n; i++)
		{
			int b;
			cin >> b;
			in.push_back(b);
			arr[b] = i;
		}
		root->num = top;
		for (int i = 1; i <pre.size(); i++)
		{
			node* cur = new node();
			cur->num = pre[i];
			makeTree(root,cur);
		}
		postorder(root);
		cout << endl;
		//delete root;
	}





}