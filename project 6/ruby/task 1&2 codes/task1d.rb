=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# File IO demo

# Create new file object and write lines into it, using user input from terminal


aFile = File.new("./usr_input.txt", "w") # create new file objects


puts "What’s the best thing that’s happened to you this week?"
s = gets.chomp ;

aFile.puts("Answer :"+s)

aFile.close

   
   

