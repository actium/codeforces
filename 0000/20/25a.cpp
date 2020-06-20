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

void solve(const std::vector<size_t>& v)
{
    const size_t n = v.size();
    for (size_t i = 1; i < n - 1; ++i) {
        if (v[i] % 2 == v[i-1] % 2)
            continue;

        if (v[i-1] % 2 == v[i+1] % 2)
            return answer(i+1);

        return answer(i);
    }

    answer(n);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}

