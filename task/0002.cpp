/************************************************************************

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/

#include "stdafx.h"


typedef struct ListNode
{
    int val;
    ListNode *next;
    
    ListNode()
      : val(0)
      , next(NULL)
    {}

    ListNode(int v)
      : val(v)
      , next(NULL)
    {}

    ~ListNode()
    {
      if (next)
      {
        delete next;
        next = NULL;
      }
    }
}ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int jinwei)
{
  if (l1 == NULL && l2 == NULL && jinwei == 0)
  {
    return NULL;
  }

  int v1 = l1 ? l1->val : 0;
  int v2 = l2 ? l2->val : 0;
  int sumVal = v1 + v2 + jinwei;
  if (sumVal >= 10)
  {
    jinwei = 1;
    sumVal -= 10;
  }
  else
  {
    jinwei = 0;
  }
  ListNode* l = new ListNode(sumVal);
  l->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, jinwei);
  return l;
}

void lc0002()
{
  ListNode* n1 = new ListNode(2);
  n1->next = new ListNode(4);
  n1->next->next = new ListNode(3);
  ListNode* n2 = new ListNode(5);
  n2->next = new ListNode(6);
  n2->next->next = new ListNode(4);

  ListNode* n3 = addTwoNumbers(n1, n2, 0);
  assert(n3 != NULL);
  assert(n3->val == 7);
  assert(n3->next != NULL);
  assert(n3->next->val == 0);
  assert(n3->next->next != NULL);
  assert(n3->next->next->val == 8);

  delete n3;
  delete n2;
  delete n1;
}
