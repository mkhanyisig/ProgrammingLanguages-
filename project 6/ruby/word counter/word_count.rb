=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# read in the word file & count the word frequencies

WORDS_COUNT = {} # hashmap
puts "Enter the filename you want to read"
filename=gets.chomp ;

#errors handling
if(File.exists?(filename)==false)
	puts "Error: your file does not exist"
	puts "**Read unsuccesful"	
else
	file = File.open(filename, "r") 

	# loop through all words and add to hash maps
	file.each_line do |line|
	  words = line.split 
	  words.each do |word|
		word = word.gsub(/[,()'"]/,'')
		word=word.downcase # make it a lower case
		if WORDS_COUNT[word]
		  WORDS_COUNT[word] += 1
		else
		  WORDS_COUNT[word] = 1
		end
	  end
	end
	puts "Words count: #{WORDS_COUNT.size}"

	# sort & then perform quality check   [the following link was very helpful for me in doing this: http://www.rubyinside.com/how-to/ruby-sort-hash]
	puts "------------------------"
	puts "Ruby hash map quality check"
	i=0
	WORDS_COUNT.sort {|a,b| b[1] <=> a[1]}.each do |w,frequency|
		if(i<20)
			puts "#{frequency}  :: #{w}"
		else
		
		end
		i=i+1
	end
	puts "**Succesful read :)"
end

