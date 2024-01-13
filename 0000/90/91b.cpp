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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> v(n);

    std::vector<std::pair<unsigned, size_t>> q;
    for (size_t i = n; i-- > 0; ) {
        if (q.empty() || q.back().first >= a[i]) {
            v[i] = -1;
            q.emplace_back(a[i], i);
        } else {
            const auto it = std::lower_bound(q.begin(), q.end(), a[i], [](const auto& a, unsigned b) {
                return b <= a.first;
            });
            v[i] = it->second - i - 1;
        }
    }

    answer(v);
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
