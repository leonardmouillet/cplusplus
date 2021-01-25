#include<map>
#include<string>
#include <cstdlib>
#include <iostream>

// ENCODAGE D'UNE CHAINE DE CARACTERES ASCII EN CODE MORSE

std::string encode(std::string  ascii_string){

    std::map<int, std::string> map1 ; // on initialise un dictionnaire de l'ascii vers le morse
    
    map1[65]=".-";         
    map1[66]="-...";
    map1[67]="-.-.";
    map1[68]="-..";
    map1[69]=".";
    map1[70]="..-.";
    map1[71]="--.";
    map1[72]="....";
    map1[73]="..";
    map1[74]=".---";
    map1[75]="-.-";
    map1[76]=".-..";
    map1[77]="--";
    map1[78]="-.";
    map1[79]="---";
    map1[80]=".--.";
    map1[81]="--.-";
    map1[82]=".-.";
    map1[83]="...";
    map1[84]="-";
    map1[85]="..-";
    map1[86]="...-";
    map1[87]=".--";
    map1[88]="-..-";
    map1[89]="-.--";
    map1[90]="--..";
    map1[97]=".-";          
    map1[98]="-...";
    map1[99]="-.-.";
    map1[100]="-..";
    map1[101]=".";
    map1[102]="..-.";
    map1[103]="--.";
    map1[104]="....";
    map1[105]="..";
    map1[106]=".---";
    map1[107]="-.-";
    map1[108]=".-..";
    map1[109]="--";
    map1[110]="-.";
    map1[111]="---";
    map1[112]=".--.";
    map1[113]="--.-";
    map1[114]=".-.";
    map1[115]="...";
    map1[116]="-";
    map1[117]="..-";
    map1[118]="...-";
    map1[119]=".--";
    map1[120]="-..-";
    map1[121]="-.--";
    map1[122]="--..";
    map1[32]=""; 

    std::string result = ""; // on initialise le résulat sous forme de chaine

    for(uint i=0; i< ascii_string.length() ; i++){ // on parcours les caractères ascii de la phrase

        char ascii_char = ascii_string[i];
        int ascii = int(ascii_char);
        std::string morse_code = map1[ascii];  // on convertit les caractères parcourus en code morse

        for(uint j=0; j < morse_code.length() ; j++){  // on ajoute le code morse du caractère au résultat
            result.push_back(morse_code[j]);
        }

        result.push_back(' ');   // on ajoute un espace entre chaque caractère de morse
    }
    result.pop_back(); // on retire le dernier espace ajouté

    return result;
}


// DECODAGE D'UN CODE MORSE EN CHAINE DE CARACTERES ASCII

std::string decode(std::string morse_string){     

    std::map<std::string, int> map2 ; // on initialise un dictionaire du morse vers l'ascii
    
    map2[".-"] = 97;
    map2["-..."] = 98;
    map2["-.-."] = 99;
    map2["-.."] = 100;
    map2["."] = 101;
    map2["..-."] = 102;
    map2["--."] = 103;
    map2["...."] = 104;
    map2[".."] = 105;
    map2[".---"] = 106;
    map2["-.-"] = 107;
    map2[".-.."] = 108;
    map2["--"] = 109;
    map2["-."] = 110;
    map2["---"] = 111;
    map2[".--."] = 112;
    map2["--.-"] = 113;
    map2[".-."] = 114;
    map2["..."] = 115;
    map2["-"] = 116;
    map2["..-"] = 117;
    map2["...-"] = 118;
    map2[".--"] = 119;
    map2["-..-"] = 120;
    map2["-.--"] = 121;
    map2["--.."] = 122;
    map2[" "] = 32;

    std::string result = ""; // on initialise le résultat sous forme de chaine

    uint k = 0; 

    while (k < morse_string.length()) {  // on parcourt le code morse

        std::string morse_char = ""; // on identifie les différents caractères morses individuellement
        while(k < morse_string.length() && morse_string[k] != ' '){ // en repérant les espaces entre caractères morses   
            morse_char.push_back(morse_string[k]);
            k = k + 1;
        }
        
        char lettre = char(map2[morse_char]); // on transforme le caractère morse identifié en caractère ascii
        result.push_back(lettre);   // on ajoute la lettre au résultat final
          
        morse_char = "";

        if (k < morse_string.length() && ( morse_string[k+1]==' ' && morse_string[k]==' ')) {
        // on regarde si on se trouve à la fin d'un mot (dernier caractère ou bien caractère suivi de deux espaces) 
            result.push_back(' ');
            k = k + 1;
        } 
        k = k + 1;
    }
    
    return result;
}