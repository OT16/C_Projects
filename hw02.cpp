// Author: Oscar Tepepan-Aviles
/*
Automous Warriors medivial times termial game
	Game reads file provided named warriors.txt and reads the first of every command
	to either; 
	store information about a warrior using a struct
	display the number and information of each warrior in the game
	make two warriors battle eachother

Note: main is at the bottom
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior {
	//Struct of information about warrior
	string name;
	int strength;
};

void open_file(ifstream& warriors_file) {
	//function to open file, exit if file does not exists or could not open
	warriors_file.clear();
	warriors_file.open("warriors.txt");
	if (!warriors_file) { cerr << "File could not open"; exit(1); }
}
void display_vector(const vector<Warrior>& warriors_vector) {
	//Display the vector of warriors, displays name and strength of each warrior
	cout << "There are " << warriors_vector.size() << " warriors\n";
	for (const Warrior& w : warriors_vector) {
		cout << "Warrior: " << w.name << ", strength: " << w.strength
			<< ' ' << endl;
	}
}
void start_battle(Warrior& warrior1, Warrior& warrior2) {
	// Start the battle of two warriors, updates the result of strenght of each warrior after battle
	cout << warrior1.name << " battles " << warrior2.name << endl;
	if (warrior1.strength == 0 && warrior2.strength == 0) {
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else if (warrior1.strength == 0 && warrior2.strength > 0) {
		cout << "He's dead, " << warrior2.name << endl;
	}
	else if (warrior1.strength > 0 && warrior2.strength == 0) {
		cout << "He's dead, " << warrior1.name << endl;
	}
	else {
		if (warrior1.strength == warrior2.strength) {
			warrior1.strength = warrior2.strength = 0;
			cout << "Mutual Annihilation: " << warrior1.name << " and "
				<< warrior2.name << " die at each other's hands" << endl;
		}
		else if (warrior1.strength > warrior2.strength) {
			warrior1.strength -= warrior2.strength;
			warrior2.strength = 0;
			cout << warrior1.name << " defeats " << warrior2.name << endl;
		}
		else { 
			warrior2.strength -= warrior1.strength;
			warrior1.strength = 0;
			cout << warrior2.name << " defeats " << warrior1.name << endl;
		}
	}
}

void main() {
	ifstream warriors_file;
	open_file(warriors_file);
	string command;
	vector<Warrior> warriors_vector;
	while (warriors_file >> command) {
		//reads file and commands
		if (command == "Warrior") {
			Warrior warrior_info;
			warriors_file >> warrior_info.name >> warrior_info.strength;
			warriors_vector.push_back(warrior_info);
		}
		else if (command == "Status") {
			display_vector(warriors_vector);
		}
		else if (command == "Battle") {
			string str_warrior1;
			string str_warrior2;
			Warrior warrior1;
			Warrior warrior2;
			warriors_file >> str_warrior1 >> str_warrior2;
			for (Warrior& w : warriors_vector) {
				if (w.name == str_warrior1) {
					warrior1 = w;
				}
				if (w.name == str_warrior2) {
					warrior2 = w;
				}
			}
			start_battle(warrior1, warrior2);
		}

	}
	
}