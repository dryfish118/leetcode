/************************************************************************
编写一个方法，计算从 0 到 n(含 n) 中数字 2 出现的次数。

示例 :

输入: 25
  输出 : 9
  解释 : (2, 12, 20, 21, 22, 23, 24, 25)(注意 22 应该算作两次)

  提示：

  n <= 10 ^ 9

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/number-of-2s-in-range-lcci
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
************************************************************************/

/************************************************************************

0 1 2 3 4 5 6 7 8 9
10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29
30 31 32 33 34 35 36 37 38 39

25 ==> 9
31 ==> 13
32 ==> 14
33 ==> 14

119 ==> 
120 ==> 
121 ==> 
130 ==> 
131 ==> 

************************************************************************/

#include "stdafx.h"

int numberOf2sInRange(int n)
{
  switch (n)
  {
  case 0:
  case 1:
    return 0;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
    return 1;
  case 100:
  case 1000:
  case 10000:
  case 100000:
  case 1000000:
  case 10000000:
  case 100000000:
  case 1000000000:
    return 10 * (numberOf2sInRange(n / 10) + 1);
  }

  int ji = 10;
  while (n / ji > 10)
  {
    ji *= 10;
  }

  int diwei = n % ji;
  int gaowei = n / ji;
  int count = gaowei * numberOf2sInRange(ji) + numberOf2sInRange(diwei);
  if (gaowei == 2)
  {
    count += diwei + 1;
  }
  else if (gaowei > 2)
  {
    count += ji;
  }
  return count;
}

void rv1706()
{
  for (int i = 1; i < 1000; i++)
  {
    printf("i(%d) ==> %d\t", i, numberOf2sInRange(i));
    if ((i % 5) == 0)
    {
      printf("\n");
    }
  }

//   printf("%d\n", numberOf2sInRange(25));
//   printf("%d\n", numberOf2sInRange(31));
//   printf("%d\n", numberOf2sInRange(32));
//   printf("%d\n", numberOf2sInRange(33));
//  printf("%d\n", numberOf2sInRange(119));
//   printf("%d\n", numberOf2sInRange(120));
//   printf("%d\n", numberOf2sInRange(121));
//   printf("%d\n", numberOf2sInRange(122));
//   printf("%d\n", numberOf2sInRange(419));
//   printf("%d\n", numberOf2sInRange(420));
//   printf("%d\n", numberOf2sInRange(421));
//   printf("%d\n", numberOf2sInRange(422));
//   printf("%d\n", numberOf2sInRange(1419));
//   printf("%d\n", numberOf2sInRange(1420));
//   printf("%d\n", numberOf2sInRange(1421));
//   printf("%d\n", numberOf2sInRange(1422));
}
