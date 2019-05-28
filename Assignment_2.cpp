#include <iostream>
using namespace std;

int  main()
{
   int studID = 20309982;
   int numLet = 5; //last name Pires
   int intResult;
   double doubleResult;

   cout << "My last (family) name is Pires\n" 
      << "My Student ID is 00000000\n" 
      << "The number of characters in my last name is 5" << endl << endl;

   //Expression 1
   intResult = studID % 2;
   cout << "Expression #1 ---------- : "
      << intResult << endl << endl;

   //Expression 2
   intResult = studID % numLet;
   cout << "Expression #2 ---------- : "
      << intResult << endl << endl;

   //Expression 3
   doubleResult = ((double)studID / numLet);
   cout << "Expression #3 ---------- : "
      << doubleResult << endl << endl;

   //Expression 4
   intResult = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + numLet;
   cout << "Expression #4 ---------- : "
      << intResult << endl << endl;

   //Expression 5
   doubleResult =
      ((double)100000 / (99 + ((studID - 54321) / ((numLet + 30) * 2))));
   cout << "Expression #5 ---------- : "
      << doubleResult << endl << endl;
   return 0;
}

/* ------------------- Run ---------------------
My last (family) name is Pires
My Student ID is 00000000
The number of characters in my last name is 5

Expression #1 ---------- : 0

Expression #2 ---------- : 2

Expression #3 ---------- : 4.062e+06

Expression #4 ---------- : 41

Expression #5 ---------- : 0.345465

Press any key to continue . . .
---------------------- End Run ---------------- */