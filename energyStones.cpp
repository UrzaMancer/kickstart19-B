#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
/*Problem

Duda the rock monster lives in the enchanted forest and has collected N energy stones for lunch. Since he has a small mouth, he eats energy stones one at a time. Some stones are tougher than others! The i-th stone takes him Si seconds to eat.

Duda eats energy stones to get energy. Different stones give him different amounts of energy. Furthermore, the stones lose energy over time. The i-th stone initially contains Ei units of energy and will lose Li units of energy each second. When Duda starts to eat a stone, he will receive all the energy the stone contains immediately (no matter how much time it takes to actually finish eating the stone). The stone's energy stops decreasing once it hits zero.

What is the largest amount of energy Duda could receive from eating his stones?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing the integer N, the number of energy stones Duda has. Then, there are N more lines, the i-th of which contains the three integers Si, Ei and Li, as described above.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum amount of energy Duda could receive from eating stones.

Limits

Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ N ≤ 100.
1 ≤ Si ≤ 100.
1 ≤ Ei ≤ 10^5.
0 ≤ Li ≤ 10^5.

Problem statement provided by https://codingcompetitions.withgoogle.com/kickstart/ */

using namespace std;
#define TESTSETFILE "template.txt"

const bool debug = true;

class Stone {
    private:
    int secondsToEat;
    int initialEnergy;
    int energyLossRate;
    int lossValue; //This is not given in the problem, but we define it as this stone's energyLossRate * (seconds of all other stones, AKA totalSeconds - this.secondsToEat)

    public:
    Stone (int, int, int);
    Stone (int, int, int, int);
    int getSeconds (void);
    int getEnergy (void);
    int getLossRate (void);
    int getLossValue (void);
    void setLossValue (int);
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

int Stone::getLossValue() {
    if (lossValue) {
        return lossValue;
    }
    else {
        return -1;
    }
}

void Stone::setLossValue(int inputLossVal) {
    lossValue = inputLossVal;
}

Stone getNextStone(istream& inFile) {
    int S, E, L;
    inFile >> S >> E >> L;
    return Stone(S, E, L);
}

vector<Stone> buildSortedStoneStack(Stone& stoneStack) {
    int minimumLossValue = 1000000000; //1 billion should be the upper boundary based on limits of 100 stones, 100 seconds per stone, and 10000 lossrate
    vector<Stone> sortedStack;
    for (Stone nextInPile : stoneStack) {
        if (nextInPile.getLossValue() < minimumLossValue) {
            sortedStack.push_back(nextInPile);
        }
        else if (nextInPile.getLossValue() == minimumLossValue) {

        }
    }
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
    
    for (Stone energyStone : stoneCollection) {
        int lossValue = energyStone.getLossRate() * (totalSeconds - energyStone.getSeconds());
        energyStone.setLossValue(lossValue);
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