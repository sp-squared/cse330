#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Vector.h"
#include "Random.h"
#include "Map.h"

using namespace std;

int main()
{
	Map<string, int> playing;
	Map<string, double> bank;
	Map<string, double> wags;
	Vector<string> players;

	rand_seed();

	int no;
	cout << endl;
	cout << "How many are playing? ";
	cin >> no;
	cout << endl << endl;

	string name;
	for (int i = 1; i <= no; i++)
	{
		cout << "Name the player: ";
		cin >> name;
		cout << endl;

		players.push_back(name);
		playing[name] = 0;
		bank[name] = 10.0;
	}

	cout << "Each player starts with $10 in the bank."
		<< endl << endl;

	string more = "y";
	int  round = 0;
	double wag;
	int roll;
	int target;
	double pot = 0;

	while (more == "y" || more == "Y")
	{
		round++;
		cout << "Round " << round << ": Your wagers ..."
			<< endl << endl;

		for (int i = 0; i < players.size(); i++)
		{
			name = players[i];
			cout << name << "? ";
			cin >> wag;
			cout << endl;

			wags[name] = wag;
			bank[name] -= wag;
			pot += wag;
		}
		cout << endl << endl;

		cout << "The pot is $" << pot << endl << endl;

		cout << "Roll your dice ...." << endl << endl;

		std::this_thread::sleep_for(std::chrono::seconds(2));

		target = 1 + rand_int(0,5);

		for (int i = 0; i < players.size(); i++)
		{
			roll = 1 + rand_int(0,5);
			playing[players[i]] = roll;

			cout << players[i] << " ... " << roll << endl;
		}
		cout << endl << endl;


		vector<string> players_on;
		vector<string> players_above;

		for (int i = 0; i < players.size(); i++)
		{
			name = players[i];
			if (playing[name] == target)
			{
				players_on.push_back(name);
			}
			else if (playing[name] > target)
			{
				players_above.push_back(name);
			}
		}

		if (!players_on.empty())
		{
			double share = pot / players_on.size();

			cout << "YOU ARE ON TARGET (" << target
				<< ")! ... " << endl;
			for (int i = 0; i < players_on.size(); i++)
			{
				bank[players_on[i]] += share;
				cout << players_on[i] << " ... wins $"
					<< share << endl;
			}
			pot = 0;
		}
		else if (!players_above.empty())
		{
			double share = (pot / 2.0) / players_above.size();

			cout << "None on target (" << target
				<< "), but YOU ARE ABOVE ..."
				<< endl;
			for (int i = 0; i < players_above.size(); i++)
			{
				bank[players_above[i]] += share;
				cout << players_above[i] << "... wins $"
					<< share << endl;
			}
			pot = pot / 2.0;
		}
		else
			cout << "Sorry, all players lose this round"
			<< endl;

		cout << endl << endl;
		cout << "AGAIN???? [y/n]: ";
		cin >> more;
		cout << endl << endl;
	}

	cout << "GAME OVER ... THIS IS HOW YOU FARED:"
		<< endl << endl;


	Set<string> namesAtoZ = bank.keys();
	Set<string>::iterator itr = namesAtoZ.begin();

	for (; itr != namesAtoZ.end(); ++itr)
	{
		cout << "Player " << *itr << " goes home with $"
			<< bank[*itr];
		if (bank[*itr] < 0)
			cout << " ... please play the cashier on the way out" << endl;
		if (bank[*itr] > 0)
			cout << " ... your voucher for next time will be in the mail" << endl;
	}
	cout << endl << endl;
	cout << "Come back soon. Play responsibly ..."
		<< endl << endl;


	return 0;
}



/*
int main()
{
	Map<string, int> basket;
	string fruit;
	int count;
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Which fruit and how many? ";
		cin >> fruit >> count;
		cout << endl << endl;
		basket[fruit] = count;
	}

	basket.printMap();
	cout << endl << endl;

	cout << "Change number of? ";
	cin >> fruit;
	cout << "To what new count? ";
	cin >> count;
	cout << endl << endl;

	basket[fruit] = count;
	basket.printMap();
	cout << endl << endl;

	string otherfruit;
	cout << "Two fruits to remove? ";
	cin >> fruit >> otherfruit;
	cout << endl << endl;

	basket.remove(fruit);
	basket.remove(otherfruit);
	basket.printMap();

	return 0;
}
*/



