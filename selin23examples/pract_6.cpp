#include <bits/stdc++.h>

//Зашифрувати уведений з клавіатури текст відповідно кодової таблиці, яка
//задана як рядковий літерал із послідовності символів, кожний з яких
//відповідає певній букві алфавіту. Вхідний текст складено тільки із малих
//букв латинського алфавіту і десяти ци

std::string RandomString(int ch);
const int ch_MAX = 36;



int main(int argc, char const *argv[])
{
    srand ( time(NULL) ); //to prevent same coding
    int cypherStrength = 6; // custom key str
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z',
                          '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::string text;
    getline(std::cin, text);
    //std::string a = RandomString(4);

    std::vector <std::string> alphaCoded = {};
    for (int i = 0; i < ch_MAX; i++){
        alphaCoded.push_back(RandomString(cypherStrength));
    }
    //search element in alphabet and get the code
    std::string cypher = "";
    for (int i=0; i < text.size(); i++){
        for (int j = 0; j < ch_MAX; j++){
            if (alpha[j] == text[i]){
                cypher+= alphaCoded[j] + " ";
                break;
            }
        }
    }

    for (int i = 0; i < alphaCoded.size(); i++){
        std::cout << alpha[i] << "\t" <<alphaCoded[i] << "\n";
    }
    std::cout << "\n";
    std::cout << cypher << std::endl;

    return 0;
}

std::string RandomString(int ch)
{
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z',
                          '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}


