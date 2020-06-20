#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] - k > 15)
            break;

        k = t[i];
    }

    answer(std::min(int(k + 15), 90));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

