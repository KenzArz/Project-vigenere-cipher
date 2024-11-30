#include <iostream>

using namespace std;

string vigenere(const string& message, const string& key, int direction) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string final_message = "";
    int key_index = 0;
    int offset, index;

    for (char ch : message) {
        if (!isalpha(ch)) { 
            final_message += ch;
        } else {
            char lower_char = (ch);
            char key_char = key[key_index % key.length()];
            key_index++;

            for (int alpha = 0; alpha < alphabet.length(); alpha++) {
                if(alphabet[alpha] == (key_char)) {
                    offset = alpha;
                }
                if(alphabet[alpha] == lower_char) {
                    index = alpha;
                }
            }
            
            int new_index = (index + offset * direction + alphabet.size()) % alphabet.size();
            final_message += alphabet[new_index];
        }
    }
    return final_message;
}

string encrypt(const string& message, const string& key) {
    return vigenere(message, key, 1);
}

string decrypt(const string& message, const string& key) {
    return vigenere(message, key, -1);
}

void head() {
    cout << "\t\t=================================\n";
    cout << "\t\t\t  VIGENERE CIPHER\n";
    cout << "\t\t=================================\n";
}


int main() {
    string message, key, new_message;
    char repeat;
    int type;
    head();
    cout << "\t\t1. Enkripsi\n\t\t2. Dekripsi\n";
    cout << "\t\t=================================\n";
    cout << "\t\tSilahkan pilih menu: ";
    cin >> type;

    system("cls");
    head();
    
    switch (type)
    {
    case 1:
        cout << "Masukkan Pesan Untuk Dienkripsi: ";
        getline(cin >> ws, message);

        cout << "Masukkan Key Untuk Mengenkripsi: ";
        getline(cin, key);

        new_message = encrypt(message, key);

        system("cls");
        head();
        
        cout << "\nOriginal Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Encrypted Message: " << new_message << endl << endl;
        break;
    case 2: 
        cout << "Masukkan Pesan Untuk Didekripsi: ";
        getline(cin >> ws, message);

        cout << "Masukkan Key Untuk Mengdekripsi: ";
        getline(cin, key);

        new_message = decrypt(message, key);
        system("cls");
        head();
        
        cout << "\nEncrypted Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Decrypted Message: " << new_message << endl << endl;
        break;
    default:
        cout << "Menu yang anda pilih tidak tersedia\n";
        system("pause");
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        system("cls");
        head();
        break;
    }

    cout << "Apakah anda ingin melakukan enkripsi/dekripsi lagi (y/n)?: ";
    cin >> repeat;

    if(repeat == 'y' || repeat == 'Y') {
        system("cls");
        return main();
    }

    return 0;
}
