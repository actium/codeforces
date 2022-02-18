#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& n)
{
    const auto d = [&n](size_t i) {
        return n[i] - '0';
    };

    const size_t m = n.length();
    for (size_t i = 0; i < m; ++i) {
        const unsigned a = d(i);
        if (a % 8 == 0)
            return answer(n.substr(i, 1));

        for (size_t j = 0; j < i; ++j) {
            const unsigned b = d(j) * 10 + a;
            if (b % 8 == 0)
                return answer(n.substr(j, 1) + n.substr(i, 1));

            for (size_t k = 0; k < j; ++k) {
                const unsigned c = d(k) * 100 + b;
                if (c % 8 == 0)
                    return answer(n.substr(k, 1) + n.substr(j, 1) + n.substr(i, 1));
            }
        }
    }

    no_answer();
}

int main()
{
    std::string n;
    std::cin >> n;

    solve(n);

    return 0;
}
