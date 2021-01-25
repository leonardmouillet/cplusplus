#include "test.h"
#include "morse.h"
#include "wav.h"

using namespace std;

int main (int argc, char* argv []) {
    if (argc > 1 && argv[1][0] == '0'){ // l'argument "0" permet d'executer les fonctions de test 
        test_morse();
        test_wav();
    }
    else if (argc > 1 && argv[1][0]== '1'){ // l'argument "1" permet de générer un fichier audio (en morse) à partir d'une phrase
        cout<<"Entrez la phrase à encoder"<<endl;
        string ascii_string;
        getline(cin, ascii_string);
        cout<<"Entrez le nom du fichier audio (.wav) à créer"<<endl;
        string filename;
        getline(cin, filename);
        string morse_code = encode(ascii_string);
        cout <<"Voici le code morse correspondant : " <<endl;
        cout <<morse_code<<endl;
        morse_to_sound(filename, morse_code);
    }
    else if (argc > 1 && argv[1][0]=='2'){ // l'argument "2" permet de générer une phrase à partir de l'adresse d'un fichier audio (en morse)
        cout<< "Entrez le nom du fichier audio (.wav) à décoder" << endl;
        string filename;
        cin >> filename;
        string morse_code = sound_to_morse(filename);
        cout<<"Voici le code morse correspondant :"<<endl;
        cout << morse_code <<endl;
        string ascii_string = decode (morse_code);
        cout << "Voici la phrase décodée :" <<endl;
        cout << ascii_string << endl;
    }
    return 0;
}
