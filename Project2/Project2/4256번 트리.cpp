#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


/**
	1. 중위 순회로 각 노드의 인덱스를 파악할 수 있고
	2. 전위 순회한 값을 돌면서 루트의 인덱스보다 작으면 왼쪽으로 크면 오른쪽으로 순회하며 트리를 생성한다
	3. 후위순회를 하며 답을 구한다.
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