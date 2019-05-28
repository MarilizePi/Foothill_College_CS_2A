# include <iostream>
# include <string>
using namespace std;

class ITunes {
private:
   string name;
   string artist;
   int bitrate;
   int totalTime;

public:
   static const int MIN_BITRATE = 64;
   static const int MAX_BITRATE = 705;
   static const int MIN_STR_LENGTH = 1;
   static const int MAX_STR_LENGTH = 80;
   static const int MIN_PLAY_TIME = 1000;
   static const int MAX_PLAY_TTME = 1000 * 60 * 60;
   static const int DEFAULT_BITRATE = 64;
   static const int DEFAULT_PLAY_TIME = 1000;
   static const string DEFAULT_STRING;

   ITunes();
   ITunes(string name, string artist, int bitrate, int totalTime);

   string getName();
   string getArtist();
   int getBitrate();
   int getTotalTime();

   bool setName(string songName);
   bool setArtist(string songArtist);
   bool setBitrate(int songBitrate);
   bool setTotalTime(int songTotalTime);


   string toString();
   void setDefaults();
   void display();

};

/* NOTE: there was a compiler error saying that I could not initialize
the string inside of the class, so I clicked on the error C2864
and their suggestion was to define it outside of the class, like this:
I hope it is ok.*/
const string ITunes::DEFAULT_STRING = "(undefined)";

int main()
{
   ITunes song1, song2;
   ITunes song3("There She Goes", "The La's", 330, 139200);
   ITunes song4("Love Me Again", "John Newman", 410, 215400);

   song1.display();
   song2.display();
   song3.display();
   song4.display();

   cout << "\n...Mutation Display..." << endl << endl;
   song1.setName("Good Morning");

   song2.setName("New York");
   song2.setArtist("Urban Cone");
   song2.setTotalTime(235000);

   song3.setArtist("Winnie The Pooh");

   song4.setName("Closing Time");
   song4.setArtist("Semisonic");
   song4.setTotalTime(34900);
   song4.setBitrate(320);

   song1.display();
   song2.display();
   song3.display();
   song4.display();

   cout << "\n...Acessor Test..." << endl << endl;
   cout << song1.getName() << endl;
   cout << song2.getTotalTime() << endl;
   cout << song3.getArtist() << endl;
   cout << song4.getBitrate() << endl << endl;

   cout << "\n...Reset to Default..." << endl << endl;
   song1.setDefaults();
   song2.setDefaults();
   song3.setDefaults();
   song4.setDefaults();

   cout << "...Display after Reset..." << endl << endl;
   song1.display();
   song2.display();
   song3.display();
   song4.display();

   cout << "\n...Filter Mutator..." << endl << endl;
   if (!song1.setName(""))
      cout << "Invalid name" << endl;
   else
      cout << "Valid name" << endl;

   if (!song2.setBitrate(123000))
      cout << "Invalid bit rate" << endl;
   else
      cout << "Valid bitrate" << endl;

   if (!song3.setTotalTime(12000))
      cout << "Invalid total time" << endl;
   else
      cout << "Valid total time" << endl;

   if (!song4.setArtist("Hello World"))
      cout << "Invalid artist" << endl;
   else
      cout << "Valid artist" << endl;
}

ITunes::ITunes()
{
   setDefaults();
}

ITunes::ITunes(string name, string artist,
   int bitrate, int totalTime)
{
   if (!setName(name))
      this->name = DEFAULT_STRING;
   if (!setArtist(artist))
      this->artist = DEFAULT_STRING;
   if (!setBitrate(bitrate))
      this->bitrate = DEFAULT_BITRATE;
   if (!setTotalTime(totalTime))
      this->totalTime = DEFAULT_PLAY_TIME;
}

bool ITunes::setName(string songName)
{
   if (songName.length() < MIN_STR_LENGTH ||
      songName.length() > MAX_STR_LENGTH)
      return false;
   else
   {
      name = songName;
      return true;
   }
}

bool ITunes::setArtist(string songArtist)
{
   if (songArtist.length() < MIN_STR_LENGTH ||
      songArtist.length() > MAX_STR_LENGTH)
      return false;
   else
   {
      artist = songArtist;
      return true;
   }
}

bool ITunes::setBitrate(int songBitrate)
{
   if (songBitrate < MIN_BITRATE ||
      songBitrate > MAX_BITRATE)
      return false;
   else
   {
      bitrate = songBitrate;
      return true;
   }
}

bool ITunes::setTotalTime(int songTotalTime)
{
   if (songTotalTime < MIN_PLAY_TIME ||
      songTotalTime > MAX_PLAY_TTME)
      return false;
   else
   {
      totalTime = songTotalTime;
      return true;
   }
}

string ITunes::getName()
{
   return name;
}

string ITunes::getArtist()
{
   return artist;
}

int ITunes::getBitrate()
{
   return bitrate;
}

int ITunes::getTotalTime()
{
   return totalTime;
}

string ITunes::toString()
{
   string stringDetails;
   int secondConvert, minuteConvert, secondDuration;
   secondConvert = 1000;
   minuteConvert = 60000;
   secondDuration = 60;

   stringDetails = "Title: " + name + " / Artist: " + artist +
      " / Playing Time: " + std::to_string(totalTime / minuteConvert) +
      " minutes and " + 
      std::to_string((totalTime / secondConvert) % secondDuration)
      + " seconds" + " / Bit Rate : " + std::to_string(bitrate) + "k ";

   return stringDetails;
}

void ITunes::setDefaults()
{
   name = DEFAULT_STRING;
   artist = DEFAULT_STRING;
   bitrate = DEFAULT_BITRATE;
   totalTime = DEFAULT_PLAY_TIME;
}

void ITunes::display()
{
   cout << toString() << endl << endl;
}


/*********************RUN*********************
Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: There She Goes / Artist: The La's / Playing Time: 2 minutes and 19 seconds / Bit Rate : 330k

Title: Love Me Again / Artist: John Newman / Playing Time: 3 minutes and 35 seconds / Bit Rate : 410k


...Mutation Display...

Title: Good Morning / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: New York / Artist: Urban Cone / Playing Time: 3 minutes and 55 seconds / Bit Rate : 64k

Title: There She Goes / Artist: Winnie The Pooh / Playing Time: 2 minutes and 19 seconds / Bit Rate : 330k

Title: Closing Time / Artist: Semisonic / Playing Time: 0 minutes and 34 seconds / Bit Rate : 320k


...Acessor Test...

Good Morning
235000
Winnie The Pooh
320


...Reset to Default...

...Display after Reset...

Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k

Title: (undefined) / Artist: (undefined) / Playing Time: 0 minutes and 1 seconds / Bit Rate : 64k


...Filter Mutator...

Invalid name
Invalid bit rate
Valid total time
Valid artist
Press any key to continue . . .
**********************************************/