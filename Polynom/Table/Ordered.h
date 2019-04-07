#pragma once

#include"Table.h"



class Ordered : public Table
{
private:
	vector<row> v;
	int Binary_search(string&);


public:
	Ordered();
	~Ordered() {}
	void Insert(row&);
	void Delete(string&);
	Polynom *Search(string&);
};
