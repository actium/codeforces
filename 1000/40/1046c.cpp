#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(std::vector<unsigned>& s, const std::vector<unsigned>& p, unsigned d)
{
    unsigned t = s[d-1] + p[0], k = 0;
    for (size_t i = 0, l = 1, r = s.size()-1; i < d; ++i) {
        if (i == d-1)
            continue;

        if (s[i] + p[r] <= t) {
            --r;
        } else {
            ++k;
            ++l;
        }
    }

    answer(k + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> s(n), p(n);
    std::cin >> s >> p;

    solve(s, p, d);

    return 0;
}
