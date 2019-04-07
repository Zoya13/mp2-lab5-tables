
#pragma once
#include"Table.h"



class Disordered : public Table
{
private:
	vector<row> v;
public:
	Disordered();
	~Disordered() {}
	void Insert(row&);
	void Delete(string&);
	Polynom* Search(string&);
};
