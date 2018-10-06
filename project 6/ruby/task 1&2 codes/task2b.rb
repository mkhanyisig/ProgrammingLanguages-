=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end


# overriding functions

# Overiding class functions
# The Rectangle constructor accepts arguments in either of the following forms:  
#   Rectangle.new([x_top, y_left], length, width)  
#   Rectangle.new([x_top, y_left], [x_bottom, y_right])  
class Rectangle  
	  def initialize(*args)  
		if args.size < 2  || args.size > 3  
		  # modify this to raise exception, later  
		  puts 'This method takes either 2 or 3 arguments'  
		else  
		  if args.size == 2  
			puts 'Two arguments'  
		  else  
			puts 'Three arguments'  
		  end  
		end  
	  end  
	  
	

end  
Rectangle.new([0,0], 3, 4)  
Rectangle.new([0,0], [3, 4])  


def f(a)
	b=a*a
	puts "the product #{a}*#{a}=#{b}"
end




f(5)
#Rectangle.f(5,10)
#Rectangle.f(-1,5,12)
