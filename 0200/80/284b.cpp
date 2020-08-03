#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned fa = 0, fi = 0;
    for (const char c : s) {
        fa += (c == 'A');
        fi += (c == 'I');
    }

    answer(fi == 0 ? fa : fi == 1);
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

