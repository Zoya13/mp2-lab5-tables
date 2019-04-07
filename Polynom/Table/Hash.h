
#pragma once
#include "Table.h"
#include<list>
#include <math.h>
class Hash : public Table
{
private:
	vector<list<row>> v;
	unsigned int MurmurHash2(string&);
public:
	Hash();
	~Hash() {}
	void Insert(row&);
	void Delete(string&);
	Polynom* Search(string&);
};