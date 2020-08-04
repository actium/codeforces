#include <iostream>
#include <vector>

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

    const int d = t[1] - t[0];
    for (size_t i = 2; i < n; ++i) {
        if (t[i] - t[i-1] != d)
            return answer(t.back());
    }

    answer(t.back() + d);
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

