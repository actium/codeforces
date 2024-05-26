#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& d)
{
    std::vector<unsigned> v[5];
    for (const unsigned x : d)
        v[(x / 100 != 0) << 2 | (x / 10 % 10 != 0) << 1 | (x % 10 != 0)].push_back(x);

    if (!v[1].empty() && !v[2].empty()) {
        v[0].push_back(v[1][0]);
        v[0].push_back(v[2][0]);
    } else {
        for (size_t i = 1; i < 4; ++i) {
            if (!v[i].empty()) {
                v[0].push_back(v[i][0]);
                break;
            }
        }
    }

    if (!v[4].empty())
        v[0].push_back(100);

    answer(v[0]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t k;
    std::cin >> k;

    std::vector<unsigned> d(k);
    std::cin >> d;

    solve(d);

    return 0;
}