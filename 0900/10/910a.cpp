#include <iostream>
#include <string>

size_t jump(const std::string& s, size_t x, size_t d)
{
    for ( ; d > 0; --d) {
        if (s[x + d] == '1')
            return x + d;
    }
    return 0;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, size_t d)
{
    const size_t n = s.length();

    size_t count = 1;
    for (size_t i = 0; i < n - d - 1; ) {
        if (i = jump(s, i, d))
            ++count;
        else
            return answer(-1);
    }

    answer(count);
}

int main()
{
    size_t n, d;
    std::cin >> n >> d;

    std::string s;
    std::cin >> s;

    solve(s, d);

    return 0;
}

