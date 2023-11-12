#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
void encryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE* inFile = fopen(inputFile, "r");
    FILE* outFile = fopen(outputFile, "w");

    if (inFile == NULL || outFile == NULL) {
        cout << "Error opening files." << "\n";
        return;
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        if (iswalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = ((ch - base + key + 26) % 26) + base;
        }
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}
int main()
{
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    int key = 3;

    encryptFile(inputFile, outputFile, key);

    cout << "Encryption complete." << "\n";
}