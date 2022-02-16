fun answer(x:Long)
{
    println("${x}")
}

fun solve(n:Int, k1:Int, k2:Int, s:String)
{
    var q:Long = 0

    var p:Int = 0
    for (c in s) {
        p = if (c == '1') { minOf(k1, k2 - p) } else { 0 }
        q += p
    }

    answer(q)
}

fun test_case()
{
    val (n, k1, k2) = readLine()!!.split(" ").map(String::toInt)

    val s = readLine()!!

    solve(n, k1, k2, s)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
