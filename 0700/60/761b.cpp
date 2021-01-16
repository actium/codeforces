#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned c)
{
    const size_t n = a.size();

    std::vector<unsigned> da(n), db(n);
    for (size_t i = 1; i < n; ++i) {
        da[i-1] = a[i] - a[i-1];
        db[i-1] = b[i] - b[i-1];
    }
    da.back() = a[0] + c - a.back();
    db.back() = b[0] + c - b.back();

    const auto check = [&](size_t i) {
        for (size_t j = 0; j < n; ++j) {
            if (db[j] != da[(i+j)%n])
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < n; ++i) {
        if (check(i))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b, c);

    return 0;
}

