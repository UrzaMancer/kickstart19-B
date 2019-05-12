#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int numberOfStones;
    vector<int> secondsToEat, initialEnergy, energyLossRate;
    secondsToEat.reserve(numberOfStones);
    initialEnergy.reserve(numberOfStones);
    energyLossRate.reserve(numberOfStones);
    int totalTestCases;
    cin >> totalTestCases;
    int maxLossRate = -1;
    int nextStoneToEat = -1;
    int minSecondsToEat = 101;
    for (int testCaseNumber = 1; testCaseNumber <= totalTestCases; ++testCaseNumber) {
        int maximumEnergy = 0;
        cin >> numberOfStones;
        for (int stone = 0; stone < numberOfStones; ++numberOfStones) {
            cin >> secondsToEat[stone] >> initialEnergy[stone] >> energyLossRate[stone];
            if (energyLossRate[stone] > maxLossRate) {
                maxLossRate = energyLossRate[stone];
                minSecondsToEat = secondsToEat[stone];
            }
        }
        int secondsPassed = 0;
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
        cout << "Case #" << testCaseNumber << ": " << maximumEnergy << endl;
    }
    return 0;
}