/************************************************************************

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/


#include <iostream>
#include <string>
#include <vector>

/*
                5
             /     \
            2       8
          /  \     /  \
         1    3   6    9
               \        \
                4       12
*/


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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(12);

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

    return 0;
}
