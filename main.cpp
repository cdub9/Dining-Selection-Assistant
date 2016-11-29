/*
    This program helps you choose a restarant by pitting two restaurants against each other in a single 
    elimination style tournament until a single restaurant remains.
*/
#include <iostream>
#include <vector>
#include <cstdbool>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

const int NOT_FOUND = -1;
const int FIRST_OPTION = 1;
const int SECOND_OPTION = 2;
const int THIRD_OPTION = 3;
const int FOURTH_OPTION = 4;
const int FIFTH_OPTION = 5;
const int SIXTH_OPTION = 6;

/*
    Checks whether or not a given restaurant name is already in the list
    @param restaurants - The current list of restaurants
    @param restaurant_name - The name of the restaurant that we're checking to see whether or not it exists in our list
*/
int find_restaurant(const vector<string> restaurants, string restaurant_name) {
    for (int i = 0; i < restaurants.size(); i++) {
        if (restaurant_name == restaurants[i]) {
            return i;
        }
    }
    return NOT_FOUND;
}

/*
    Adds a new restaurant to the list (vector)
    @param restaurants - The current list of restaurants
    @param restaurant_name - The name of the restaurant that we're adding to the list
*/
vector<string> add_restaurant(vector<string>& restaurants, string restaurant_name) {
    restaurants.push_back(restaurant_name);
    return restaurants;
    
}

/*
    Removes a restaurant from the list
    @param restaurants - A current list of all restaurants
    @param restaurant_to_remove - The name of the restaurant to be removed
*/
vector<string> remove_restaurant(vector<string>& restaurants, string restaurant_to_remove, int position_of_restaurant_being_removed) {
    int last_pos = restaurants.size() - 1;
    restaurants[position_of_restaurant_being_removed] = restaurants[last_pos];
    restaurants.pop_back();
    return restaurants;
}

/*
    Shuffles the current list of restaurants
    @param restaurants - The list of restaurants to be randomly shuffled
*/
vector<string> shuffle(vector<string> restaurants) {
    string temp;
    int new_position = 0;
    for (int i = 0; i < restaurants.size(); i++) { // change to <= size
        new_position = rand() % restaurants.size();
        temp = restaurants[i];
        restaurants[i] = restaurants[new_position];
        restaurants[new_position] = temp;
    }
    return restaurants;
}

/*
    Check to see if the number of restaurants is a power of 2^n
    @param restaurants - The list of restaurants that we're counting to find out if the number of restaurants is a power of 2^n
*/
bool check_number_of_restaurants(const vector<string> restaurants) {
    int correct_number_of_restaurants = 0;
    bool match = false;
    for (int i = 0; i < restaurants.size(); i++) {
        correct_number_of_restaurants = pow(2, i);
        if (correct_number_of_restaurants == restaurants.size()) {
            cout << endl << "We have an appropriate number of restaurants to start the tournament." << endl << endl;
            match = true;
            return match;
        }
    }
    if (match == false) {
        cout << endl << "Invalid number of restaurants. The number of restaurants must be a power of 2 (e.g. 2^n)." << endl << endl;
    }
    return match;
}

/*
    Starts the tournament
    @param restaurants - The vector of restaurants that will be part of the tournament
*/
void start_tournament(vector<string>& restaurants) {
    for (int i = 0; i < restaurants.size(); i++) {
        bool reprompt = true;
            int user_selection = 0;
            while (reprompt == true) {
                cout << "1: " << restaurants[i] << " or 2: " << restaurants[i + 1] << "? ";
                cin >> user_selection;
                if (user_selection == FIRST_OPTION) {
                    restaurants.erase(restaurants.begin() + (i + 1));
                    if (restaurants.size() == 1) {
                        cout << endl << "The winner is " << restaurants[0] << "!" << endl << endl;
                        reprompt = false;
                    }
                    reprompt = false;
                }
                else if (user_selection == SECOND_OPTION) {
                    restaurants.erase(restaurants.begin() + i);
                    if (restaurants.size() == 1) {
                        cout << endl << "The winner is " << restaurants[0] << "!" << endl << endl;
                        reprompt = false;
                    }
                    reprompt = false;
                }
            }
        reprompt = false;
    }
}

int main() {
    srand(time(0));
    bool keep_going = true;
    vector<string> restaurants{ "Texas Road House", "Chile\'s", "Outback Steak House", "Olive Garden", "Zupas", "Costa Vida", "Tucanos", "La Jolla Groves" };

    while (keep_going) {

        cout << "Please select an option below:" << endl << endl;
        cout << "1 - Display all restaurants" << endl;
        cout << "2 - Add a restaurant" << endl;
        cout << "3 - Remove a restaurant" << endl;
        cout << "4 - Shuffle the vector" << endl;
        cout << "5 - Begin the tournament" << endl;
        cout << "6 - Quit the program" << endl;
        int menu_selection = 0;
        cin >> menu_selection;

        if (menu_selection == FIRST_OPTION) {
            for (int i = 0; i < restaurants.size(); i++) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << restaurants[i];
            }
            cout << endl << endl;
        }

        if (menu_selection == SECOND_OPTION) {
            cout << "Please enter the restaurant you'd like to add: ";
            string new_restaurant;
            cin.sync();
            getline(cin, new_restaurant);

            int does_restaurant_exist = find_restaurant(restaurants, new_restaurant); // At some point try including this in the find_restaurant and other functions
            if (does_restaurant_exist == -1) {
                restaurants = add_restaurant(restaurants, new_restaurant);
                cout << endl << new_restaurant << " was added to the list." << endl << endl;
            }
            else {
                cout << endl << "That restaurant is already in the list." << endl << endl;
            }
        }

        if (menu_selection == THIRD_OPTION) {
            cout << "Please enter the restaurant you'd like to remove: ";
            string restaurant_to_remove;
            cin.sync();
            getline(cin, restaurant_to_remove);

            int does_restaurant_exist = find_restaurant(restaurants, restaurant_to_remove);
            if (does_restaurant_exist == -1) {
                cout << endl << "That restaurant is not in the current list." << endl << endl;
            }
            else {
                cout << does_restaurant_exist << endl;
                int position_of_restaurant = does_restaurant_exist;
                restaurants = remove_restaurant(restaurants, restaurant_to_remove, position_of_restaurant);
                cout << restaurant_to_remove << " was removed from the list." << endl << endl;
            }
        }

        if (menu_selection == FOURTH_OPTION) {
            restaurants = shuffle(restaurants);
            cout << endl << "The list of restaurants has been shuffled!" << endl << endl;
        }

        if (menu_selection == FIFTH_OPTION) {
            bool begin = check_number_of_restaurants(restaurants);
            if (begin == true) {
                cout << "The tournament is starting!" << endl << endl;
                while (restaurants.size() > 1) {
                    start_tournament(restaurants);
                }
            }
            system("pause");
            keep_going = false;
            return 1;
        }

        if (menu_selection == SIXTH_OPTION) {
            keep_going = false;
            return 1;
        }
    }
    
    system("pause");
    return 0;
}
