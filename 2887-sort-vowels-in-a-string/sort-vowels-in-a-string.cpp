class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Collect vowels
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Sort vowels
        sort(vowels.begin(), vowels.end());

        string result;
        int vowelIndex = 0;

        // Reconstruct string with sorted vowels
        for (char c : s) {
            if (isVowel(c)) {
                result.push_back(vowels[vowelIndex++]);
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};
