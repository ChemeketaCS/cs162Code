#include <iostream>
#include <cassert>

using namespace std;


const int MAX_LENGTH = 256;

//Simplistic represntation of a string using an array of chars
class SimpleString {
private:
    char letters[MAX_LENGTH] = {};     //storage for string
                                        // = {0} initializes with all null chars
    int length = 0;                     //logical length of string

public:
    SimpleString() {
        length = 0;

        //If we did not initialize the array where it was declared
        // would need a loop to do so in constructor
        for(int i = 0; i < MAX_LENGTH; i++)
            letters[i] = ' ';
    }

    void appendLetter(char c) {
        //logical length of string is location next char goes
        letters[length] = c;
        length++;
    }

    void changeLetter(int index, char c) {
        //blow up if given a bad index
        assert(index >= 0 && index < length);

        letters[index] = c;
    }

    char getLetter(int index) {
        //blow up if given a bad index
        assert(index >= 0 && index < length);

        return letters[index];
    }

    int getLength() {
        return length;
    }

    void print() {
        for(int i = 0; i < length; i++) {
            cout << letters[i];
        }
    }


};


int main()
{
    SimpleString s1;
    s1.appendLetter('H');
    s1.appendLetter('e');
    s1.appendLetter('l');
    s1.appendLetter('l');

    s1.print();
    cout << " is " << s1.getLength() << " letters" << endl;

    s1.appendLetter('o');

    s1.print();
    cout << " is " << s1.getLength() << " letters" << endl;

    s1.changeLetter(0, 'J');
    s1.print();
    cout << " is " << s1.getLength() << " letters" << endl;

    return 0;
}

