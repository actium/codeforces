fun answer(x:Int)
{
    println("${x}")
}

fun solve(a:List<Int>, b:List<Int>)
{
    val u = a.count { it !in b }
    val v = b.count { it !in a }
    if (u > v) {
        answer(2 * v + 2)
    } else {
        answer(2 * u + 1)
    }
}

fun test_case()
{
    val (n, m) = readLine()!!.split(" ").map(String::toInt)
    val a = readLine()!!.split(" ").map(String::toInt)
    val b = readLine()!!.split(" ").map(String::toInt)
    solve(a, b)
}
fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
