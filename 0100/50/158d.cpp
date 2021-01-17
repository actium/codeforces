#include <iostream>
#include <vector>

#include <climits>

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

void solve(const std::vector<int>& t)
{
    const size_t n = t.size();

    int s = INT_MIN;
    for (size_t p = 1; p * 3 <= n; ++p) {
        if (n % p != 0)
            continue;

        for (size_t i = 0; i < p; ++i) {
            int c = 0;
            for (size_t j = 0; j < n; j += p)
                c += t[(i + j) % n];

            s = std::max(s, c);
        }
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

