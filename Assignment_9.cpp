#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student
{
private:
   string lastName;
   string firstName;
   int totalPoints;
   static int sortKey;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;
   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;
   static const int DEFAULT_SORT_KEY = SORT_BY_LAST;

public:
   Student(string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
      long pts = DEFAULT_POINTS);

   // accessors and mutators
   string getLastName()
   {
      return lastName;
   }

   string getFirstName()
   {
      return firstName;
   }

   int getTotalPoints()
   {
      return totalPoints;
   }

   static int getSortKey()
   {
      return sortKey;
   }

   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);
   static bool setSortKey(int key);

   static int compareTwoStudents(Student firstStud, Student secondStud);
   string toString();

private:
   static bool validString(string testStr);
   static bool validPoints(int testPoints);
   static bool validSortKey(int testNumber);
};

// class StudentArrayUtilities prototype
class StudentArrayUtilities
{
public:
   static const int MEDIAN_FINDER = 2;
   static const int CHECK_EVEN = 2;
   static void printArray(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

const string Student::DEFAULT_NAME = "zz-error";
int Student::sortKey = Student::DEFAULT_SORT_KEY;

int main()
{
   Student  myClass[] =
   {
      Student("smith","fred", 95), Student("bauer","jack",123),
      Student("jacobs","carrie", 195),  Student("renquist","abe",148),
      Student("3ackson","trevor", 108),  Student("perry","fred",225),
      Student("loceff","fred", 44),  Student("stollings","pamela",452),
      Student("charters","rodney", 295),  Student("cassar","john",321),
      Student("pires", "mari", 67),  Student("castellanos", "hugo", 85),
      Student("pritikin", "molly", 316),  Student("snow", "john", 149),
      Student("wawruk", "larissa", 200)
   };

   Student myClass2[] =
   {
      Student("smith","fred", 95),  Student("bauer","jack",123),
      Student("jacobs","carrie", 195),  Student("renquist","abe",148),
      Student("3ackson","trevor", 108),  Student("perry","fred",225),
      Student("loceff","fred", 44),  Student("stollings","pamela",452),
      Student("charters","rodney", 295), Student("cassar","john",321),
      Student("pires", "mari", 67),  Student("eduardo", "hugo", 85),
      Student("smith", "molly", 316),  Student("snow", "john", 149),
      Student("santos", "larissa", 200), Student("steve", "sandra", 110)
   };

   Student myClass3[] =
   {
      Student("Feynman", "richard", 500)
   };

   int arraySize = sizeof(myClass) / sizeof(myClass[0]);

   //sort by default
   StudentArrayUtilities::printArray("Before: ", myClass, arraySize);
   StudentArrayUtilities::arraySort(myClass, arraySize);
   StudentArrayUtilities::printArray("After default sort: ",
      myClass, arraySize);

   //Sort by first name
   Student::setSortKey(Student::SORT_BY_FIRST);
   StudentArrayUtilities::arraySort(myClass, arraySize);
   StudentArrayUtilities::printArray("After sort by first: ",
      myClass, arraySize);

   //Sort by points
   Student::setSortKey(Student::SORT_BY_POINTS);
   StudentArrayUtilities::arraySort(myClass, arraySize);
   StudentArrayUtilities::printArray("After sort by points: ",
      myClass, arraySize);

   //Check median even
   Student::setSortKey(Student::SORT_BY_FIRST);
   cout << "Median of evenClass: " << StudentArrayUtilities::
      getMedianDestructive(myClass, arraySize) << endl;

   //Check preserved sort key
   if (Student::getSortKey() != Student::SORT_BY_FIRST)
      cout << "Fail to preserved sort key." << endl;
   else
      cout << "Successfully preserved sort key." << endl;

   //median for odd
   arraySize = sizeof(myClass2) / sizeof(myClass2[0]);
   cout << "Median of oddClass: " << StudentArrayUtilities::
      getMedianDestructive(myClass2, arraySize) << endl;

   //median for one array
   arraySize = sizeof(myClass3) / sizeof(myClass3[0]);
   cout << "Median of smallClass: " << StudentArrayUtilities::
      getMedianDestructive(myClass3, arraySize) << endl;
}


Student::Student(string last, string first, long points)
{
   if (!setLastName(last))
      lastName = DEFAULT_NAME;
   if (!setFirstName(first))
      firstName = DEFAULT_NAME;
   if (!setPoints(points))
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
   if (!validString(last))
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if (!validString(first))
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if (!validPoints(pts))
      return false;
   totalPoints = pts;
   return true;
}

bool Student::setSortKey(int key)
{
   if (!validSortKey(key))
      return false;
   sortKey = key;
   return true;
}

int Student::compareTwoStudents(Student firstStud, Student secondStud)
{
   int result, num;

   num = sortKey;
   switch (num)
   {
   case SORT_BY_LAST:
      result = firstStud.lastName.compare(secondStud.lastName);
      break;
   case SORT_BY_FIRST:
      result = firstStud.firstName.compare(secondStud.firstName);
      break;
   case SORT_BY_POINTS:
      result = firstStud.totalPoints - secondStud.totalPoints;
      break;
   default:
      result = -1;
   }
   return result;
}


string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " " + cnvrtLast.str()
      + ", " + cnvrtFirst.str()
      + " points: " + cnvrtPoints.str()
      + "\n";
   return resultString;
}

bool Student::validString(string testStr)
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints(int testPoints)
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}

bool Student::validSortKey(int testNumber)
{
   if (testNumber == SORT_BY_FIRST || testNumber == SORT_BY_LAST ||
      testNumber == SORT_BY_POINTS)
      return true;
   return false;
}


void StudentArrayUtilities::printArray(string title,
   Student data[], int arraySize)
{
   string output = "";
   cout << title << endl;

   for (int k = 0; k < arraySize; k++)
      output += " " + data[k].toString();

   cout << output << endl;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      if (!floatLargestToTop(array, arraySize - 1 - k))
         return;
}


bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;

   for (int k = 0; k < top; k++)
      if (Student::compareTwoStudents(data[k], data[k + 1]) > 0)
      {
         mySwap(data[k], data[k + 1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}

double StudentArrayUtilities::getMedianDestructive(Student array[],
   int arraySize)
{
   int firstNum, secondNum, clientSortKey;
   double average;

   clientSortKey = Student::getSortKey();
   Student::setSortKey(Student::SORT_BY_POINTS);
   arraySort(array, arraySize);
   if (arraySize % CHECK_EVEN == 0)
   {
      firstNum = array[arraySize / MEDIAN_FINDER].getTotalPoints();
      secondNum = array[(arraySize / MEDIAN_FINDER) - 1].getTotalPoints();
      average = (double)(firstNum + secondNum) / MEDIAN_FINDER;
   }
   else
      average = (double)array[arraySize / MEDIAN_FINDER].getTotalPoints();
   Student::setSortKey(clientSortKey);
   return average;
}
