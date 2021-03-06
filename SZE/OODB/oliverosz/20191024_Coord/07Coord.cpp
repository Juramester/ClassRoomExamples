// 07Coord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

#include "Coord.h"
#include "Cartesian.h"
#include "Polar.h"

int main()
{
	Cartesian* origo = new Cartesian(0, 0);
	vector<Coord*> coords;
	coords.push_back(origo);
	coords.push_back(new Polar(1, 3.14 / 4));
	coords.push_back(new Cartesian(-1, -1));

	for (int i = 0; i < coords.size(); ++i) {
		//cout << coords[i]->toString() << endl;
		cout << *coords[i] << endl;
	}

	*coords[0] = *coords[1];

	cout << endl;
	for (vector<Coord*>::iterator it = coords.begin(); it != coords.end(); ++it) {
		//cout << coords[i]->toLongString() << endl;
		cout << (*it)->toLongString() << endl;
	}

	cout << endl << *coords[1] + *coords[2] << endl;

	cout << endl;
	list<Coord*> copy(coords.begin()+1, coords.end());
	copy.sort([](Coord* c1, Coord* c2) -> bool { return c1->getR() > c2->getR(); });
	for (auto it = copy.begin(); it != copy.end(); ++it) {
		cout << **it << endl;
	}

	for (int i = 0; i < coords.size(); ++i) {
		delete coords[i];
	}
}
