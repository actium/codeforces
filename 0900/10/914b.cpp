#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "Agasa", "Conan" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    constexpr size_t N = 100000;

    std::vector<unsigned> f(N);
    for (const unsigned x : a)
        ++f[x-1];

    for (size_t i = 0; i < N; ++i) {
        if (f[i] % 2 == 1)
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

