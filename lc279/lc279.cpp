/************************************************************************

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.

示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/


#include <math.h>
#include <iostream>

/*

1 = 1
2 = 1 + 1
3 = 1 + 1 + 1
4 = 4
5 = 1 + 4
6 = 1 + 1 + 4
7 = 1 + 1 + 1 + 4
8 = 4 + 4
9 = 9
10 = 1 + 9
11 = 1 + 1 + 9
12 = 1 + 1 + 1 + 9
13 = 4 + 9
14 = 1 + 4 + 9
15 = 1 + 1 + 4 + 9
16 = 16
17 = 1 + 16
18 = 1 + 1 + 16
19 = 1 + 1 + 1 + 16
20 = 4 + 16
21 = 1 + 4 + 16
22 = 1 + 1 + 4 + 16
23 = 1 + 1 + 1 + 4 + 16
24 = 4 + 4 + 16
25 = 25
26 = 1 + 25
27 = 1 + 1 + 25
28 = 1 + 1 + 1 + 25
29 = 4 + 25
30 = 1 + 4 + 25
31 = 1 + 1 + 4 + 25
*/

void numSquares(int n)
{
	double kaifang = sqrt(n);
	int quzheng = (int)kaifang;
	int jieyu = n - quzheng * quzheng;
	if (jieyu > 0)
	{
		numSquares(jieyu);
		std::cout << " ";
	}
	std::cout << quzheng;
}

int main()
{
	std::cout << "12: ";
	numSquares(12);
	std::cout << std::endl;

	std::cout << "13: ";
	numSquares(13);
	std::cout << std::endl;

	std::cout << "31: ";
	numSquares(31);
	std::cout << std::endl;

	return 0;
}
