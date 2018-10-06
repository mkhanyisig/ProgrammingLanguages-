=begin
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	Ruby : Functions and File I/O
=end

# Asks user to enter website URL & then reads the content there, returning the top 20 words

require 'net/http'
require 'uri'

def open(url)
  Net::HTTP.get(URI.parse(url))
end

WORDS_COUNT = {} # hashmap
puts "Please enter the URL you want to read contents of"

link=gets.chomp ;
page_content = open(link) # a long string containing the words

# create new file and write contents onto it
words = page_content.split 
words.each do |word|
	word = word.gsub(/[,()'"]/,'')
	word=word.downcase # make it a lower case
	if WORDS_COUNT[word]
	  WORDS_COUNT[word] += 1
	else
	  WORDS_COUNT[word] = 1
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
	







