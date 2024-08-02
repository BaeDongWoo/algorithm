#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void run(vector<char> splitNumber, string combiNum, vector<bool> &visited);
bool isPrime1(int n);
set<int> setNumber;

int solution(string numbers) {
    int answer = 0;
    vector<char> splitNumber;
    string combiNum = "";
    vector<bool> visited(numbers.size(), false);

    for (char num : numbers) {
        splitNumber.push_back(num);
    }

    run(splitNumber, combiNum, visited);

    for (int n : setNumber) {
        if (n > 1 && isPrime1(n)) {
            answer++;
        }
    }

    return answer;
}

void run(vector<char> splitNumber, string combiNum, vector<bool> &visited) {
    for (int i = 0; i < splitNumber.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            string newCombiNum = combiNum + splitNumber[i];
            int num = stoi(newCombiNum);
            setNumber.insert(num);
            run(splitNumber, newCombiNum, visited);
            visited[i] = false;
        }
    }
}

bool isPrime1(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
