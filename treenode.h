#ifndef _TREENODE_H_
#define _TREENODE_H_

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

  string str()
  {
    char tmp[128] = { 0 };
    _itoa_s(val, tmp, 128, 10);
    return string(tmp);
  }

}TreeNode;

void dfs(TreeNode* node, string path, stringarray& paths);
void binaryTreePaths(TreeNode* root, stringarray& paths);

#endif//_TREENODE_H_
