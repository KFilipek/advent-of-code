#include <iostream>
#include <regex>
#include <string>

using namespace std;

int find_first_digit(string &s) {
    regex re("[0-9]|one|two|three|four|five|six|seven|eight|nine|zero");
    smatch m;

    if (regex_search(s, m, re)) {
        if (m[0] == "one")
            return 1;
        else if (m[0] == "two")
            return 2;
        else if (m[0] == "three")
            return 3;
        else if (m[0] == "four")
            return 4;
        else if (m[0] == "five")
            return 5;
        else if (m[0] == "six")
            return 6;
        else if (m[0] == "seven")
            return 7;
        else if (m[0] == "eight")
            return 8;
        else if (m[0] == "nine")
            return 9;
        else if (m[0] == "zero")
            return 0;
        else {
            char c;
            c= m[0].str()[0];
            return atoi(&c);
        }
    }
    return 0;
}

int find_last_digit(string &s) {
    regex re("[0-9]|one|two|three|four|five|six|seven|eight|nine|zero");
    smatch m;
    vector<char> v;

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        v.insert(v.begin(), *it);
        string str(v.begin(), v.end());

        if (regex_search(str, m, re))
        {
            if (m[0] == "one")
                return 1;
            else if (m[0] == "two")
                return 2;
            else if (m[0] == "three")
                return 3;
            else if (m[0] == "four")
                return 4;
            else if (m[0] == "five")
                return 5;
            else if (m[0] == "six")
                return 6;
            else if (m[0] == "seven")
                return 7;
            else if (m[0] == "eight")
                return 8;
            else if (m[0] == "nine")
                return 9;
            else if (m[0] == "zero")
                return 0;
            else
            {
                char c;
                c = m[0].str()[0];
                return atoi(&c);
            }
        }
    }
    return 0;
}

int main() {
    vector<string> input;

    string line;
    int calibration_value = 0;
    while (getline(cin, line) && !line.empty()) {
        calibration_value += 10 * find_first_digit(line);
        calibration_value += find_last_digit(line);
        input.push_back(line);
    }
    cout << calibration_value << endl;
    return 0;
}
