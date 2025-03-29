#include <iostream>
using namespace std;

/*
Mifflin-St. Jeor equation. This equation is an improvement upon the Harrison-Benedict and was delevoped in 1991.
It's aim is to accurately measure Basal Metabolic Rate (BMR) without the knowledge of one's Lean Body Mass (LBM)
*/

int msjBMR(string gender, float weight, float height, int age) {
    float metricWeight = weight / 2.2;
    float metricHeight = height * 2.54;
    float baseCalculation = (10 * metricWeight) + (6.25 * metricHeight) - (5 * age);
    if (gender == "male" or gender == "Male") {
        return baseCalculation - 5;
    } else {
        return baseCalculation - 161;
    }   
}

int main() {
    float height;
    float weight;
    int age; 
    string gender;
    cout << "Welcome! Please enter in your gender: ";  
    cin >> gender;
    cout << "Please enter your bodyweight in pounds: ";
    cin >> weight;
    cout << "Please enter your height in inches: ";
    cin >> height;
    cout << "Please enter your age: ";
    cin >> age;
    float calculatedBMR = msjBMR(gender, weight, height, age);
    cout << "Your BRM is " << calculatedBMR << " calories! " << endl;
    return 0; 
}