#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& state, const std::string& cipher, size_t n)
{
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t delta = abs(state[i] - cipher[i]) % 10;
        count += std::min(delta, 10 - delta);
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string state, cipher;
    std::cin >> state >> cipher;

    solve(state, cipher, n);

    return 0;
}

