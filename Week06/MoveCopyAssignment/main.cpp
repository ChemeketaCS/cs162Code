#include <iostream>

using namespace std;


class Thing {
public:
    int* data;
    int size;

    Thing() {
        cout << "Making an empty thing..." << endl;
        data = nullptr;
    }

    Thing(int dataSize) {
        cout << "Making a thing..." << endl;
        data = new int[dataSize];
        size = dataSize;
        for(int i = 0; i < size; i++) {
            data[i] = i;
            cout << ".";
        }
        cout << endl;
    }

    Thing(const Thing& other) {
        cout << "Copying a thing..." << endl;
        data = new int[other.size];
        size = other.size;
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
            cout << ".";
        }
        cout << endl;
    }

    Thing& operator=(const Thing& other) {
        cout << "Assigning from another thing..." << endl;
        if(&other != this) {
            delete data;
            data = new int[other.size];
            this->size = other.size;
            for(int i = 0; i < size; i++) {
                cout << ".";
            }
            cout << endl;
        }
        return *this;
    }

    Thing(Thing&& other) {
        cout << "Moving from one thing to another..." << endl;
        data = other.data; //copy other things pointer
        size = other.size;
        other.data = nullptr; //reset other thing to empty state
        other.size = 0;
    }

    Thing& operator=(Thing&& other) {
        cout << "Moving from one thing to another on assignment..." << endl;
        if(this != &other) {
            data = other.data; //copy other things pointer
            size = other.size;
            other.data = nullptr; //reset other thing to empty state
            other.size = 0;
        }
        return *this;
    }


    ~Thing() {
        cout << "Destroying a thing..." << endl;
    }

};


int main()
{
    Thing x(500);

    //copy x to y
    Thing y = x;

    //move x to z, x should be cleared out:
    Thing z = std::move(x);

    cout << "z size: " << z.size << endl;
    cout << "x size: " << x.size << endl;

    return 0;
}

