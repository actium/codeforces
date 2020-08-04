#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& s, unsigned a, unsigned b)
{
    const size_t n = s.size();

    std::sort(std::next(s.begin()), s.end(), std::greater<unsigned>());

    unsigned long long sum = std::accumulate(s.cbegin(), s.cend(), 0u);
    for (size_t i = 1; i < n; ++i) {
        if (1ull * s[0] * a >= sum * b)
            return answer(i-1);

        sum -= s[i];
    }

    answer(n-1);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s, a, b);

    return 0;
}

