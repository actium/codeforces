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

void solve(const std::vector<unsigned>& a)
{
    std::vector<std::pair<unsigned, unsigned>> q;
    for (const unsigned x : a) {
        if (q.empty() || x != q.back().first)
            q.emplace_back(x, 0);

        ++q.back().second;
    }

    unsigned z = 0, k = 0;
    for (const std::pair<unsigned, unsigned>& e : q) {
        if (e.first == 0)
            z += e.second;
        else
            k += std::min(e.second, z);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
