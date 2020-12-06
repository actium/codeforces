#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, unsigned k)
{
    const auto f = [&](const std::pair<unsigned, unsigned>& a) {
        for (const auto& b : p) {
            const unsigned d = abs(b.first - a.first) + abs(b.second - a.second);
            if (d > k)
                return false;
        }
        return true;
    };

    for (const auto& a : p) {
        if (f(a))
            return answer(1);
    }

    answer(-1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

