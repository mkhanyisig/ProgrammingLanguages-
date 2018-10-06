=begin
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
=end


def Alarm1
   i = 0
   while i<=2
      puts "Alarm 1 : Beeep wake up, time : #{Time.now}"
      sleep(2) #snooze
      i = i+1
   end
end

def Alarm2
   i = 0
   while i<=3
      puts "Alarm 2 : Dong Dong!! wake up, time : #{Time.now}"
      sleep(4) #snooze
      i = i+1
   end
end

puts "Started At #{Time.now}"
t1 = Thread.new{Alarm1()}
t2 = Thread.new{Alarm2()}
t1.join
t2.join
puts "End at #{Time.now}"
