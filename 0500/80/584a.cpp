#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned t)
{
    if (t == 10) {
        if (n == 1)
            return answer("-1");

        t = 1;
    }

    std::string s(n, '0');
    s.front() = '0' + t;
    answer(s);
}

int main()
{
    unsigned n, t;
    std::cin >> n >> t;

    solve(n, t);

    return 0;
}

