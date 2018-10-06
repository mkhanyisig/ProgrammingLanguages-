=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# File IO demo

# puts, putc & gets demonstration

 
puts "Give me two random number(Press enter when done)";
num1 = gets.chomp ;
num2 = gets.chomp ;
print "you entered: #{num1} & #{num2}";

puts "Enter your favourite color (Press enter when done)";
color=gets.chomp;

puts "the first four characters are";

i = 0;
while i < 4  do
   putc color[i];
   puts "  "
   i +=1
end

