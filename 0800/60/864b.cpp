#include <iostream>
#include <set>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t k = 0;

    std::set<char> v;
    for (const char c : s) {
        if (islower(c))
            v.insert(c);
        else
            v.clear();

        k = std::max(k, v.size());
    }

    answer(k);
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

