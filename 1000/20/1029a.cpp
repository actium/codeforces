#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t, unsigned k)
{
    std::string s;
    for (size_t i = 0; k > 0; --k) {
        do {
            i = s.find(t[0], i+1);
        } while (i != std::string::npos && s.substr(i) != t.substr(0, s.length() - i));

        if (i == std::string::npos)
            i = s.length();

        s += t.substr(s.length() - i);
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string t;
    std::cin >> t;

    solve(t, k);

    return 0;
}

