// Tutorial:https://youtu.be/sMARZCTPyNI?si=c6-noxEbWunp3K0d
// or geekforgeeks.org

#include <bits/stdc++.h>
using namespace std;

vector<int> constructLps(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    int i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }

        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string pattern, string txt)
{
    vector<int> res;
    vector<int> lps = constructLps(pattern);

    int i = 0;
    int j = 0;

    while (i < txt.length())
    {

        if (txt[i] == pattern[j])
        {
            i++;
            j++;

            if (j == pattern.length())
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }

        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main()
{
    string txt = "aabcdaabdef", pattern = "aab";

    vector<int> res = kmp(pattern, txt);
    cout << "Match Found at index: ";
    for (auto pr : res)
        cout << pr << " ";

    return 0;
}