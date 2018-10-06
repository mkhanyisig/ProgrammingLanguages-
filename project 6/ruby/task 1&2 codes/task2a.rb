=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end


# function one
def add(a,b) 
   sum=a+b
   puts "#{a} + #{b} = #{sum}"
end

def subtract(a,b)
	return (a-b)
end
x=15
y=4
puts "addition"
add(x,y)


puts "difference"
diff=subtract(x,y)
puts "#{x} - #{y} = #{diff}"