=begin
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
=end

count = 0
arr = []

10.times do |i|
   arr[i] = Thread.new {
      sleep(rand(0)/10.0)
      Thread.current["current"] = count
      count += 1
   }
end

arr.each {|t| t.join; print t["current"], ", " }
puts "count = #{count}"
