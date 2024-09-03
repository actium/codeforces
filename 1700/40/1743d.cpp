#include <iostream>
#include <string>
#include <vector>

class Integer {
public:
    static Integer parse(std::string value)
    {
        const size_t n = value.length(), k = (n + 63) / 64;

        std::vector<uint64_t> digits(k);
        for (size_t i = k, q = 63; !value.empty(); value.pop_back()) {
            if (q++ == 63) {
                --i;
                q = 0;
            }

            digits[i] |= uint64_t(value.back() - '0') << q;
        }

        while (digits.size() > 1 && digits[0] == 0)
            digits.erase(digits.begin());

        return Integer(std::move(digits));
    }

    void shift()
    {
        const size_t n = digits_.size();

        uint64_t carry = 0;
        for (size_t i = 0; i < n; ++i) {
            const uint64_t c = digits_[i] << 63;
            digits_[i] >>= 1;
            digits_[i] |= carry;
            carry = c;
        }

        if (digits_[0] == 0)
            digits_.erase(digits_.begin());
    }

    Integer operator |(const Integer& rhs) const
    {
        const size_t n = digits_.size(), m = rhs.digits_.size(), k = std::max(n, m);

        std::vector<uint64_t> digits(k);
        for (size_t i = 1; i <= k; ++i) {
            if (i <= n)
                digits[k-i] |= digits_[n-i];
            if (i <= m)
                digits[k-i] |= rhs.digits_[m-i];
        }
        return Integer(std::move(digits));
    }

    bool operator <(const Integer& rhs) const
    {
        const size_t n = digits_.size();
        if (n != rhs.digits_.size())
            return n < rhs.digits_.size();

        for (size_t i = 0; i < n; ++i) {
            if (digits_[i] != rhs.digits_[i])
                return digits_[i] < rhs.digits_[i];
        }
        return false;
    }

    explicit operator std::string() const
    {
        std::string value;
        for (const uint64_t d : digits_) {
            for (size_t i = 63; ~i != 0; --i)
                value.push_back('0' + (d >> i & 1));
        }

        while (value.size() > 1 && value[0] == '0')
            value.erase(value.begin());

        return value;
    }

private:
    explicit Integer(std::vector<uint64_t> digits)
        : digits_(std::move(digits))
    {}

private:
    std::vector<uint64_t> digits_;

}; // class Integer

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length(), x = s.find('0');

    if (2 * x >= n)
        return answer(std::string(n, '1'));

    Integer p = Integer::parse(s), q = p, r = p;
    for (size_t i = 0; i < x; ++i) {
        q.shift();
        r = std::max(r, p | q);
    }

    answer(std::string(r));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    const size_t x = s.find('1');
    if (x != std::string::npos)
        s = s.substr(x);

    solve(s);

    return 0;
}
