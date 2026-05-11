class Solution {
public:
    // copied from gemini but solve after exam
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build the multiplier (handles cases like "12[a]")
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                // Push the current multiplier and the string built so far
                countStack.push(k);
                stringStack.push(currentString);
                // Reset for the new context inside the brackets
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                // Pop the multiplier and the previous string context
                int repeatTimes = countStack.top();
                countStack.pop();
                string lastString = stringStack.top();
                stringStack.pop();

                // Repeat currentString k times and attach to lastString
                for (int i = 0; i < repeatTimes; i++) {
                    lastString += currentString;
                }
                currentString = lastString;
            } else {
                // It's a normal character, just append
                currentString += ch;
            }
        }

        return currentString;
    }
};