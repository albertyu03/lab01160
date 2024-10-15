#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*** Enums and Print Functions for Terminals and Non-Terminals  **********************/

#define MAX_SYMBOL_NAME_SIZE 25

// All of the terminals in the language
typedef enum {
    T_eof = 0,  // 0: end of file
    T_num,      // 1: numbers
    T_plus,     // 2: +
    T_minus,    // 3: - 
    T_times,    // 4: *
    T_period,   // 5: .
    T_bar,      // 6: | 
    T_openparen,    // 7: (
    T_closeparen    // 8: )
} token_type;

int main() {
    int cur_int = getchar();  // Read input as int to capture EOF
    map<char, token_type> tokentl = {
        {'0', T_num}, {'1', T_num}, {'2', T_num}, {'3', T_num},
        {'4', T_num}, {'5', T_num}, {'6', T_num}, {'7', T_num}, 
        {'8', T_num}, {'9', T_num}, {'+', T_plus}, {'-', T_minus}, 
        {'*', T_times}, {'.', T_period}, {'|', T_bar}, {'(', T_openparen}, 
        {')', T_closeparen}
    };
    
    vector<token_type> tokens;
    bool was_int = false;

    // Loop while not EOF
    while (cur_int != EOF) {
        if (cur_int != ' ' && cur_int != '\n') {  // Only process non-whitespace characters
            // Only cast after checking cur_int is not EOF
            char cur_char = static_cast<char>(cur_int);  // Now safe to cast
            
            cout << "current char: " << cur_char << endl;  // Print the current character

            if (tokentl.count(cur_char) > 0) {  // If character exists in the map
                if (tokentl[cur_char] == T_num) {
                    if (!was_int) {  // Only add number token if it hasn't already
                        was_int = true;
                        tokens.push_back(tokentl[cur_char]);
                    }
                } else {  // If not a number, add token
                    was_int = false;
                    tokens.push_back(tokentl[cur_char]);
                }
            } else {
                // Handle unexpected characters
                cout << "ERROR! Unexpected character: " << cur_char << endl;
            }
        }
        // Output all the tokens
        for (unsigned int i = 0; i < tokens.size(); i++) {
            cout << tokens[i] << endl;
        }
        cout << endl;

        // Read the next character
        cur_int = getchar();
    }

    // Add end of file token after escaping loop
    cout << "ESCAPED LOOP" << endl;
    tokens.push_back(T_eof);

    // Output all the tokens
    for (unsigned int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
    }

    return 0;
}
