# include <string>
# include <iostream>
# include <sstream>
# include <ctime>
using namespace std;

class TripleString
{
private:
   string string1, string2, string3;
   //helper method
   bool validString(string str);
public:
   static const int MAX_LEN = 20;

   //default constructor
   TripleString();

   //mutators
   bool setString1(string randomString1);
   bool setString2(string randomString2);
   bool setString3(string randomString3);
   //acessors
   string getString1();
   string getString2();
   string getString3();
};

//global-scope method prototypes
int getBet();
string randString();
TripleString pull();
int getPayMultiplier(TripleString thePull);
void display(TripleString thePull, int winnings);


int main()
{
   srand((unsigned)time(NULL));
   int bet, win;
   TripleString thePull;

   while (true) {
      bet = getBet();
      if (bet == 0) {
         cout << "See you next time!" << endl << endl;
         break;
      }
      thePull = pull();
      win = bet*getPayMultiplier(thePull);
      display(thePull, win);
   }
   return 0;
}


int getBet()
{
   string userInputStr;
   int userInputInt;
   int legalBetMin = 1;
   int legalBetMax = 50;

   while (true)
   {
      cout << "\nHow much would you like to bet (" << legalBetMin << " - "
         << legalBetMax << ")" << " or 0 to quit? ";
      getline(cin, userInputStr);
      istringstream(userInputStr) >> userInputInt;

      if ((userInputInt >= legalBetMin) && (userInputInt <= legalBetMax)
         || userInputInt == 0)
         break;
      else
         continue;
   }
   return userInputInt;
}


TripleString pull()
{
   TripleString thePull;
   string str1 = randString();
   string str2 = randString();
   string str3 = randString();
   thePull.setString1(str1);
   thePull.setString2(str2);
   thePull.setString3(str3);
   return thePull;
}


string randString()
{
   int randomRemain;
   string stringValue;

   static const int MAX_RANGE = 1000;
   static const double BAR_MIN = 1;
   static const double BAR_MAX = 400;
   static const double CHER_MIN = 401;
   static const double CHER_MAX = 700;
   static const double SPACE_MIN = 701;
   static const double SPACE_MAX = 750;

   randomRemain = rand() % MAX_RANGE;

   if ((randomRemain >= BAR_MIN) && (randomRemain <= BAR_MAX))
      stringValue = "BAR";
   else if ((randomRemain >= CHER_MIN) && (randomRemain <= CHER_MAX))
      stringValue = "cherries";
   else if ((randomRemain >= SPACE_MIN) && (randomRemain <= SPACE_MAX))
      stringValue = "(space)";
   else
      stringValue = "7";

   return stringValue;
}


int getPayMultiplier(TripleString thePull)
{
   int result = 0;
   const int CHERRIES_VALUE = 5;
   const int CHERRIES_VALUE_2 = 15;
   const int CHERRIES_VALUE_3 = 30;
   const int BAR_VALUE = 50;
   const int SEVEN_VALUE = 100;

   if ((thePull.getString1() == "cherries") && 
      (thePull.getString2() != "cherries") &&
      (thePull.getString3() == "space" || thePull.getString3() == "BAR" ||
         thePull.getString3() == "7"))
      result = CHERRIES_VALUE;

   else if ((thePull.getString1() == "cherries") && 
      (thePull.getString2() == "cherries") &&
      (thePull.getString3() != "cherries"))
      result = CHERRIES_VALUE_2;

   else if ((thePull.getString1() == "cherries") && 
      (thePull.getString2() == "cherries") &&
      (thePull.getString3() == "cherries"))
      result = CHERRIES_VALUE_3;

   else if (thePull.getString1() == "BAR" && 
      thePull.getString2() == "BAR" &&
      thePull.getString3() == "BAR")
      result = BAR_VALUE;

   else
      if (thePull.getString1() == "7" && thePull.getString2() == "7" &&
         thePull.getString3() == "7")
         result = SEVEN_VALUE;

   return result;
}


void display(TripleString thePull, int winnings)
{
   string strings = thePull.getString1() + " " +
      thePull.getString2() + " " + thePull.getString3();


   if (winnings == 0)
   {
      cout << "whirrrrrr .... and your pull is ..." << endl;
      cout << strings << endl;
      cout << "sorry, you lose." << endl << endl;
   }

   else
   {
      cout << "whirrrrrr .... and your pull is ..." << endl;
      cout << strings << endl;
      cout << "congratulations, you win: " << winnings << endl << endl;
   }

}


TripleString::TripleString()
{
   string1 = "";
   string2 = "";
   string3 = "";
}

