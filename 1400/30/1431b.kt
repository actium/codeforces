fun answer(x:Int)
{
    println("${x}")
}

fun solve(s:String)
{
    answer(s.count { it == 'w' } + s.split("w").sumOf { it.length / 2})
}

fun test_case()
{
    val s = readLine()!!

    solve(s)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
