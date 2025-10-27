#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>

#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat>& trip);
void add_goat(list<Goat>& trip, string names[], string colors[]);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
  srand(time(0));
  bool again;

  // read & populate arrays for names and colors
  ifstream fin("names.txt");
  string names[SZ_NAMES];
  int i = 0;
  while (fin >> names[i++]);
  fin.close();
  ifstream fin1("colors.txt");
  string colors[SZ_COLORS];
  i = 0;
  while (fin1 >> colors[i++]);
  fin1.close();

  list<Goat> trip;
  // testing functions
  display_trip(trip);

  add_goat(trip, names, colors);
  add_goat(trip, names, colors);

  trip.push_back(Goat("Vida", 14, "Red"));
  trip.push_back(Goat("Nola", 14, "Gold"));
  trip.push_back(Goat("Todd", 9, "Green"));

  int index = select_goat(trip);

  display_trip(trip);
  return 0;
}

int main_menu() {
  while (true) {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";

    int input;
    if (!(cin >> input)) {
      return 4;
    }
    return input;
  }
}

void display_trip(list<Goat> trip) {
  if (trip.empty()) {
    cout << "Trip has no goats.\n";
    return;
  }

  int i = 1;
  for (const auto& g : trip) {
    cout << "[" << i++ << "]" << g.get_name() << " (" << g.get_age() << ", "
         << g.get_color() << ")\n";
  }
}

int select_goat(list<Goat> trip) {
  if (trip.empty()) {
    cout << "Trip has no goats.\n";
    return -1;
  }

  display_trip(trip);

  int choice;
  cout << "Enter the number of the goat you want to select (0 to exit)";
  cin >> choice;

  while (choice < 0 || choice > trip.size()) {
    cout << "Invalid choice. Choose again.\n";
    cin >> choice;
  }
  if (choice == 0) {
    return -1;
  }
  return choice - 1;
}

void add_goat(list<Goat>& trip, string names[], string colors[]) {
  int rand_name = rand() % SZ_NAMES;
  int rand_age = rand() % MAX_AGE;
  int rand_color = rand() % SZ_COLORS;

  Goat g(names[rand_name], rand_age, colors[rand_color]);
  trip.push_back(g);
}

void delete_goat(list<Goat>& trip) {
  if (trip.empty()) {
    cout << "Trip has no goats.\n";
    return;
  }
}