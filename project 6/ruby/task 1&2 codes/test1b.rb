=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# File IO demo

# read in wctest text file  and print out the first 20 characterss


aFile = File.open("wctest.txt", "r")
if aFile
   content = aFile.sysread(20) # read the first 20 characters in the program
   puts content
else
   puts "Unable to open file!"
end
