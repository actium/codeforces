#include <iostream>
#include <vector>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<bool>& v)
{
    const size_t n = v.size();

    for (size_t i = 1; i < n; ++i) {
        if (!v[i])
            return answer("Oh, my keyboard!");
    }

    answer("I become the guy.");
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<bool> v(n + 1);
    for (size_t i = 0; i < 2; ++i) {
        size_t p;
        std::cin >> p;

        for (size_t i = 0; i < p; ++i) {
            unsigned a;
            std::cin >> a;

            v[a] = true;
        }
    }

    solve(v);

    return 0;
}

