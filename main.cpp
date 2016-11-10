#include <iostream>
#include <vector>
#include <cstdbool>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

/*
    Checks whether or not a given restaurant name is already in the list
    @param restaurants
    @param restaurant_name
*/
int find_restaurant(const vector<string> restaurants, string restaurant_name) {
    for (int i = 0; i < restaurants.size(); i++) {
        if (restaurant_name == restaurants[i]) {
            int location = i;
            return location;
        }
    }
    int not_found = -1;
    return not_found;
}

/*
    Adds a new restaurant to the list (vector)
    @param restaurants
    @param restaurant_name
*/
vector<string> add_restaurant(vector<string>& restaurants, string restaurant_name) {
    restaurants.push_back(restaurant_name);
    return restaurants;
    
}

/*
    Removes a restaurant from the list
    @param restaurants A current list of all restaurants
    @param restaurant_to_remove The name of the restaurant to be removed
*/
vector<string> remove_restaurant(vector<string>& restaurants, string restaurant_to_remove, int position_of_restaurant_being_removed) {
    int last_pos = restaurants.size() - 1;
    restaurants[position_of_restaurant_being_removed] = restaurants[last_pos];
    restaurants.pop_back();
    return restaurants;
}

/*
    Shuffles the current list of restaurants
    @param 
    @param
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

int main() {
    srand(time(0));
    bool keep_going = true;
    while (keep_going) {
        vector<string> restaurants{ "Texas Road House", "Chile\'s", "Outback Steak House", "Olive Garden", "Zupas", "Costa Vida", "Tucanos", "La Jolla Groves" };

        cout << "Please select an option below:" << endl << endl;
        cout << "1 - Display all restaurants" << endl;
        cout << "2 - Add a restaurant" << endl;
        cout << "3 - Remove a restaurant" << endl;
        cout << "4 - Shuffle the vector" << endl;
        cout << "5 - Begin the tournament" << endl;
        cout << "6 - Quit the program" << endl;
        int menu_selection = 0;
        cin >> menu_selection;

        if (menu_selection == 1) {
            for (int i = 0; i < restaurants.size(); i++) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << restaurants[i];
            }
            cout << endl << endl;
        }

        if (menu_selection == 2) {
            cout << "Please enter the restaurant you'd like to add: ";
            string new_restaurant;
            cin >> new_restaurant;

            int does_restaurant_exist = find_restaurant(restaurants, new_restaurant); // At some point try including this in the find_restaurant and other functions
            if (does_restaurant_exist == -1) {
                restaurants = add_restaurant(restaurants, new_restaurant);
                cout << new_restaurant << " was added to the list." << endl << endl;
            }
            else {
                cout << endl << "That restaurant is already in the list." << endl << endl;
            }
        }

        if (menu_selection == 3) {
            cout << "Please enter the restaurant you'd like to remove: ";
            string restaurant_to_remove;
            cin >> restaurant_to_remove;

            int does_restaurant_exist = find_restaurant(restaurants, restaurant_to_remove);
            if (does_restaurant_exist == -1) {
                cout << endl << "That restaurant is not in the current list" << endl << endl;
            }
            else {
                cout << does_restaurant_exist << endl;
                int position_of_restaurant = does_restaurant_exist;
                restaurants = remove_restaurant(restaurants, restaurant_to_remove, position_of_restaurant);
                cout << restaurant_to_remove << " was removed from the list." << endl << endl;
            }
        }

        if (menu_selection == 4) {
            restaurants = shuffle(restaurants);
            cout << endl << "The list of restaurants has been shuffled!" << endl << endl;
        }



        if (menu_selection == 5) {
            //Make sure the number of restaurants is a power of 2^n, otherwise print error message. There must be a better way to do this...
            int correct_number_of_restaurants = 0;
            bool match = false;
            for (int i = 0; i < restaurants.size(); i++) {
                correct_number_of_restaurants = pow(2, i);
                if (correct_number_of_restaurants == restaurants.size()) {
                    cout << endl << "We have an appropriate number of restaurants to start the tournament." << endl << endl;
                    match = true;
                }
            }
            if (match == false) {
                cout << endl << "The tournament cannot start because we don't have the right number of restaurants to begin with." << endl << endl;
            }

            //Start the tournament using a function

            //start_tournament() {
            //
            //This function should show two restaurants, ask the user to select his favorite, and remove the loser
            //Input should be either 1 or 2 - reprompt until they provide a 1 or 2
            //Each restaurant should appear exactly once per round
            //
            //}
        }



        if (menu_selection == 6) {
            keep_going = false;
            return 1;
        }


        /*
        for (int i = 0; i < restaurants.size(); i++) {

        }
        */



    }
    
    system("pause");
    return 0;
}
