#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] > s[i])
            return answer(i-1, i);
    }

    no_answer();
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

