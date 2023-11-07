
#include <iostream>
#include <string>
using namespace std;

//encrypt a message
string encrypt(string message, int key) {
    string encryptedMessage = "";
    for (char c : message) {
        if (isdigit(c)) {
            int num = c - '0';
            num = (num + key) % 10;
            encryptedMessage += to_string(num);
        }
        else if (islower(c)) {
            char encryptedChar = ((c - 'a' + key) % 26) + 'a';
            encryptedMessage += encryptedChar;
        }
        else if (isupper(c)) {
            char encryptedChar = ((c - 'A' + key) % 26) + 'A';
            encryptedMessage += encryptedChar;
        }
        else if (c == ' ') {
            encryptedMessage += ' ';
        }
    }
    return encryptedMessage;
}

//decrypt a message
string decrypt(string message, int key) {
    string decryptedMessage = "";
    for (char c : message) {
        if (isdigit(c)) {
            int num = c - '0';
            num = (num - key + 10) % 10;
            decryptedMessage += to_string(num);
        }
        else if (islower(c)) {
            char decryptedChar = ((c - 'a' - key + 26) % 26) + 'a';
            decryptedMessage += decryptedChar;
        }
        else if (isupper(c)) {
            char decryptedChar = ((c - 'A' - key + 26) % 26) + 'A';
            decryptedMessage += decryptedChar;
        }
        else if (c == ' ') {
            decryptedMessage += ' ';
        }
    }
    return decryptedMessage;
}

int main() {
    char choice;
    int key;

    cout << "Welcome to Cryptographic Techniques Program" << endl;

    do {
        cout << "Please enter your selection:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cin >> choice;

        if (choice == '1' || choice == '2') {
            cout << "Please enter the key K (cipher key): ";
            cin >> key;

            cin.ignore(); // Consume the newline character

            string inputMessage, outputMessage;

            cout << "Please enter the message: ";
            getline(cin, inputMessage);

            if (choice == '1') {
                outputMessage = encrypt(inputMessage, key);
                cout << "Encrypted message: " << outputMessage << endl;
            }
            else if (choice == '2') {
                outputMessage = decrypt(inputMessage, key);
                cout << "Decrypted message: " << outputMessage << endl;
            }
        }
        else {
            cout << "Invalid choice. Please enter '1' for Encrypt or '2' for Decrypt." << endl;
        }

        cout << "Do you want to continue (C) or exit (E)? ";
        cin >> choice;
    } while (choice == 'C' || choice == 'c');

    return 0;
}
