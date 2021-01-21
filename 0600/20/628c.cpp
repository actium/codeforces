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

void solve(const std::string& s, size_t k)
{
    std::string t;
    for (const char c : s) {
        const size_t d1 = std::min<size_t>(c - 'a', k), d2 = std::min<size_t>('z' - c, k);
        if (d1 > d2) {
            t.push_back(c - d1);
            k -= d1;
        } else {
            t.push_back(c + d2);
            k -= d2;
        }
    }

    if (k == 0)
        return answer(t);

    no_answer();
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

