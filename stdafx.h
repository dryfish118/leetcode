#ifndef _STDAFX_H_
#define _STDAFX_H_

#include <math.h>

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef vector<string> stringarray;
typedef stringarray::iterator stringiter;
typedef stringarray::const_iterator stringciter;
typedef vector<stringarray> stringarrayarray;
typedef stringarrayarray::iterator stringarrayiter;
typedef set<char> charset;
typedef map<charset, stringarray> stringarraymap;
typedef stringarraymap::iterator stringarraymapiter;

#include "treenode.h"

#endif // _STDAFX_H_
