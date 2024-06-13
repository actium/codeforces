scan [gets stdin] "%d %d %d" n m k

set c [expr {($k - 1) / $n}]
set r [expr {($k - 1) % $n}]
set x [expr {1 + $r * $m + $c}]

puts $x
