set a [gets stdin]
set s [split $a]
set t [lsort -integer -decreasing -indices $s]
foreach v $t { lset s $v [incr i] }
puts $s
