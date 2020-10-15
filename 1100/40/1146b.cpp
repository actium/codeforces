#include <iostream>
#include <string>

void no_answer()
{
    std::cout << ":(" << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length();

    std::string p;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] != 'a')
            p.push_back(t[i]);
    }

    if (p.length() % 2 == 0) {
        const size_t k = p.length() / 2;

        const std::string s = t.substr(0, n - k);
        if (s + p.substr(0, k) == t)
            return answer(s);
    }

    no_answer();
}

int main()
{
    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

