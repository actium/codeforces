fun answer(v:Int)
{
    println("${v}")
}

fun solve(s:String)
{
    answer(s.split(".").sumOf { maxOf(0, it.length - 1) })
}

fun test_case()
{
    val n = readLine()!!.toInt()
    val s = readLine() + "." + readLine()
    solve(s)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
