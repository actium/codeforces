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

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        k += s[i];

        if (i > 0 && s[i-1] == 0)
            k += s[i];
    }

    if (k > 0 && s[0] == 0)
        --k;

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

