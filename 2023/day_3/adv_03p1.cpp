#include <iostream>
#include <regex>
#include <string>
#include <cctype>

using namespace std;

// Probably better is to use a mask matrix
bool is_adjacent_to_symbol(vector<string> input, size_t x, size_t y) {
    if (input[y][x] == '.') {
        return false;
    }
    if (x > 0 && input[y][x - 1] != '.' && !isdigit(input[y][x - 1])) {
        return true;
    }
    if (x < input[y].size() - 1 && input[y][x + 1] != '.' && !isdigit(input[y][x + 1])) {
        return true;
    }
    if (y > 0 && input[y - 1][x] != '.' && !isdigit(input[y - 1][x])) {
        return true;
    }
    if (y < input.size() - 1 && input[y + 1][x] != '.' && !isdigit(input[y + 1][x])) {
        return true;
    }
    if (x > 0 && y > 0 && input[y - 1][x - 1] != '.' && !isdigit(input[y - 1][x - 1])) {
        return true;
    }
    if (x < input[y].size() - 1 && y > 0 && input[y - 1][x + 1] != '.' && !isdigit(input[y - 1][x + 1])) {
        return true;
    }
    if (x > 0 && y < input.size() - 1 && input[y + 1][x - 1] != '.' && !isdigit(input[y + 1][x - 1])) {
        return true;
    }
    if (x < input[y].size() - 1 && y < input.size() - 1 && input[y + 1][x + 1] != '.' && !isdigit(input[y + 1][x + 1])) {
        return true;
    }
    return false;
}

// Check from xy to the right that any digit is an adjacent symbol
bool is_adjacent_to_symbol_right(vector<string> input, size_t x, size_t y) {
    for (size_t i = x; i < input[y].size(); i++) {
        if (!isdigit(input[y][i])) {
            break;
        }
        if (is_adjacent_to_symbol(input, i, y)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> input;

    string line;
    int calibration_value = 0;
    while (getline(cin, line) && !line.empty()) {
        input.push_back(line);
    }

    for (size_t y = 0; y < input.size(); y++) {
        for (size_t x = 0; x < input[y].size(); x++) {
            if (!isdigit(input[y][x])) {
                continue;
            } else {
                size_t advance = 0;
                string temp = string(input[y].begin() + x, input[y].end());
                int parsed_value = stoi(temp, &advance);
                if (is_adjacent_to_symbol_right(input, x, y)) {
                    calibration_value += parsed_value;
                }
                x += advance - 1; // Move after the number
            }
        }
    }
    cout << "Calibration value: " << calibration_value << endl;
    return 0;
}
