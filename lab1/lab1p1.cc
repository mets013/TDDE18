#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

     // Variables -----------------------------------------

     int num{};
     double real{};
     char alpha{};
     string str{};

     // ---------------------------------------------------

     cout << "Enter one integer: ";
     cin  >> num;
     cin.ignore(1000, '\n');
     cout << "You entered the number: " << num << "\n\n";

     // ---------------------------------------------------

     cout << "Enter four integers: ";
     cin  >> num; // fill buffer here with all four numbers
     cout << "You entered the numbers: " << num; 
     // first number gets sent to terminal
     cin  >> num; // still numbers in buffer!
     cout << " " << num; // push out to terminal
     cin  >> num; // and so on...
     cout << " " << num;
     cin  >> num;
     cout << " " << num << "\n\n";
     cin.ignore(1000, '\n'); 
     // clear the buffer, ignore up to 1000 inputs
     // or untill new line

     // ---------------------------------------------------

     cout <<"Enter one integer and one real number: "; 
     // endl or flush not "needed" since cout is flushed 
     // by cin so output comes out directly, 
     // new line is enough for these cases
     cin  >> num >> real;
     cin.ignore(1000, '\n');                                                 
     // clear buffer after input
     cout << "The real is: " << setw(11) << fixed << setprecision(3) << real 
     // fixed makes so that it always prints 3 decimals, even if we write 10
          << '\n' << "The integer is: " << setw(8) << num << "\n\n";

     // ---------------------------------------------------

     cout << "Enter one real and one integer number: ";
     cin  >> real >> num;
     cin.ignore(1000, '\n'); // clear input buffer after input
     cout << setfill('.') << "The real is: " << setw(11) << real << '\n'
          << "The integer is: " << setw(8) << num << "\n\n";

     // ---------------------------------------------------

     cout << "Enter a character: ";
     cin  >> alpha;
     cin.ignore(1000, '\n'); // same as above
     cout << "You entered: " << alpha << "\n\n";

     // ---------------------------------------------------

     cout << "Enter a word: ";
     cin  >> str;
     cin.ignore(1000, '\n');
     cout << "The word '" << str << "' has " 
          << size(str) << " character(s).\n\n";

     // ---------------------------------------------------

     cout << "Enter an integer and a word: ";
     cin  >> num >> str;
     cin.ignore(1000, '\n');
     cout << "You entered '" << num 
          << "' and '" << str << "'.\n\n";

     // ---------------------------------------------------

     cout << "Enter a character and a word: ";
     cin  >> alpha >> str;
     cin.ignore(1000, '\n');
     cout << "You entered the string \"" << str 
          << "\" and the character '" << alpha << "'.\n\n";
     
     // ---------------------------------------------------

     cout << "Enter a word and real number: ";
     cin  >> str >> real;
     cin.ignore(1000, '\n');
     cout <<"You entered \"" << str << "\" and \"" 
          << real << "\".\n\n";

     // ---------------------------------------------------
    
     cout << "Enter a text-line: ";
     getline(cin, str); 
     // get line takes everything in the input 
     // (removes/takes with \n unlike cin) so we do not need cin.ignore
     cout << "You entered: \"" << str << "\"\n\n";

     // ---------------------------------------------------

     cout << "Enter a second line of text: ";
     getline(cin, str);
     cout << "You entered: \"" << str << "\"\n\n";

     // ---------------------------------------------------

     cout << "Enter three words: "; 
     // same as for the four numbers, but now for string.
     cin  >> str;
     cout << "You entered: '" << str;
     cin  >> str;
     cout << " " << str;
     cin  >> str;
     cout << " " << str << "'\n";

     // ---------------------------------------------------

     return 0; // is this needed? program works without it
}