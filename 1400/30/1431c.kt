fun answer(v:Int)
{
    println("${v}")
}

fun solve(p:List<Int>, k:Int)
{
    var v:Int = 0
    for (i in 0 until p.size) {
        val s = (p.size - i) / k
        v = maxOf(v, p.subList(i, i + s).sum())
    }

    answer(v)
}

fun test_case()
{
    val (n, k) = readLine()!!.split(" ").map(String::toInt)
    val p = readLine()!!.split(" ").map(String::toInt)
    solve(p, k)
}
fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