bool TripleString::setString1(string randomString1)
{
   if (!validString(randomString1))
      return false;

   string1 = randomString1;
   return true;
}

bool TripleString::setString2(string randomString2)
{
   if (!validString(randomString2))
      return false;

   string2 = randomString2;
   return true;
}

bool TripleString::setString3(string randomString3)
{
   if (!validString(randomString3))
      return false;

   string3 = randomString3;
   return true;
}

bool TripleString::validString(string str)
{
   if (str.length() <= MAX_LEN)
      return true;
   else
      return false;
}

string TripleString::getString1()
{
   return string1;
}

string TripleString::getString2()
{
   return string2;
}

string TripleString::getString3()
{
   return string3;
}

// "pull groups #47 resulted in all cherries and 
//pull group #35 resulted in all BARs." 

/********************** RUN **********************


How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
BAR 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 2
whirrrrrr .... and your pull is ...
BAR BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 4
whirrrrrr .... and your pull is ...
BAR cherries 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 5
whirrrrrr .... and your pull is ...
7 cherries BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
7 BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 2
whirrrrrr .... and your pull is ...
7 BAR BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 6
whirrrrrr .... and your pull is ...
cherries cherries BAR
congratulations, you win: 90


How much would you like to bet (1 - 50) or 0 to quit? 5
whirrrrrr .... and your pull is ...
cherries 7 BAR
congratulations, you win: 25


How much would you like to bet (1 - 50) or 0 to quit? 4
whirrrrrr .... and your pull is ...
7 BAR BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 33
whirrrrrr .... and your pull is ...
7 cherries cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
BAR cherries BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 12
whirrrrrr .... and your pull is ...
7 7 BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 11
whirrrrrr .... and your pull is ...
BAR 7 BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 6
whirrrrrr .... and your pull is ...
cherries cherries 7
congratulations, you win: 90


How much would you like to bet (1 - 50) or 0 to quit? 51

How much would you like to bet (1 - 50) or 0 to quit? 50
whirrrrrr .... and your pull is ...
7 cherries 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 34
whirrrrrr .... and your pull is ...
7 cherries BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 88

How much would you like to bet (1 - 50) or 0 to quit? 656

How much would you like to bet (1 - 50) or 0 to quit? 4
whirrrrrr .... and your pull is ...
cherries BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? p

How much would you like to bet (1 - 50) or 0 to quit? 7
whirrrrrr .... and your pull is ...
(space) cherries BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 45
whirrrrrr .... and your pull is ...
BAR 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 46
whirrrrrr .... and your pull is ...
7 7 BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 32
whirrrrrr .... and your pull is ...
BAR BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
7 BAR BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 54

How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
BAR BAR 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
BAR cherries cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
(space) 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 9
whirrrrrr .... and your pull is ...
cherries cherries 7
congratulations, you win: 135


How much would you like to bet (1 - 50) or 0 to quit? 34
whirrrrrr .... and your pull is ...
BAR BAR 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
7 cherries BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 11
whirrrrrr .... and your pull is ...
(space) BAR 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 10
whirrrrrr .... and your pull is ...
7 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 9
whirrrrrr .... and your pull is ...
BAR BAR BAR
congratulations, you win: 450


How much would you like to bet (1 - 50) or 0 to quit? 8
whirrrrrr .... and your pull is ...
BAR 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 5
whirrrrrr .... and your pull is ...
7 BAR 7
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 43
whirrrrrr .... and your pull is ...
cherries BAR BAR
congratulations, you win: 215


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
cherries BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 23
whirrrrrr .... and your pull is ...
cherries BAR BAR
congratulations, you win: 115


How much would you like to bet (1 - 50) or 0 to quit? 5
whirrrrrr .... and your pull is ...
BAR 7 cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 43
whirrrrrr .... and your pull is ...
cherries cherries (space)
congratulations, you win: 645


How much would you like to bet (1 - 50) or 0 to quit? 48
whirrrrrr .... and your pull is ...
(space) (space) BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 26
whirrrrrr .... and your pull is ...
7 BAR BAR
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
7 BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 2
whirrrrrr .... and your pull is ...
cherries cherries BAR
congratulations, you win: 30


How much would you like to bet (1 - 50) or 0 to quit? 1
whirrrrrr .... and your pull is ...
cherries cherries cherries
congratulations, you win: 30


How much would you like to bet (1 - 50) or 0 to quit? 7
whirrrrrr .... and your pull is ...
BAR BAR cherries
sorry, you lose.


How much would you like to bet (1 - 50) or 0 to quit? 0
See you next time!

Press any key to continue . . .
/********************** RUN **********************/