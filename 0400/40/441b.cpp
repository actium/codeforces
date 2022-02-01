#include <algorithm>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& s, unsigned v)
{
    std::sort(s.begin(), s.end());

    unsigned k = 0;

    std::vector<unsigned> q(1 + 3000 + 1, v);
    for (const auto [a, b] : s) {
        const unsigned c = std::min(b, q[a]);
        k += c;
        q[a] -= c;

        if (c < b) {
            const unsigned d = std::min(b - c, q[a + 1]);
            k += d;
            q[a + 1] -= d;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned v;
    std::cin >> v;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, v);

    return 0;
}
