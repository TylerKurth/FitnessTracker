#include <iostream>
#include <string>
using namespace std;

/*
Mifflin-St. Jeor equation. This equation is an improvement upon the Harrison-Benedict and was delevoped in 1991.
It's aim is to accurately measure Basal Metabolic Rate (BMR) without the knowledge of one's Lean Body Mass (LBM)
*/
float msjBMR(string gender, float weight, float height, int age) {
    float metricWeight = weight / 2.2;
    float metricHeight = height * 2.54;
    float BMR;
    float baseCalculation = (10 * metricWeight) + (6.25 * metricHeight) - (5 * age);
    if (gender == "male" or gender == "Male") {
        return baseCalculation - 5;
    } else {
        return baseCalculation - 161;
    }
}
/* Calculates TDEE based upon commonly-used activity multipliers. Returns TDEE based upon the user's given input for activity level, ranging from 1-5.*/
float activityLevelMult(float calculatedBMR, int exerciseMultiplier) {
    if (exerciseMultiplier == 1){
        return calculatedBMR * 1.2;
    } if (exerciseMultiplier == 2) {
        return calculatedBMR * 1.375;
    } if (exerciseMultiplier == 3) {
        return calculatedBMR * 1.55;
    } if (exerciseMultiplier == 4) {
        return calculatedBMR * 1.725;
    } else {
        return calculatedBMR * 1.9;
    }

}

int main() {
    float height;
    float weight;
    int age; 
    string gender;
    int exerciseMultiplier;
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
    cout << "Please enter your activity level based on the following information: " << endl;
    cout << "Sedentary: Little to no physical exercise: Input 1" << endl;
    cout << "Exercise 1-3 times per week: Input 2" << endl;
    cout << "Exercise 4-5 times per week: Input 3" << endl;
    cout << "Exercise 6-7 times per week: Input 4" << endl;
    cout << "Very intense exercise daily, or physical job: Input 5" << endl;
    cin >> exerciseMultiplier;
    float TDEE = activityLevelMult(calculatedBMR, exerciseMultiplier); 
    cout << "Based on your activity level, your TDEE is approximately " << TDEE << endl; 
    return 0; 
}