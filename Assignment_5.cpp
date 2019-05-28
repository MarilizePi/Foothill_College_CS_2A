#include <iostream>
#include <string>
using namespace std;

char getKeyLetter();
string getString();
string maskLetter(string theString, char keyLetter);
string removeLetter(string theString, char keyLetter);
int countKey(string theString, char keyLetter);

int main()
{
   char keyCharacter;
   string targetString;
   string maskOutput;
   string removeOutput;
   int countOutput;

   keyCharacter = getKeyLetter();
   targetString = getString();

   maskOutput = maskLetter(targetString, keyCharacter);
   removeOutput = removeLetter(targetString, keyCharacter);
   countOutput = countKey(targetString, keyCharacter);

   cout << "\nString with key character, \"" << keyCharacter << "\" masked:\n"
      << maskOutput << endl;

   cout << "\nString with \"" << keyCharacter << "\" removed:\n"
      << removeOutput << endl;

   cout << "\n# of occurrences of key character, \"" << keyCharacter << "\": "
      << countOutput << endl;
}

char getKeyLetter()
{
   string userInputStr, screenPrompt;
   const int NUMBER_LETTERS_ALLOWED = 1;

   screenPrompt = "Please enter a SINGLE letter to act as key: ";

   do
   {
      cout << screenPrompt;
      getline(cin, userInputStr);
   }

   while (userInputStr.length() != NUMBER_LETTERS_ALLOWED);
   return userInputStr[0];
}


string getString()
{
   string userInputStr, screenPrompt;
   const int MINIMUM_CHAR_ALLOWED = 4;
   int userInputInt = 0;

   screenPrompt = "Please enter a phrase or sentence >= 4 letters: ";

   do
   {
      cout << screenPrompt;
      getline(cin, userInputStr);
      userInputInt = userInputStr.length();
   }

   while (userInputInt < MINIMUM_CHAR_ALLOWED);
   return userInputStr;
}


string maskLetter(string theString, char keyLetter)
{
   string myStr = "";

   for (int i = 0; i < theString.length(); i++)
      if (theString[i] == keyLetter)
         myStr += "-";

      else
         myStr += theString[i];

   return myStr;
}


string removeLetter(string theString, char keyLetter)
{
   string myStr = "";

   for (int i = 0; i < theString.length(); i++)
      if (theString[i] == keyLetter)
         myStr += theString[i];

   return myStr;
}


int countKey(string theString, char keyLetter)
{
   int countInt = 0;

   for (int i = 0; i < theString.length(); i++)
      if (theString[i] == keyLetter)
         countInt++;

   return countInt;
}