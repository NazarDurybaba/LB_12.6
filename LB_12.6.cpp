#include <iostream>
#include <fstream>
#include <queue>
#include <cctype>

using namespace std;

// ������� ��� ��������� ����� ������� � ���������� �����
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

// ������� ��� ������������� �����
void printQueue(const queue<char>& q) {
    queue<char> temp = q;
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
    }
    cout << endl;
}

// ������� ��� ������ ���������� ������� �� ������ �� � ���� �����
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

    // ������� ������� � ����� �� ��������� �����
    createQueueFromFile(originalQueue, "input.txt");

    // ���������� ���� ��������� �����
    cout << "Original Queue:" << endl;
    printQueue(originalQueue);

    // �������� �������� ������� �� �������� �� � ����� englishCharsQueue,
    // � ����� ������� - � ����� otherCharsQueue
    selectEnglishChars(originalQueue, englishCharsQueue, otherCharsQueue);

    // ���������� ���� ����� ���������� �������
    cout << "English Characters Queue:" << endl;
    printQueue(englishCharsQueue);

    // ���������� ���� ����� ����� �������
    cout << "Other Characters Queue:" << endl;
    printQueue(otherCharsQueue);

    return 0;
}
