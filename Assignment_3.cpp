#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   // food #1 constants
   const string FOOD_1_NAME = "italian bread";
   const  int FOOD_1_CALORIES_P100G = 271; // in calories
   const  double FOOD_1_CARB_P100G = 205; // in grams
   const  double FOOD_1_PROTEIN_P100G = 35.2; // in grams
   const  double FOOD_1_FAT_P100G = 30.5; // in grams
   // food #2 constants
   const  string FOOD_2_NAME = "sun-dry tomato";
   const  int FOOD_2_CALORIES_P100G = 258; // in calories
   const  double FOOD_2_CARB_P100G = 199; // in grams
   const  double FOOD_2_PROTEIN_P100G = 34.4; // in grams
   const  double FOOD_2_FAT_P100G = 24.9; // in grams
   // food #3 constants
   const  string FOOD_3_NAME = "hard-boiled egg";
   const  int FOOD_3_CALORIES_P100G = 155; // in calories
   const  double FOOD_3_CARB_P100G = 4.5; // in grams
   const  double FOOD_3_PROTEIN_P100G = 54.9; // in grams
   const  double FOOD_3_FAT_P100G = 95.7; // in grams
   // food #4 constants
   const  string FOOD_4_NAME = "peanut butter";
   const  int FOOD_4_CALORIES_P100G = 588; // in calories
   const  double FOOD_4_CARB_P100G = 79.3; // in grams
   const  double FOOD_4_PROTEIN_P100G = 87.1; // in grams
   const  double FOOD_4_FAT_P100G = 422; // in grams
   // food #5 constants
   const  string FOOD_5_NAME = "strawberry jam";
   const  int FOOD_5_CALORIES_P100G = 286; // in calories
   const  double FOOD_5_CARB_P100G = 286; // in grams
   const  double FOOD_5_PROTEIN_P100G = 0.0; // in grams
   const  double FOOD_5_FAT_P100G = 0.0; // in grams

   string recipeName, userInputStr;
   int userInputInt, numberOfServings;
   double totalCals, totalCarb, totalProtein, totalFat;

   // initialize accumulator variables
   totalCals = 0;
   totalCarb = 0.;
   totalProtein = 0.;
   totalFat = 0.;

   // print menu
   cout << "---------- List of Supplies ----------" << endl;
   cout << " Food #1: " << FOOD_1_NAME << endl;
   cout << " Food #2: " << FOOD_2_NAME << endl;
   cout << " Food #2: " << FOOD_3_NAME << endl;
   cout << " Food #2: " << FOOD_4_NAME << endl;
   cout << " Food #3: " << FOOD_5_NAME << endl << endl;

   // name of recipe
   cout << "Name of recipe? ";
   getline(cin, recipeName);

   // # Servings
   cout << "Number of servings? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> numberOfServings;
   if ((numberOfServings < 1) || (numberOfServings > 10))
   {
      cout << "ERROR: You should choose between 1 and 10 servings" << endl;
      return 0;
   }

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   if ((userInputInt < 0) || (userInputInt > 1000))
   {
      cout << "ERROR: You should choose between 0 and 1000 grams" << endl;
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_1_CALORIES_P100G / 100.);
   totalCarb += userInputInt * (FOOD_1_CARB_P100G / 100.);
   totalProtein += userInputInt * (FOOD_1_PROTEIN_P100G / 100.);
   totalFat += userInputInt * (FOOD_1_FAT_P100G / 100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   if ((userInputInt < 0) || (userInputInt > 1000))
   {
      cout << "ERROR: You should choose between 0 and 1000 grams" << endl;
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_2_CALORIES_P100G / 100.);
   totalCarb += userInputInt * (FOOD_2_CARB_P100G / 100.);
   totalProtein += userInputInt * (FOOD_2_PROTEIN_P100G / 100.);
   totalFat += userInputInt * (FOOD_2_FAT_P100G / 100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   if ((userInputInt < 0) || (userInputInt > 1000))
   {
      cout << "ERROR: You should choose between 0 and 1000 grams" << endl;
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_3_CALORIES_P100G / 100.);
   totalCarb += userInputInt * (FOOD_3_CARB_P100G / 100.);
   totalProtein += userInputInt * (FOOD_3_PROTEIN_P100G / 100.);
   totalFat += userInputInt * (FOOD_3_FAT_P100G / 100.);

   // food #4 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_4_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   if ((userInputInt < 0) || (userInputInt > 1000))
   {
      cout << "ERROR: You should choose between 0 and 1000 grams" << endl;
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_4_CALORIES_P100G / 100.);
   totalCarb += userInputInt * (FOOD_4_CARB_P100G / 100.);
   totalProtein += userInputInt * (FOOD_4_PROTEIN_P100G / 100.);
   totalFat += userInputInt * (FOOD_4_FAT_P100G / 100.);

   // food #5 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_5_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   if ((userInputInt < 0) || (userInputInt > 1000))
   {
      cout << "ERROR: You should choose between 0 and 1000 grams" << endl;
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_5_CALORIES_P100G / 100.);
   totalCarb += userInputInt * (FOOD_5_CARB_P100G / 100.);
   totalProtein += userInputInt * (FOOD_5_PROTEIN_P100G / 100.);
   totalFat += userInputInt * (FOOD_5_FAT_P100G / 100.);

   // report results --------------------------------------------------
   cout << "\nThe nutritional value per serving of " << recipeName << " ------------" << endl;
   cout << "Calories: " << totalCals / numberOfServings << endl;
   cout << "Carbohydrates: " << totalCarb / numberOfServings << endl;
   cout << "Protein: " << totalProtein / numberOfServings << endl;
   cout << "Fat: " << totalFat / numberOfServings << endl;

   return 0;
}

/* -------------------------- run #1 ----------------------
---------- List of Supplies ----------
Food #1: italian bread
Food #2: sun-dry tomato
Food #2: hard-boiled egg
Food #2: peanut butter
Food #3: strawberry jam

Name of recipe? Peanut Butter & Jelly Sandwich
Number of servings? 1
How many grams of italian bread? 20
How many grams of sun-dry tomato? 0
How many grams of hard-boiled egg? 0
How many grams of peanut butter? 25
How many grams of strawberry jam? 25

The nutritional value per serving of Peanut Butter & Jelly Sandwich ------------
Calories: 272.7
Carbohydrates: 132.325
Protein: 28.815
Fat: 111.6
Press any key to continue . . .

----------------------------- run #2 -----------------------
---------- List of Supplies ----------
Food #1: italian bread
Food #2: sun-dry tomato
Food #2: hard-boiled egg
Food #2: peanut butter
Food #3: strawberry jam

Name of recipe? Tomato Craving
Number of servings? 2
How many grams of italian bread? 20
How many grams of sun-dry tomato? 15
How many grams of hard-boiled egg? 0
How many grams of peanut butter? 0
How many grams of strawberry jam? 0

The nutritional value per serving of Tomato Craving ------------
Calories: 46.45
Carbohydrates: 35.425
Protein: 6.1
Fat: 4.9175
Press any key to continue . . .

----------------------------- run #3 -----------------------
---------- List of Supplies ----------
Food #1: italian bread
Food #2: sun-dry tomato
Food #2: hard-boiled egg
Food #2: peanut butter
Food #3: strawberry jam

Name of recipe? Protein Power
Number of servings? 1
How many grams of italian bread? 30
How many grams of sun-dry tomato? 0
How many grams of hard-boiled egg? 100
How many grams of peanut butter? 0
How many grams of strawberry jam? 0

The nutritional value per serving of Protein Power ------------
Calories: 236.3
Carbohydrates: 66
Protein: 65.46
Fat: 104.85
Press any key to continue . . .

----------------------------- run #4 Error Serving -----------------------
---------- List of Supplies ----------
Food #1: italian bread
Food #2: sun-dry tomato
Food #2: hard-boiled egg
Food #2: peanut butter
Food #3: strawberry jam

Name of recipe? Party on
Number of servings? 12
ERROR: You should choose between 1 and 10 servings
Press any key to continue . . .

----------------------------- run #5 Error Grams -----------------------
---------- List of Supplies ----------
Food #1: italian bread
Food #2: sun-dry tomato
Food #2: hard-boiled egg
Food #2: peanut butter
Food #3: strawberry jam

Name of recipe? Super Caloric
Number of servings? 5
How many grams of italian bread? 100
How many grams of sun-dry tomato? 300
How many grams of hard-boiled egg? 1001
ERROR: You should choose between 0 and 1000 grams
Press any key to continue . . .
--------------------------------------------------------------- */