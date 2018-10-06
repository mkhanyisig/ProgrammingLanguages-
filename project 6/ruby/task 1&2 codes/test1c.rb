=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# File IO demo

# Create new file object and write lines into it


aFile = File.new("./in.txt", "w") # create new file objects

aFile.syswrite("This is the first line written using Syswrite")
# add lines using puts
aFile.puts("                            Additional words inserted by different method")
lines=["This is another line", "This is another one as well"]
lines.each{ |line| aFile.puts(line) }


aFile.closes

   
   

