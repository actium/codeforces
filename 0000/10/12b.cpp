#include <algorithm>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "WRONG_ANSWER", "OK" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& n, const std::string& m)
{
    const size_t k = n.length();

    std::string t = n;
    std::sort(t.begin(), t.end());

    for (size_t i = 0; i < k; ++i) {
        if (t[i] != '0') {
            std::swap(t[i], t.front());
            break;
        }
    }

    answer(t == m);
}

int main()
{
    std::string n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

