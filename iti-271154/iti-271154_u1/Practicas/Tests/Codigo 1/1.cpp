#include<iostream>
using namespace std;
#include "record.h"

int main() {
    record myrecord;
    myrecord.setMealPref(1);
    myrecord.setCourses(10, 20);
    myrecord.print();
    /*myrecord.getMealPref();
    myrecord.mealPref = VEGETARIAN;
    myrecord.name = "KIM JH";
    myrecord.course1 = 100;
    myrecord.course2 = 90; 
    int sum = myrecord.course1 + myrecord.course2;
    myrecord.avg = ((double) sum) / 2; 
    myrecord.print();*/
    return 0;
}
