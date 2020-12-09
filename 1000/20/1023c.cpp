#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::string t;
    for (size_t i = 0, c = 0; i < n && t.length() < k; ++i) {
        if (s[i] == '(' && c < k/2)
            t.push_back('('), ++c;

        if (s[i] == ')')
            t.push_back(')');
    }

    answer(t);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

