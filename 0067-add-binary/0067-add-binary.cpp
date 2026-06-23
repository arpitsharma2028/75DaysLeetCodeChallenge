class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Loop as long as there are characters to process or a carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            // Add the digit from string a if available
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }

            // Add the digit from string b if available
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // The new bit to add to our result is sum % 2
            result += to_string(sum % 2);

            // Calculate the new carry
            carry = sum / 2;
        }

        // Since we built the string from right to left, reverse it to get the final answer
        reverse(result.begin(), result.end());
        return result;
    }
};