#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class DateProfile 
{
private:
   char gender, searchGender;
   int finance, romance;
   string name;

public:
   static const int MIN_ROMANCE = 0;
   static const int MAX_ROMANCE = 10;
   static const int MIN_NAME_LEN = 0;
   static const int MAX_NAME_LEN = 20;
   static const int MAX_DIFFERENCE_RANGE = 10;
   static const int AVERAGE = 2;
   static const char DEFAULT_GEND;
   static const char DEFAULT_SEARCH_GEND;
   static const int DEFAULT_ROMANCE = 0;
   static const int DEFAULT_FINANCE = 0;
   static const string DEFAULT_NAME;

private:
   static bool validChar(char validChar);
   static bool validNumber(int validNum);
   static bool validName(string validName);

   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);

public:
   void setDefaults();
   void setAll(char gender, char searchGender, int romance,
      int finance, string name);

   //constructor
   DateProfile();
   DateProfile(char gender, char searchGender, int romance,
      int finance, string name);

   //mutators and acessors
   bool setGender(char gdr);
   char getGender()
   {
      return gender;
   }

   bool setSearchGender(char searchGdr);
   char getSearchGender()
   {
      return searchGender;
   }

   bool setFinance(int  matchFinance);
   int getFinance()
   {
      return finance;
   }

   bool setRomance(int matchRomance);
   int getRomance()
   {
      return romance;
   }

   bool setName(string matchName);
   string getName()
   {
      return name;
   }

   double fitValue(DateProfile partner);
};

const char DateProfile::DEFAULT_GEND = ' ';
const char DateProfile::DEFAULT_SEARCH_GEND = ' ';
const string DateProfile::DEFAULT_NAME = "undefined";
void displayTwoProfile(DateProfile profile1, DateProfile profile2);

int main()
{
   DateProfile applicant1('M', 'F', 9, 4, "Joe Somebody");
   DateProfile applicant2('F', 'M', 8, 7, "Jane Peabody");
   DateProfile applicant3('M', 'F', 9, 10, "Steve Nobody");
   DateProfile applicant4('F', 'M', 10, 2, "Helen Anybody");

   displayTwoProfile(applicant1, applicant1);
   displayTwoProfile(applicant1, applicant2);
   displayTwoProfile(applicant1, applicant3);
   displayTwoProfile(applicant1, applicant4);

   cout << endl;
   displayTwoProfile(applicant2, applicant1);
   displayTwoProfile(applicant2, applicant2);
   displayTwoProfile(applicant2, applicant3);
   displayTwoProfile(applicant2, applicant4);

   cout << endl;
   displayTwoProfile(applicant3, applicant1);
   displayTwoProfile(applicant3, applicant2);
   displayTwoProfile(applicant3, applicant3);
   displayTwoProfile(applicant3, applicant4);

   cout << endl;
   displayTwoProfile(applicant4, applicant1);
   displayTwoProfile(applicant4, applicant2);
   displayTwoProfile(applicant4, applicant3);
   displayTwoProfile(applicant4, applicant4);

   cout << "-----------MUTATORS TEST-----------" << endl;
   if (!applicant4.setGender('P'))
      cout << "Invalid gender." << endl;
   else
      cout << "Valid gender." << endl;

   if (!applicant1.setSearchGender('X'))
      cout << "Invalid gender for searching." << endl;
   else
      cout << "Valid gender for searching." << endl;

   if (!applicant2.setFinance(-1))
      cout << "Invalid finance." << endl;
   else
      cout << "Valid finance." << endl;

   if (!applicant3.setName("Marilize Pires"))
      cout << "Invalid name." << endl;
   else
      cout << "Valid name." << endl;
   return 0;
}

void DateProfile::setDefaults()
{
   gender = DEFAULT_GEND;
   searchGender = DEFAULT_SEARCH_GEND;
   finance = DEFAULT_FINANCE;
   romance = DEFAULT_ROMANCE;
   name = DEFAULT_NAME;
}

