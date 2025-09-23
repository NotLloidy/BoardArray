#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

            //Initializes pos to use in the loop
            int pos = 0;

            //To catch if the score is lower than the lowest in the Array
            if(index == SIZE) {
                if(!(array[index - 1].compare(entry))) {
                    cout << entry->name << "'s score is too low to be added!";
                    return;
                }
            }

            //Finds the pos to where entry is higher than the current element
            for(int i = 0; i < index; i++) {
                if(array[i].compare(entry)) {
                    pos = i;
                    break;
                }
            }
            
            //Shift elements to the right starting from pos
            for(int j = index; j > pos; j--) {
                array[j] = array[j - 1];
            }

            //Insert the score to pos and increment index
            array[pos] = *entry;
            index++;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};