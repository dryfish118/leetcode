/************************************************************************

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
		  1                         2
		 / \                       / \
		3   2                     1   3
	   /                           \   \
	  5                             4   7
输出:
合并后的树:
		 3
		/ \
	   4   5
	  / \   \
	 5   4   7

注意: 合并必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/


#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> stringarray;
typedef stringarray::iterator stringiter;
typedef stringarray::const_iterator stringciter;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0)
        , left(NULL)
        , right(NULL)
    {
    }

    TreeNode(int v)
        : val(v)
        , left(NULL)
        , right(NULL)
    {
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
            left = NULL;
        }
        if (right)
        {
            delete right;
            right = NULL;
        }
    }

    std::string str()
    {
        char tmp[128] = { 0 };
        _itoa_s(val, tmp, 128, 10);
        return std::string(tmp);
    }

}TreeNode;


TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
  TreeNode* t = NULL;
  if (t1 && t2)
  {
    t = new TreeNode(t1->val + t2->val);
    t->left = mergeTrees(t1->left, t2->left);
    t->right = mergeTrees(t1->right, t2->right);
  }
  else if (t1)
  {
    t = new TreeNode(t1->val);
    t->left = mergeTrees(t1->left, NULL);
    t->right = mergeTrees(t1->right, NULL);
  }
  else if (t2)
  {
    t = new TreeNode(t2->val);
    t->left = mergeTrees(NULL, t2->left);
    t->right = mergeTrees(NULL, t2->right);
  }
	return t;
}

void dfs(TreeNode* node, std::string path, stringarray& paths)
{
  if (node)
  {
    if (path.empty())
    {
      path += node->str();
    }
    else
    {
      path += "->" + node->str();
    }

    if (node->left)
    {
      dfs(node->left, path, paths);
    }
    if (node->right)
    {
      dfs(node->right, path, paths);
    }
    else if (!node->left)
    {
      paths.push_back(path);
    }
  }
}

void binaryTreePaths(TreeNode* root, stringarray& paths)
{
  dfs(root, std::string(), paths);
}

int main()
{
  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(3);
  root1->left->left = new TreeNode(5);
  root1->right = new TreeNode(2);

  TreeNode* root2 = new TreeNode(2);
  root2->left = new TreeNode(1);
  root2->left->right = new TreeNode(4);
  root2->right = new TreeNode(3);
  root2->right->right = new TreeNode(7);

  TreeNode* root = mergeTrees(root1, root2);

  stringarray paths;
  binaryTreePaths(root, paths);
  std::cout << "[";
  for (stringiter i = paths.begin(); i != paths.end(); i++)
  {
    if (i != paths.begin())
    {
      std::cout << ", ";
    }
    std::cout << "\"" << *i << "\"";
  }
  std::cout << "]";

  delete root;
  delete root1;
  delete root2;

	return 0;
}
