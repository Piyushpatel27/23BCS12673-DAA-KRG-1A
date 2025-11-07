#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to build LPS (Longest Prefix Suffix) array for pattern
void computeLPSArray(const string &pat, vector<int> &lps) {
    int m = pat.length();
    int len = 0; // length of previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to find all occurrences of pattern in text
void KMPSearch(const string &pat, const string &txt) {
    int m = pat.length();
    int n = txt.length();

    vector<int> lps(m);
    computeLPSArray(pat, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    bool found = false;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << (i - j) << endl;
            found = true;
            j = lps[j - 1]; // Continue searching for next occurrence
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found in the text." << endl;
}

int main() {
    string txt, pat;

    cout << "Enter the text string: ";
    getline(cin, txt);
    cout << "Enter the pattern string: ";
    getline(cin, pat);

    cout << "\nAll occurrences of pattern \"" << pat << "\" in text:\n";
    KMPSearch(pat, txt);

    return 0;
}
