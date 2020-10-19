#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& d)
{
    unsigned long long s[3] = {};
    for (size_t l = 0, r = d.size(); l <= r; ) {
        if (s[1] == s[2])
            s[0] = s[1];

        if (s[1] <= s[2])
            s[1] += d[l++];
        else
            s[2] += d[--r];
    }

    answer(s[0]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}

