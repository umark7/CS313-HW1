//
// Created by Hema Muni on 3/25/21.
//

#ifndef HOMEWORK_ONE_QUESTION11_H
#define HOMEWORK_ONE_QUESTION11_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurant {
protected:
    string r_name;
    string r_address;
    int r_table;

public:
    Restaurant(string name, string address) : r_name{name}, r_address{address} {}
    //The interface has to be implemented in derived class.
    virtual vector<string> menu() = 0;

    //gets the Restaurant name
    string getName() {
        return r_name;
    }
    //gets the Restaurant address
    string getAddress() {
        return r_address;
    }
    //gets the amount of tables
    int getTable(){
        return r_table;
    }
};


class Italian_Restaurant : public Restaurant {
public:
    Italian_Restaurant(string name, string address) : Restaurant(name, address) {}

    //Copy assignment operator overloading
    void operator = (const Italian_Restaurant &IR) {
        r_name = IR.r_name;
        r_address = IR.r_address;
    }
    //overriding the virtual menu function
    vector<string> menu() override{
        vector<string> italian_menu{"pasta", "pizza", "calzone", "caprese chicken", "rosemary mushroom risotto",
                                    "water", "wine", "soft drinks", "italian sodas"};
        return italian_menu;
    }
};



class Greek_Restaurant : public Restaurant {
public:
    Greek_Restaurant(string name, string address) : Restaurant(name, address) {}
    //Copy assignment operator overloading
    void operator = (const Greek_Restaurant &GR) {
        r_name = GR.r_name;
        r_address = GR.r_address;
    }
    //overriding the virtual menu function
    vector<string> menu() override{
        vector<string> greek_menu{"gyro", "dolmadakia (stuffed grape leaves)", "tomatokeftedes (Tomato Fritters)",
                                  "Yellow Split Pea Puree", "Greek Salad", "water", "soft drinks", "beer"};
        return greek_menu;
    }
};



class Chinese_Restaurant : public Restaurant {
public:
    Chinese_Restaurant(string name, string address) : Restaurant(name, address) {}
    //Copy assignment operator overloading
    void operator = (const Chinese_Restaurant &CR) {
        r_name = CR.r_name;
        r_address = CR.r_address;
    }
    //overriding the virtual menu function
    vector<string> menu() override{
        vector<string> chinese_menu{"noodles", "steamed dumplings", "egg foo young", "hot and sour soup",
                                    "water", "soft drinks", "alcohol"};
        return chinese_menu;
    }
};

template<typename T>
void read(T& theRestaurant) {
    vector<string> newMenu = theRestaurant.menu();
    cout << "The menu for " << theRestaurant.getName() << " is" << endl;
    //prints out each item from the restaurant
    for(int i = 0; i < newMenu.size(); i++) {
        cout << newMenu[i] << endl;
    }
}

template <typename T>
class Reader_Robot {
private:
    T restaurant_type;
public:
    Reader_Robot(T restaurant) : restaurant_type(restaurant) {}
    void read() {
        //gets the restaurant menu from the over ridden function
        vector<string> newMenu = restaurant_type.menu();
        cout << "The menu for " << restaurant_type.getName() << " is" << endl;

        //prints out each item from the restaurant
        for(int i = 0; i < newMenu.size(); i++) {
            cout << newMenu[i] << endl;
        }
        cout << endl;
    }
};

#endif //HOMEWORK_ONE_QUESTION11_H
