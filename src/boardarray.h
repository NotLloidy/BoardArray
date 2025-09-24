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

            for (int i = 0; i < index; i++) {
                Entry current = array[i];
                if (entry->compare(&current)) {
                    for (int j = index; j > i; j--) {
                        if (j == SIZE) continue;
                        array[j] = array[j - 1];
                    }
                    array[i] = *entry;
                    if (index < SIZE) index++;
                    return;
                }
            }

            if(index < SIZE) {
                array[index] = *entry;
                index++;
            } else { 
                if (entry->compare(&array[index - 1])) {
                    array[index - 1] = *entry;
                }
                else {
                    cout << entry->name << "'s score is too low to be added!" << endl;
                }
            }
        }
            

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};