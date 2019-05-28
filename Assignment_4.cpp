#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   int initial_stamps = 0;
   int final_stamps = 0;
   const int FREE_YOGURT = 10;
   int userInputInt;
   string userInputStr;
   char userInputChar;
   bool quit;

   quit = false;
   while (!quit)
   {
      cout << "Menu: " << endl;
      cout << "P (process Purchase)" << endl;
      cout << "S (Shut down)" << endl << endl;
      cout << "Your choice: ";
      getline(cin, userInputStr);

      userInputChar = userInputStr[0];
      if (toupper(userInputChar) == 'P')
      {
         cout << "\n" << "How many yogurts would you like to buy? ";
         getline(cin, userInputStr);
         istringstream(userInputStr) >> userInputInt;
         initial_stamps = userInputInt;
         final_stamps += userInputInt;
         cout << "\n" << "You just earned " << initial_stamps
            << " stamps and have a total of " << final_stamps
            << " stamps to use." << endl << endl;

         if (final_stamps >= FREE_YOGURT)
         {
            cout << "You qualify for a free yogurt. ";
            cout << "Would you like to use your credits ? (Y or N) ";
            getline(cin, userInputStr);
            userInputChar = userInputStr[0];

            if (toupper(userInputChar) == 'Y')
            {
               final_stamps -= FREE_YOGURT;
               cout << "\n" << "Enjoy your yogurt!" << endl;
               cout << "You now have " << final_stamps
                  << " stamps." << endl << endl;
            }

            /* Since I didn't know (yet) how to return to the specific loop,
            I decided to repeate some lines of code.*/
            else
            {
               if (toupper(userInputChar) == 'N')
               {
                  cout << "\n" << "How many yogurts would you like to buy? ";
                  getline(cin, userInputStr);
                  istringstream(userInputStr) >> userInputInt;
                  initial_stamps = userInputInt;
                  final_stamps += userInputInt;
                  cout << "\n" << "You just earned " << initial_stamps
                     << " stamps and have a total of " << final_stamps
                     << " stamps to use." << endl << endl;
               }
            }
         }
      }

      else if (toupper(userInputChar) == 'S')
      {
         cout << "See you next time!" << endl;
         quit = true;
      }

      else
      {
         if (toupper(userInputChar) != 'P' || toupper(userInputChar) != 'S')
         {
            cout << "*** Use P or S, please. ***" << endl << endl;
            continue;
         }
      }
   }
   return 0;
}

/*------------------- Run 1---------------------
Menu:
P (process Purchase)
S (Shut down)

Your choice: p

How many yogurts would you like to buy? 7

You just earned 7 stamps and have a total of 7 stamps to use.

Menu:
P (process Purchase)
S (Shut down)

Your choice: purchase

How many yogurts would you like to buy? 7

You just earned 7 stamps and have a total of 14 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) y

Enjoy your yogurt!
You now have 4 stamps.

Menu:
P (process Purchase)
S (Shut down)

Your choice: puppy

How many yogurts would you like to buy? 8

You just earned 8 stamps and have a total of 12 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) yes

Enjoy your yogurt!
You now have 2 stamps.

Menu:
P (process Purchase)
S (Shut down)

Your choice: shut
See you next time!
Press any key to continue . . .

------------------- Run 2---------------------
Menu:
P (process Purchase)
S (Shut down)

Your choice: pp

How many yogurts would you like to buy? 5

You just earned 5 stamps and have a total of 5 stamps to use.

Menu:
P (process Purchase)
S (Shut down)

Your choice: t
*** Use P or S, please. ***

Menu:
P (process Purchase)
S (Shut down)

Your choice: 9
*** Use P or S, please. ***

Menu:
P (process Purchase)
S (Shut down)

Your choice: .
*** Use P or S, please. ***

Menu:
P (process Purchase)
S (Shut down)

Your choice: p

How many yogurts would you like to buy? 9

You just earned 9 stamps and have a total of 14 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) n

How many yogurts would you like to buy? 3

You just earned 3 stamps and have a total of 17 stamps to use.

Menu:
P (process Purchase)
S (Shut down)

Your choice: p

How many yogurts would you like to buy? 0

You just earned 0 stamps and have a total of 17 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) nope

How many yogurts would you like to buy? 1

You just earned 1 stamps and have a total of 18 stamps to use.

Menu:
P (process Purchase)
S (Shut down)

Your choice: p

How many yogurts would you like to buy? 10

You just earned 10 stamps and have a total of 28 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) y

Enjoy your yogurt!
You now have 18 stamps.

Menu:
P (process Purchase)
S (Shut down)

Your choice: p

How many yogurts would you like to buy? 0

You just earned 0 stamps and have a total of 18 stamps to use.

You qualify for a free yogurt. Would you like to use your credits ? (Y or N) y

Enjoy your yogurt!
You now have 8 stamps.

Menu:
P (process Purchase)
S (Shut down)

Your choice: s
See you next time!
Press any key to continue . . .
---------------------------------------------*/