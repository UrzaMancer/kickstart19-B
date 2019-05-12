#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
#define TESTSETFILE "template.txt"

const bool debug = true;

class Stone {
    private:
    int secondsToEat;
    int initialEnergy;
    int energyLossRate;

    public:
    Stone (int, int, int);
    Stone (int, int, int, int);
    int getSeconds (void);
    int getEnergy (void);
    int getLossRate (void);
};

Stone::Stone (int S, int E, int L) {
    secondsToEat = S;
    initialEnergy = E;
    energyLossRate = L;
}

int Stone::getSeconds() {
    return secondsToEat;
}

int Stone::getEnergy() {
    return initialEnergy;
}

int Stone::getLossRate() {
    return energyLossRate;
}

Stone getNextStone(istream& inFile) {
    int S, E, L;
    inFile >> S >> E >> L;
    return Stone(S, E, L);
}

int runTestCase(istream& inFile) {
    int numberOfStones, maximumEnergy;
    int totalSeconds, totalEnergy = 0;
    
    vector<Stone> stoneCollection;

    inFile >> numberOfStones;
    stoneCollection.reserve(numberOfStones);

    for (int i = 0; i < numberOfStones; ++i) {
        stoneCollection.push_back(getNextStone(inFile));
        totalEnergy += stoneCollection.back().getEnergy();
        totalSeconds += stoneCollection.back().getSeconds();
    }
    
    for (Stone eStone : stoneCollection) {
        int //calculate loss value, sort by loss value. Investigate a data structure?
    }
    for (int i = 0; i < numberOfStones; ++i) {
        for (int j = 0; j < numberOfStones; ++j) {
            if (energyLossRate[j] == maxLossRate) {
                if (secondsToEat[j] < minSecondsToEat) {
                    minSecondsToEat = secondsToEat[j];
                    nextStoneToEat = j;
                }
            }
        }
        maximumEnergy += initialEnergy[nextStoneToEat] - (secondsPassed * energyLossRate[nextStoneToEat]);
        secondsToEat.erase(secondsToEat.begin()+nextStoneToEat);
        initialEnergy.erase(secondsToEat.begin()+nextStoneToEat);
        energyLossRate.erase(secondsToEat.begin()+nextStoneToEat);
        maxLossRate = energyLossRate[0];
        minSecondsToEat = 101;
    }
    inFile >> code;
    return;
}

void main() {
    int totalTestCases;
    int testCase = 0;
    ifstream testSetInput;
    testSetInput.open(TESTSETFILE);
    if (testSetInput.is_open()) {
        testSetInput >> totalTestCases;
    }
    else {
        cout << "Unable to open file " << TESTSETFILE << endl;
        return;
    }
    while(testCase <= totalTestCases) {
        cout << "Case #" << testCase << ": " << runTestCase(testSetInput) << endl;
        ++testCase;
    }
    testSetInput.close();
    return;
}