void DateProfile::setAll(char gender, char searchGender,
   int romance, int finance, string name)
{
   if (!setGender(gender))
      this->gender = DEFAULT_GEND;
   if (!setSearchGender(searchGender))
      this->searchGender = DEFAULT_SEARCH_GEND;
   if (!setRomance(romance))
      this->romance = DEFAULT_ROMANCE;
   if (!setFinance(finance))
      this->finance = DEFAULT_FINANCE;
   if (!setName(name))
      this->name = DEFAULT_NAME;
}

DateProfile::DateProfile()
{
   setDefaults();
}

DateProfile::DateProfile(char gender, char searchGender,
   int romance, int finance, string name)
{
   setAll(gender, searchGender, romance, finance, name);
}

bool DateProfile::setGender(char gdr)
{
   if (!validChar(gdr))
      return false;
   gender = gdr;
   return true;
}

bool DateProfile::setSearchGender(char searchGdr)
{
   if (!validChar(searchGdr))
      return false;
   searchGender = searchGdr;
   return true;
}

bool DateProfile::setRomance(int matchRomance)
{
   if (!validNumber(matchRomance))
      return false;
   romance = matchRomance;
   return true;
}

bool DateProfile::setFinance(int matchApplicant)
{
   if (!validNumber(matchApplicant))
      return false;
   finance = matchApplicant;
   return true;
}

bool DateProfile::setName(string matchName)
{
   if (!validName(matchName))
      return false;
   name = matchName;
   return true;
}

bool DateProfile::validChar(char validChar)
{
   if (validChar != 'M' && validChar != 'F')
      return false;
   return true;
}

bool DateProfile::validNumber(int validNum)
{
   if (validNum < MIN_ROMANCE ||
      validNum > MAX_ROMANCE)
      return false;
   return true;
}

bool DateProfile::validName(string validName)
{
   if (validName.length() <= MIN_NAME_LEN ||
      validName.length() >= MAX_NAME_LEN)
      return false;
   return true;
}

double DateProfile::fitValue(DateProfile partner)
{
   double resultFitValue;
   if (determineGenderFit(partner) == 0)
      return 0;
   resultFitValue = ((determineRomanceFit(partner) +
      (determineFinanceFit(partner))) / AVERAGE);
   return resultFitValue;
}

double DateProfile::determineGenderFit(DateProfile partner)
{
   int genderResult;
   genderResult = 0;
   if (this->getGender() == partner.getSearchGender() &&
      this->getSearchGender() == partner.getGender())
      genderResult = 1;
   return genderResult;
}

double DateProfile::determineRomanceFit(DateProfile partner)
{
   double resultRomance;
   resultRomance = 1 - abs(((double)this->getRomance() -
      partner.getRomance()) / MAX_DIFFERENCE_RANGE);
   return resultRomance;
}

double DateProfile::determineFinanceFit(DateProfile partner)
{
   double resultFinance;
   resultFinance = 1 - abs((double)(this->getFinance() -
      partner.getFinance()) / MAX_DIFFERENCE_RANGE);
   return resultFinance;
}

void displayTwoProfile(DateProfile profile1, DateProfile profile2)
{
   cout << "Fit between " << profile1.getName() << " and "
      << profile2.getName() << ": " << endl;
   cout << profile1.fitValue(profile2) << endl;
}

/********************************RUN********************************
Fit between Joe Somebody and Joe Somebody:
0
Fit between Joe Somebody and Jane Peabody:
0.8
Fit between Joe Somebody and Steve Nobody:
0
Fit between Joe Somebody and Helen Anybody:
0.85

Fit between Jane Peabody and Joe Somebody:
0.8
Fit between Jane Peabody and Jane Peabody:
0
Fit between Jane Peabody and Steve Nobody:
0.8
Fit between Jane Peabody and Helen Anybody:
0

Fit between Steve Nobody and Joe Somebody:
0
Fit between Steve Nobody and Jane Peabody:
0.8
Fit between Steve Nobody and Steve Nobody:
0
Fit between Steve Nobody and Helen Anybody:
0.55

Fit between Helen Anybody and Joe Somebody:
0.85
Fit between Helen Anybody and Jane Peabody:
0
Fit between Helen Anybody and Steve Nobody:
0.55
Fit between Helen Anybody and Helen Anybody:
0
-----------MUTATORS TEST-----------
Invalid gender.
Invalid gender for searching.
Invalid finance.
Valid name.
Press any key to continue . . .
********************************************************************/