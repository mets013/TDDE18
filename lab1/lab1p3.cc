#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

    // Variables ------------------------------------------

    ifstream ifs{"lab1p3.cc"}; // change file here
    
    string word{},
           longest_word{},
           shortest_word{};

    int    counter{0},
           word_length{};

    double average_length{};


    // Read file ------------------------------------------

    while (ifs >> word) { // read file until it ends 

        if (counter == 0) { 
        // uses the first word from the file as longest and
        // shortest initally to prevent "hårdkodning"
            longest_word = word;
            shortest_word = word;
        // for example, if you say shorest word is intially "hej"
        // but then you have a file where every word is longer than
        // 3 letters, then it becomes wrong
        }

        ++counter; // counts the words...
        word_length += size(word); //sums the word lengths

        if (size(word) > size(longest_word)) { 
            // this works but it will take the first 
            // longest word in the file, not last or middle etc...
            longest_word = word;
        }

        if (size(word) < size(shortest_word)) {
            shortest_word = word; 
            // same here as for longest, also not so good
            // since for example it says '{' is smallest 
            // it is not a "word" when you run it on this
            // file
        }


    }

    // Calculate average length ---------------------------

    average_length = static_cast<double>(word_length)/counter;
    // convert either word_length or counter to double so we 
    // get decimals in the average word length, both don't
    // need to be converted since c++ uses the most precise format
    // (lecture 1)

    // Statistics and print -------------------------------

    cout << "There are " << counter << " words in the file.\n"

         << "The shortest word was \"" << shortest_word 
         << "\" with " << size(shortest_word) << " characters(s).\n"

         << "The longest word was \"" << longest_word 
         << "\" with " << size(longest_word) << " character(s).\n"

         << "The average length was " << setprecision(2) << fixed 
         << average_length << " characters(s).\n";

    return 0;

}
