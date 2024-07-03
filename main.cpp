#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <map>

//Armin Hamrah - Markov Chain

using namespace std;

map<string, vector<char>> loadFile(ifstream &f, int level) {
    char ch;
    string seed;
    map<string, vector<char>> result;
    for (int i=0; i<level; i++) {
        f >> noskipws >> ch;
        seed += toupper(ch);
    }
    while (f>>noskipws>>ch) {
        ch = toupper(ch);
        result[seed].push_back(ch); //add each new ch into vector of characters
        seed = seed.substr(1)+ch;
    }
    f.close();
    cout << result.size() << endl;
    return result;
}

string writeRandom(map<string,  vector<char>> &markov) {
    cout << "HERE" << endl;
    string seed = markov.begin()->first;
    string result = seed;
    int sentenceNum = 0;
    while (sentenceNum<25) {
        vector<char> letters = markov[seed];
        char ch = letters[rand()%letters.size()];
        if (ch=='.' || ch=='?' || ch=='!')
            sentenceNum++;
        result += ch;
        cout << "     " << ch << endl;
        seed = seed.substr(1)+ch;
    }
    return result;
}

int main() {
    srand(time(0));
    cout << "Hello, Markov Chain!" << endl;
    cout << "Enter level (1-10): ";
    int level;
    cin >> level;
    cout << "Enter file name: ";
    string filename;
    cin >> filename;
    ifstream f(filename);
    map<string, vector<char>> markovMap = loadFile(f, level);
    cout << writeRandom(markovMap) << endl;
    return 0;
}