# Ruby demo
puts "Welcome to my Ruby Control flow demo \n\n";

a = 10;
b = -17;
c = 24;
d = 5.5;

# if else & elsif demo
puts "Conditional Statements demo:\nLet's start with if, else & elseif\n";
# check whether a is odd or even
if a%2==1
    puts "a is #{a}, so it is odd\n";
elsif a%2==0
    puts "a is #{a}, so it is even\n";
else
    puts "Check again, a is #{a}, so your a value might be a float or some other non int type\n";
end
    
# loop demonstrations

puts "Lets check out the use of a forloop\n";
# increase a to 26
puts "lets increase the value of a from #{a} to 26\n"; 
for i in 0..100 do
    a+=2;
    if a==26
        puts "Done. Your value of is now: #{a}\n";
        break
    end
end

# while loop
puts "While loop demo\n";
# reduce a to -10
puts "Lets now decrease the value of a to -10. The current value is #{a}\n";
while a>-10
    a-=1;
end
puts "done with while loop, the value of a is now #{a}"

# until loop
puts "Ruby also has an until control statement, lets use this to #{a} to 26\n";

until a==26
    if a<26
        a+=1;
    else 
        a-+1;
    end
end
puts "done with until loop, the value of a is now #{a}\n \n"

# redo demo & break demo
puts "return a value #{a} to default value of 10, using redo statement & break statement"
a=77
(0..2).each do |i|
  a-=1;
  redo if a>10
  # increase until 10 otherwise
  a+=2;
  
  redo if a<10
    
    a-=2
  if a==10
      break
  end
end


puts "\n you final a value: #{a} \n"



# each statement demonstration
puts "lets use the each ruby statement to print out some countries:\n "
na=["USA", "Mexico", "Canada","puerto Rico", "Cuba", "Dominican republic"]

na.each do |country|
    puts country
end
puts "\nThats it, done. What region are these from?";

# case demonstration
puts "\n\n\nlets use a puts method to tell where these people are from\n ";

def give_country(name)
   case name
   when "Makumbi"
       puts "Arthur Bumblebee Makumbi is from Uganda"
    when"Mkhanyisi"
        puts "Thats me, i'm from Swaziland"
    when "Moeketsi"
        puts "Justice is from Lesotho"
    when "Noura"
        puts "She is from Senegal"
    else
        puts "I dont know"
    end
   
end

nm="Noura"

puts "Where is #{nm} from? \n";
give_country(nm)













