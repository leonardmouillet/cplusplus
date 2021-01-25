#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// DES CONSTANTES

const double two_pi = 6.283185307179586476925286766559;
const double maximum = 32767; // volume sonore maximal ( = 2^15 - 1 car l'amplitude est codée par un entier signé sur deux octets)
double hz = 44100; // nombre d'échantillons par secondes 
double frequency = 261.626; // frequence de la note émise 
double d = 0.2; // durée d'un bip court (en secondes)


// UNE FONCTION D'ECRITURE

template <typename W>
void write(ofstream& f, W i, unsigned size = sizeof(W)){
    f.write(reinterpret_cast<char*>(&i), size);
}


// CONVERSION D'UN CODE MORSE EN FICHIER AUDIO

void morse_to_sound(const string &filename, string &morse_code){

    ofstream f;
    f.open(filename, ofstream::binary); // on crée et on ouvre le fichier wav

    if (f.is_open()){

        // ECRITURE DE L'ENTETE DU FICHIER WAV
    
        f << "RIFF----WAVEfmt "; // on laisse de la place ("----") pour insérer la taille du fichier plus tard     
        write( f, 16, 4); 
        write( f, 1, 2); 
        write( f, 1, 2); 
        write( f, 44100, 4); 
        write( f, 176400, 4); 
        write( f, 4, 2);  
        write( f, 16, 2); 
        size_t data_chunk_pos = f.tellp(); 
        f << "data----"; // on laisse de la place ( "----" ) pour insérer la taille des données ( = fichier - entête ) plus tard

        // ECRITURE DES DONNEES    
    
        for (uint i = 0; i < morse_code.length(); i++) { // on parcourt le code morse
    
            if(morse_code[i] == '.'){

                int N1 = hz * d; // un note pendant d secondes, donc N1 échantillons à remplir
                for (int n = 0 ; n < N1; n++){ // on remplit les échantillons un par un
                    double mod = sin ( (two_pi * (n+1) * frequency) / hz ); // on module l'amplitude maximale pour créer une note
                    write( f, (int)(maximum  * mod), 2 );
                }

                if (i<morse_code.length() - 1){ // un caractère (un son) est automatiquement suivi d'une pause, sauf si c'est le dernier caractère

                    int N2 = hz * d; // une pause pendant d secondes, soit N2 échantillons à remplir
                    for (int n = 0; n < N2 ; n++){ // on remplit les échantillons un par aun, avec des 0
                    write( f, 0, 2 );
                    }
                }
            }

            if(morse_code[i] == '-') {   
            
                int N1 = hz * 3 * d;
                for (int n = 0; n < N1 ; n++){
                    double mod = sin ( (two_pi * (n+1) * frequency) / hz );
                    write( f, (int)(maximum * mod), 2 );
                }

                if (i<morse_code.length() - 1){
                    int N2 = hz * d;
                    for (int n = 0; n < N2 ; n++){
                    write( f, 0, 2 );
                    }
                }
            }
    
            if (morse_code[i] == ' ') {

                int N2 = hz * d;
                for (int n = 0; n < N2; n++){
                    write( f, 0, 2 );
                }
            }
        }

        // COMPLETION DE L'EN TETE AVEC LA TAILLE DES DONNEES

        size_t file_length = f.tellp();
        f.seekp( data_chunk_pos + 4 );
        write( f, file_length - data_chunk_pos + 8 );
        f.seekp( 0 + 4 );
        write( f, file_length - 8, 4 );
        f.close();

    }
}

// CONVERSION D'UN FICHIER AUDIO EN CODE MORSE

