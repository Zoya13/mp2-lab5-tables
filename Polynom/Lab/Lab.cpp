// Lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"../Table/Table.h"
#include"../Polynom/Polynom.h"
#include"../Table/Hash.h"
#include"../Table/Disordered.h"
#include"../Table/Ordered.h"
#include <iostream>
#include <string>

using namespace std;


void main()
{
	int k = 0, l;
	bool flag;
	int it = 0;
	int counter;
	string s,s1,s2;
	double c;
	Polynom A, B, C,A1,A2,B1,B2,C1;
	vector<Polynom>v(1024);
		Hash H;
		Ordered O;
		Disordered D;
	do {
		cout <<'\n'<< "Choose one of the items:" << '\n';
		string d[5] = { "1. Search a Polynom","2. Insert a Polynom","3. Delete a Polynom", "4. Operations with polynomials","5. Exit" };
		for (int i = 0; i < 5; i++)
			cout << d[i] << '\n';
		cout << "Input a menu number:";
		cin >> k;
		
		if (k == 5) break;
		switch (k) {
		case 1: {
			cout << "Input a name of the polynom"<<endl;
			cin >> s;
			if (H.Search(s) != NULL) {
				A = *H.Search(s);
				cout << '\n'<<A;
			}
			else
				cout << "There is not such polynom in Hash-Table"<<endl;
			if (O.Search(s) != NULL) {
				A1 = *O.Search(s);
				cout << '\n' << A1;
			}
			else
				cout << "There is not such polynom in Ordered Table" << endl;
			if (D.Search(s) != NULL) {
				A2 = *D.Search(s);
				cout << '\n' << A2;
			}
			else
				cout << "There is not such polynom in Disordered Table" << endl;
			cout << '\n' << "Number of operations to search a polynom in Hash-Table = "<<H.Count();
			cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << O.Count();
			cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << D.Count() << endl;
		break;
		}
		case 2: {

			cout << "Input a name of the polynom" << endl;
			cin >> s;
			cout << "Input polynom" << '\n';
			cin >> v[it];
			row r;
			r.data = &v[it];
			r.key = s;
			H.Insert(r);
			O.Insert(r);
			D.Insert(r);
			it++;
			cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
			cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
			cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
			break;
		}
		case 3: {
			cout << "Input a name of the polynom" << endl;
			cin >> s;
			H.Delete(s);
			O.Delete(s);
			D.Delete(s);
			cout << '\n' << "Number of operations to delete a polynom in Hash-Table = " << H.Count();
			cout << '\n' << "Number of operations to delete a polynom in Ordered Table = " << O.Count();
			cout << '\n' << "Number of operations to delete a polynom in Disordered Table = " << D.Count() << endl;
			break;
		}
		case 4: {
			int f=0;
			flag = true;
			do {
				string g[2] = { "1. Input polynomials","2. Polynomials from tables" };
				for (int i = 0; i <2; i++)
					cout << g[i] << '\n';
				cout << "Input a menu number:";
				cin >> f;
			} while ((f != 1) && (f != 2));
			if (f == 1) {
				cout << "Input a name of the polynom" << endl;
				cin >> s;
				cout << "Input polynom" << '\n';
				cin >> v[it];
				A = v[it];
				row r;
				r.data = &v[it];
				r.key = s;
				H.Insert(r);
				O.Insert(r);
				D.Insert(r);
				it++;
				cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
				cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
				cout << "Input a name of the polynom" << endl;
				cin >> s1;
				cout << "Input polynom" << '\n';
				cin >> v[it];
				B = v[it];
				row r1;
				r1.data = &v[it];
				r1.key = s1;
				H.Insert(r1);
				O.Insert(r1);
				D.Insert(r1);
				it++;
				cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
				cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
			}
			if (f == 2) {
				cout << "Input a name of the polynom" << endl;
				cin >> s;
				if (H.Search(s) != NULL) {
					A = *H.Search(s);
					cout << '\n' << A;
				}
				else {
					cout << "There is not such polynom in Hash-Table" << endl;
					flag = false;
				}
				if (O.Search(s) != NULL) {
					A1 = *O.Search(s);
					cout << '\n' << A1;
				}
				else {
					cout << "There is not such polynom in Ordered Table" << endl;
					flag = false;
				}
				if (D.Search(s) != NULL) {
					A2 = *D.Search(s);
					cout << '\n' << A2;
				}
				else {
					cout << "There is not such polynom in Disordered Table" << endl;
					flag = false;
				}
				cout << '\n' << "Number of operations to search a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << O.Count();
				cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << D.Count() << endl;
				cout << "Input a name of the polynom" << endl;
				cin >> s1;
				if (H.Search(s1) != NULL) {
					B = *H.Search(s1);
					cout << '\n' << B;
				}
				else {
					cout << "There is not such polynom in Hash-Table" << endl;
					flag = false;
				}
				if (O.Search(s1) != NULL) {
					B1 = *O.Search(s1);
					cout << '\n' << B1;
				}
				else {
					cout << "There is not such polynom in Ordered Table" << endl;
					flag = false;
				}
				if (D.Search(s1) != NULL) {
					B2= *D.Search(s1);
					cout << '\n' << B2;
				}
				else {
					cout << "There is not such polynom in Disordered Table" << endl;
					flag = false;
				}
				cout << '\n' << "Number of operations to search a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << O.Count();
				cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << D.Count() << endl;
			}
			if (flag) {
				l = 0;
				while (l < 7) {
					string e[7] = { "1. A+B=","2. A-B=","3. B-A=", "4. A*B=","5. A*c=","6. B*c=", "7. Exit" };
					for (int i = 0; i < 7; i++)
						cout << e[i] << '\n';
					cout << "Input a menu number:";
					cin >> l;
					switch (l) { 
					case 1: {
						v[it] = A + B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A+B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					case 2: {
						v[it] = A - B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A-B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					case 3: {
						v[it] = B - A;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom B-A" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					case 4: {
						v[it] = A * B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A*B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					case 5: {
						cout << "Input a const: ";
						cin >> c;
						v[it] = A * c;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A*c" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					case 6: {
						cout << "Input a const: ";
						cin >> c;
						v[it] = B * c;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of the polynom B*c" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						O.Insert(r2);
						D.Insert(r2);
						cout << v[it] << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << O.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << D.Count() << endl;
						break;
					}
					}
				}
			}
			break;
		}
				
		}
	} while (k < 5);
}
