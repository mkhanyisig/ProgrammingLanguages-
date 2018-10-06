=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# creating a dynamic function

class Message
  [:hello, :goodbye].each do |action|
    define_method action do |arg|
      puts "#{action} #{arg}"
    end
  end
end

#irb
Message.instance_methods false #=> [:hello, :goodbye]
puts "Say hi to someone (enter the name) "
s=gets.chomp ;
Message.new.hello(s)
puts " Ok, now Say goodbye someone else"
b=gets.chomp ;
Message.new.goodbye(b)