string sound_to_morse(const string &filename){
    
    ifstream f ;
    f.open(filename, ios::binary);

    // On va parcourir deux fois le fichier : 
        // la première fois pour déterminer le nombre de "sons" et "silences" dans le fichier audio
        // la seconde fois pour remplir un tableau avec la taille de ces "sons" et "silences"
    // On construit ensuite le code morse à partir du tableau ainsi formé

    if (f.is_open()){
        
        f.ignore(40);
        uint32_t size_file ;
        f.read(reinterpret_cast<char *>(&size_file), sizeof (size_file)); // on récupère ici la taille du fichier

        // PREMIERE LECTURE DU FICHIER
        
        int size_tab = 0; // la première lecture nous permet de déterminer la taille du tableau à créer, ici initalisée à 0
        uint32_t s ; // on construit une variable pour récupérer les valeurs des échantillons
        bool loop = true;
        
        while(f.tellg() < size_file){

            size_tab = size_tab + 1;

            while (loop && f.tellg() < size_file){ // on parcourt les échantillons jusqu'à atteindre un silence
                f.read(reinterpret_cast<char *>(&s), sizeof (s));
                if (s == 0 && f.tellg() < size_file){
                    f.read(reinterpret_cast<char *>(&s), sizeof (s));
                    if (s == 0 && f.tellg() < size_file){
                        loop = false; // deux "0" d'affilé signifient qu'on a atteint un silence : on sort de la boucle
                    }
                }
            }

            loop = true ;

            while ( s == 0 && f.tellg() < size_file ){ // on parcourt les échantillons jusqu'à atteindre un nouveau son
                f.read(reinterpret_cast<char *>(&s), sizeof (s));
            }
        }

        // DEUXIEME LECTURE DU FICHIER

        int sound[size_tab]; // on va stocker ici la durée (en nombre d'échantillons) des sons
        int silence[size_tab]; // on va stocker ici la durée (en nombre d'échantillons) des silences
        int k = 0 ; // on initialise un compteur d'échantillons
        f.seekg(40);

        for(int i = 0; f.tellg() < size_file; i++){

            while (loop && f.tellg() < size_file){ // on parcourt un son
                f.read(reinterpret_cast<char *>(&s), sizeof (s));
                
                if (s == 0 && f.tellg() < size_file){
                    f.read(reinterpret_cast<char *>(&s), sizeof (s));
                    if (s == 0 && f.tellg() < size_file){
                        loop = false; // dans ce cas, on a atteint un silence donc on sort de la boucle et on compte les "0" restants
                    }
                    else {
                        k = k + 2; // dans ce cas, on est toujours dans un son et on a parcouru deux échantillons depuis l'entrée dans la boucle
                    }
                }
                else { 
                    k = k + 1 ; // dans ce cas, on est toujours dans un son et on a parcouru un échantillon depuis l'entrée dans la boucle
                }
            }

            sound[i] = k;
            loop = true ;
            k = 2;
            
            if (f.tellg() < size_file - 1){ // on parcourt le silence suivant, sauf si on a atteint la fin du fichier

                while ( s == 0 && f.tellg() < size_file){
                    f.read(reinterpret_cast<char *>(&s), sizeof (s));
                    k = k + 1;
                }

                silence[i] = k ;
            }

            else{ // si le fichier s'achève sur un son, on prend 0 comme taille du silence correspondant 
                silence[i]=0;
            }

            k = 0 ;
        }

        // RECONSTITUTION DU CODE MORSE

        std::string morse_code ="";
        
        /*std::cout<<"Silence 1 : "<<0.2*hz<<std::endl;
        std::cout<<"Silence 3 : "<<0.2*2*hz<<std::endl;
        std::cout<<"Silence 3 : "<<0.2*3*hz<<std::endl;
        std::cout<<" "<<std::endl;
        for (int i = 0; i < size_tab; i++){
            std::cout<<"son numéro "<<i+1<<" : "<<sound[i]<<std::endl;
            std::cout<<"silence numéro "<<i+1<<" : "<<silence[i]<<std::endl;
        }*/
    
        for( int i =0; i < size_tab; i++){ // on parcourt les tableaux créés précédemment

            int N = hz * d;
                    
            if(sound[i] <= (int)1.10*(3/2)*N && sound[i]>= (int)0.9*(3/2)*N){ // on distingue les sons longs ("-") des sons courts (".")
                morse_code.push_back('.');
            }
            else{
                morse_code.push_back('-');
            }
            
            if (silence[i]==0){} // on distingue les silences courts (entre les caractères - et .), intermédiaires (entre les lettres), longs (entre les mots) ou inexistants (de longeur 0)

            else if (silence[i]<= 1.1*N/2 && silence[i]>=0.9*N/2){}

            else if (silence[i]<= 1.1*N && silence[i]>=0.9*N){
                morse_code.push_back(' ');
            }
            else {
                morse_code.push_back(' ');
                morse_code.push_back(' ');
            }
        
        }   
        
        return morse_code;
    }

    else { 
        throw ("erreur fichier");
    }
}