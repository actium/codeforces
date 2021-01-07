#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();
    if (n < 26)
        return no_answer();

    unsigned f[26] = {}, k = 0;
    for (size_t i = 0; i < n; ++i) {
        k += (s[i] == '?' || f[s[i] - 'A']++ == 0 ? 1 : -1);

        if (i >= 26)
            k += (s[i-26] == '?' || --f[s[i-26] - 'A'] == 0 ? -1 : 1);

        if (k == 26) {
            std::string t;
            for (size_t j = 0; j < 26; ++j) {
                if (f[j] == 0)
                    t.push_back('A' + j);
            }

            for ( ; !t.empty(); --i) {
                if (s[i] == '?') {
                    s[i] = t.back();
                    t.pop_back();
                }
            }

            for (char& c : s) {
                if (c == '?')
                    c = 'A';
            }

            return answer(s);
        }
    }

    no_answer();
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

