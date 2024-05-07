#include <iostream>
#include <fstream>
#include <queue>
#include <cctype>

using namespace std;

// Функція для створення черги символів з текстового файлу
void createQueueFromFile(queue<char>& q, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file " << filename << endl;
        return;
    }

    char c;
    while (file.get(c)) {
        q.push(c);
    }

    file.close();
}

// Функція для роздрукування черги
void printQueue(const queue<char>& q) {
    queue<char> temp = q;
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
    }
    cout << endl;
}

// Функція для вибору англійських символів та запису їх у нову чергу
void selectEnglishChars(queue<char>& original, queue<char>& englishChars, queue<char>& otherChars) {
    while (!original.empty()) {
        char c = original.front();
        if (isalpha(c) && islower(c)) {
            englishChars.push(c);
        }
        else {
            otherChars.push(c);
        }
        original.pop();
    }
}

int main() {
    queue<char> originalQueue;
    queue<char> englishCharsQueue;
    queue<char> otherCharsQueue;

    // Зчитуємо символи з файлу та створюємо чергу
    createQueueFromFile(originalQueue, "input.txt");

    // Роздрукуємо вміст початкової черги
    cout << "Original Queue:" << endl;
    printQueue(originalQueue);

    // Вибираємо англійські символи та записуємо їх у чергу englishCharsQueue,
    // а решту символів - у чергу otherCharsQueue
    selectEnglishChars(originalQueue, englishCharsQueue, otherCharsQueue);

    // Роздрукуємо вміст черги англійських символів
    cout << "English Characters Queue:" << endl;
    printQueue(englishCharsQueue);

    // Роздрукуємо вміст черги інших символів
    cout << "Other Characters Queue:" << endl;
    printQueue(otherCharsQueue);

    return 0;
}
