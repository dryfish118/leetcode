/************************************************************************

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

说明：

	所有输入均为小写字母。
	不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef std::vector<std::string> stringarray;
typedef stringarray::iterator stringiter;
typedef stringarray::const_iterator stringciter;
typedef std::vector<stringarray> stringarrayarray;
typedef stringarrayarray::iterator stringarrayiter;
typedef std::set<char> charset;
typedef std::map<charset, stringarray> stringarraymap;
typedef stringarraymap::iterator stringarraymapiter;

charset hashString(const std::string& str)
{
	charset chs;
	for (size_t i = 0; i < str.length(); i++)
	{
		chs.insert(str.at(i));
	}
	return chs;
}

void groupAnagrams(const stringarray& strs, stringarrayarray& rets)
{
	stringarraymap m;
	for (stringciter i = strs.begin(); i != strs.end(); i++)
	{
		charset key = hashString(*i);
		stringarraymapiter pos = m.find(key);
		if (pos == m.end())
		{
			stringarray a;
			a.push_back(*i);
			m.insert(std::make_pair(key, a));
		}
		else
		{
			pos->second.push_back(*i);
		}
	}

	for (stringarraymapiter i = m.begin(); i != m.end(); i++)
	{
		rets.push_back(i->second);
	}
}

int main()
{
	stringarray strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	stringarrayarray rets;
	groupAnagrams(strs, rets);

	std::cout << "[" << std::endl;
	int count = 1;
	for (stringarrayiter i = rets.begin(); i != rets.end(); i++)
	{
		stringarray& sa = *i;
		std::cout << "  [";
		for (stringiter j = sa.begin(); j != sa.end(); j++)
		{
			if (j != sa.begin())
			{
				std::cout << ",";
			}
			std::cout << "\"" << *j << "\"";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "]" << std::endl;
	
	return 0;
}
