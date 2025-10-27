#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>

#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat>& trip);
void add_goat(list<Goat>& trip, string[], string[]);
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
  display_trip(trip);

  trip.push_back(Goat("Vida", 14, "Red"));
  trip.push_back(Goat("Nola", 14, "Gold"));
  trip.push_back(Goat("Todd", 9, "Green"));

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
// int select_goat(list<Goat> trip) {}

void add_goat(list<Goat>& trip, string[], string[]) {}

void delete_goat(list<Goat>& trip) {
  if (trip.empty()) {
    cout << "Trip has no goats.\n";
    return;
  }
}

void display_trip(list<Goat> trip) {
  if (trip.empty()) {
    cout << "Trip has no goats.\n";
    return;
  }

  int i = 1;
  for (const auto& g : trip) {
    cout << "[" << i++ << "]" << g.get_name() << "(" << g.get_age() << ", "
         << g.get_color() << ")\n";
  }
}