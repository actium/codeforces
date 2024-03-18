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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& s)
{
    const size_t n = s.size();

    s.push_back(0);         // sentinel

    std::sort(s.begin(), s.end());

    unsigned k = 0;
    for (size_t i = n / 2, j = n; j != 0; --j) {
        if (s[j] == 0)
            continue;

        while (i != 0 && s[i] * 2 > s[j])
            --i;

        if (i != 0)
            s[i--] = 0;

        ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
