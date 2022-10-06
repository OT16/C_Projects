//Author: Oscar Tepepan-Aviles
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
	int neighbormax = 3;

	ifstream lifetext("life.txt");
	if (lifetext) {
		cout << "File opened\n";
	}
	if (!lifetext) {
		cout << "File did not open\n";
	}
	string line;
	vector<string> vectorsoflines;
	while (getline(lifetext, line)) {
		vectorsoflines.push_back(line);
	}
	lifetext.close();
	cout << "Initial World\n";
	cout << "====================\n";
	for (size_t i = 0; i < vectorsoflines.size(); ++i) {
		for (size_t j = 0; j < vectorsoflines[i].size(); ++j) {
			//cout << i << j;
			cout << vectorsoflines[i][j] << ' ';
		}
		cout << endl;
	}
	vector<string> vectorofchar(vectorsoflines);
	for (size_t i = 1; i < 11; ++i) {
		cout << "Generation: "<< i<< "\n";
		cout << "====================\n";
		for (size_t i = 0; i < vectorsoflines.size(); ++i) {
			for (size_t j = 0; j < vectorsoflines[i].size(); ++j) {
				//checking for alive neighboors j=x i=y
				int neighboralive = 0;
				
				//cout << i << j;
				if (j > 0 && vectorsoflines[i][j-1] == '*') {
					neighboralive += 1;
					//cout << "le";
				}
				if (j < 19 && vectorsoflines[i][j+1] == '*') {
					neighboralive += 1;
					//cout << "ri";
				}
				if (i > 0 && vectorsoflines[i-1][j] == '*') {
					neighboralive += 1;
					//cout << "to";
				}
				if (i < 7 && vectorsoflines[i+1][j] == '*') {
					neighboralive += 1;
					//cout << "bo";
				}
				if (i > 0 && j > 0 && vectorsoflines[i-1][j-1] == '*') {
					neighboralive += 1;
					//cout << "TL";
				}
				if (j < 19 && i > 0 && vectorsoflines[i-1][j+1] == '*') {
					neighboralive += 1;
					//cout << "TR";
				}
				if (j > 0 && i < 7 && vectorsoflines[i+1][j-1] == '*') {
					neighboralive += 1;
					//cout << "BL";
				}
				if (i < 7 && j < 19 && vectorsoflines[i+1][j+1] == '*') {
					neighboralive += 1;
					//cout << "BR";
				}
				//Test rules
				if (vectorsoflines[i][j] == '*' && neighboralive < 2) {
					vectorofchar[i][j] = '-';
				}
				if (vectorsoflines[i][j] == '*' && (neighboralive == 2 || neighboralive == 3)) {
					vectorofchar[i][j] = '*';
				}
				if (neighboralive > 3) {
					vectorofchar[i][j] = '-';
				}
				if (vectorsoflines[i][j] == '-' && neighboralive == 3) {
					vectorofchar[i][j] = '*';
				}
				
				cout << vectorofchar[i][j] << ' ';
			}
			cout << endl;
		}
		for (size_t i = 0; i < vectorsoflines.size(); ++i) {
			for (size_t j = 0; j < vectorsoflines[i].size(); ++j) {
				vectorsoflines[i][j] = vectorofchar[i][j];
			}
		}
	}
		
}