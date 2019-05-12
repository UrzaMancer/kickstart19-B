#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<char> printVec) {
    for(int i=0;i<printVec.size(); ++i) {
        cout << printVec[i] << " ";
    }
    cout << endl;
}

bool canAnnaAnswerYes (vector<char> testPhrase) {
    const int phraseSize = testPhrase.size();
    if (phraseSize == 1) {
        //cout << "  DEBUG:  only one character, answer is yes" << endl;
        return true;
    }
    short unmatchedChars = 0;
    for (int j=(phraseSize - 1); j>=0; --j) {
        if(testPhrase.size() <= 1) {
            break;
        }
        char c = testPhrase.back();
        testPhrase.pop_back();
        for (int i=0; i<testPhrase.size(); ++i) {
            if (testPhrase[i] == c) {
                testPhrase.erase(testPhrase.begin()+i);
                //cout << "  DEBUG:  '" << c << "' matched at position " << i << endl;
                if(!testPhrase.empty()) {
                    //cout << "  DEBUG:  New vector: ";
                    //printVector(testPhrase);
                }
                break;
            }
            if (i >= testPhrase.size() - 1) {
                unmatchedChars++;
                //cout << "  DEBUG: '" << c << "' unmatched. unmatchedChars = " << unmatchedChars << endl;
            }
        }
        if (unmatchedChars && (phraseSize % 2 == 0)) {
            //cout << "  DEBUG:  " << unmatchedChars << " unmatchedChars with even length string. Answer is no." << endl;
            return false;
        }
        if (unmatchedChars >= 2) {
            //cout << "  DEBUG:  " << unmatchedChars << " unmatchedChars. Answer is no." << endl;
            return false;
        }
    }
    if (testPhrase.size() > 1) {
        //cout << "  DEBUG: Returning from canAnnaAnswerYes(), new Vector: ";
        printVector(testPhrase);
        return false;
    }
    //cout << "  DEBUG: Returning from canAnnaAnswerYes(), exited all loops & tests. Answer is yes." << endl;
    return true;
}

int main() {
    int totalTestCases, numQuestionsAnsweredYes;
    cin >> totalTestCases;
    int numberOfBlocks, totalQuestions = 0;
    string blockString;
    for(int testCaseNumber=0; testCaseNumber<totalTestCases; ++testCaseNumber) {
        numQuestionsAnsweredYes = 0;
        cin >> numberOfBlocks >> totalQuestions;
        cin >> blockString;
        for(int j=0; j<totalQuestions; ++j) {
            int leftLimit, rightLimit;
            vector<char> subPhrase;
            cin >> leftLimit >> rightLimit;
            subPhrase.assign(blockString.begin()+leftLimit-1,blockString.begin()+rightLimit);
            //cout << "  DEBUG: ";
            //printVector(subPhrase);
            if(canAnnaAnswerYes(subPhrase)) {
                ++numQuestionsAnsweredYes;
                //cout << "  DEBUG: yes ; numQuestionsAnsweredYes = " << numQuestionsAnsweredYes << endl;
            }
        }
    cout << "Case #" << (testCaseNumber + 1) << ": " << numQuestionsAnsweredYes << endl;
    }
    return(0);
}
