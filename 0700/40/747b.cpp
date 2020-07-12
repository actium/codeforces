#include <iostream>
#include <string>
#include <unordered_map>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    answer("===");
}

void solve(std::string& s)
{
    constexpr char nucleotids[4] = { 'A', 'C', 'G', 'T' };

    const size_t n = s.length();
    if (n % 4 != 0)
        return no_answer();

    const unsigned k = n / 4;

    std::unordered_map<char, unsigned> f;
    for (const char c : s) {
        if (++f[c] > k && c != '?')
            return no_answer();
    }

    size_t i = 0;
    for (char& c : s) {
        if (c != '?')
            continue;

        c = nucleotids[i];
        while (f[c] == k)
            c = nucleotids[++i];

        ++f[c];
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

