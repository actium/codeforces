fun answer(k:Long)
{
    println("${k}")
}

fun solve(a:List<Int>)
{
    val x = a.max()
    val p = a.indexOfLast { it == x }
    answer((x - 1).toLong() * a.size + p + 1)
}

fun main()
{
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    solve(a)
}
