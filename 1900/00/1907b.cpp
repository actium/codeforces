#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> t[2];
    for (size_t i = 0; i < n; ++i) {
        const size_t j = isupper(s[i]) ? 1 : 0;

        if (toupper(s[i]) == 'B') {
            if (!t[j].empty()) {
                s[t[j].back()] = ' ';
                t[j].pop_back();
            }
            s[i] = ' ';
        } else {
            t[j].push_back(i);
        }
    }

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != ' ')
            s[k++] = s[i];
    }
    s.resize(k);

    answer(s);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
