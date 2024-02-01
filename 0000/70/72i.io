n := File standardInput readLine asNumber

happy := false
upset := false

x := n
while (x != 0,
    d := x mod(10)
    x := (x / 10) floor
    if (d > 0 and n mod(d) == 0, happy := true, upset := true)
)

if (happy and upset, "happy", if (happy, "happier", "upset")) println
