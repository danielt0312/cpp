#include<iostream>
using namespace std;
#include "record.h"

void record::print(void) {
    cout << "NOMBRE:" <<  name << endl;
    cout << "course1 = " << course1 
        << ", course2 = " << course2 << endl;
    cout << "avg = " << avg << endl;
        
    switch(mealPref) {
    	case NO_PREF: cout << "SIN PREFERENCIA" << endl; break;
    	case VEGETARIAN: cout << "VEGETARIANO" << endl; break;
    	case REGULAR: cout << "REGULAR" << endl; break;
    	default: cout << "DEFAULT" << endl;   
    }
}

void record::setNames(int x, int y) {
    course1 = x;
    course2 = y;
}

void record::setPref(int type) {
    switch(type){
	case 0: mealPref = NO_PREF; break;
	case 1: mealPref = REGULAR; break;
    	case 2: mealPref = VEGETARIAN; break;
    	default: mealPref = DEFAULT;
    }
}

int record::getAvg() {
    int avg = ((course1 + course) / 2)
    return avg;
}

MealType record::getPref() {
    return mealPref;
}
