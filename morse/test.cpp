#include "morse.h"
#include "wav.h"
#include<iostream>
#include <cstdlib>

using namespace std;

void test_morse(){
    string ascii_string = "test des fonctions encode et decode ceci est un test je repete ceci est un test";
    string morse_code = encode(ascii_string);
    string result = decode(morse_code);
    cout<<(result==ascii_string)<<endl;
}

void test_wav(){
    string ascii_string = "test des fonctions morse to sound et sound to morse ceci est un test avec un espace a la fin ";
    string morse_code = encode(ascii_string);
    string filename = "test.wav";
    morse_to_sound (filename, morse_code);
    string result = sound_to_morse(filename);
    std::cout<<(result == morse_code)<< std::endl;
}
