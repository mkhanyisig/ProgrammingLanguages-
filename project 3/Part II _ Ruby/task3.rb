#  Ruby demonstration Mkhanyisi 
puts "All basic types";

# ruby has integer and float numeric types

# ints
@n1=6
@n2=12
@n3=-3

# floats
@n4=3.56
@n5=9.5
@n6=-5.4

puts "sum of two ints #@n1 and #@n2 #{ @n1 +@n2 }"

puts "sum of two ints  and float #@n1 and #@n4 #{ @n1 +@n2 }"

puts " operator % in int #@n1  #{ @n1%4} "


puts " operator / on int #@n1 & #@n3  #{ @n1/@n3} "

puts " operator * on int #@n1 & #@n3  #{ @n1*@n3} "

puts " operator % on float #@n5  #{ @n5%@n3} "


puts " operator / on float #@n5 & #@n4  #{ @n5/@n4} "

# experimenting with string 

@s1="hey  "
@s2="CS333 "

# concatenate two two string
puts "combine two strings ' #@s1 ' and ' #@s2  ' to : #{ @s1 +@s2 } :) "

# two arrays of same size
@a1=Array(0..9)
@a2=Array(0..9)



# add arrays
puts " add  arrays  #{ @a1+@a2} "

# subtract arrays
puts " subbtract  arrays  #{ @a1-@a2} "

