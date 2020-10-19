#include <functional>
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<bool> v(n);
    const std::function<void(size_t)> traverse = [&](size_t i) -> void {
        v[i] = true;

        for (size_t j = 0; j < n; ++j) {
            if (!v[j] && (a[j].first == a[i].first || a[j].second == a[i].second))
                traverse(j);
        }
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (!v[i]) {
            traverse(i);
            ++k;
        }
    }

    answer(k - 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

