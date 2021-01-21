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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const auto check = [&a](std::vector<unsigned>& d) {
        const size_t n = a.size(), k = d.size();
        if (n < k)
            return false;

        std::sort(d.begin(), d.end());

        do {
            for (size_t i = 0, j = 0; j < n; ++j) {
                while (j < n && std::find(a[j].cbegin(), a[j].cend(), d[i]) == a[j].cend())
                    ++j;

                if (j < n && ++i == k)
                    return true;
            }
        } while (std::next_permutation(d.begin(), d.end()));

        return false;
    };

    for (unsigned x = 1; ; ++x) {
        std::vector<unsigned> d;
        for (unsigned q = x; q != 0; q /= 10)
            d.push_back(q % 10);

        if (!check(d))
            return answer(x - 1);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(6));
    std::cin >> a;

    solve(a);

    return 0;
}

