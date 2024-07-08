fun answer(v:Set<Int>)
{
    val s = v.joinToString(" ")
    println("${v.size} ${s}")
}

fun solve(s:Set<Int>, t:Set<Int>)
{
    val u = s union t
    val v = s intersect t
    answer(u subtract v)
}

fun main()
{
    var s = readLine()!!.split(" ").map(String::toInt)
    var t = readLine()!!.split(" ").map(String::toInt)

    solve(s.drop(1).toSet(), t.drop(1).toSet())
}
