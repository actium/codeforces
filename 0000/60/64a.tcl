scan [gets stdin] "%d" n

set x 1
while {$n > 1} {
    set x [expr $x * $n]
    set n [expr $n - 1]
}

puts $x

