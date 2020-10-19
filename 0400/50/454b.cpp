#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    a.push_back(a[0]);

    std::vector<size_t> r;
    for (size_t i = 1; i <= n; ++i) {
        if (a[i] < a[i-1])
            r.push_back(i);
    }

    if (r.size() == 0)
        return answer(0);

    if (r.size() == 1)
        return answer(n - r[0]);

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

