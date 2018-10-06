# Ruby demo
puts "Ruby function as data type \n\n";

a=10
b=13
c=-5

# my function
def add(x)
    return x+7;
end

def multiply(y)
    return y*4;
end


# assigning a function onto a variable, that gives us an error
#func=add
# we can however use the method 
func_add=method(:add);
func_mult=method(:multiply);

# calling this variable declared functions

puts "Add 7 to #{a} gives #{func_add.call(a)}\n"
puts "Multiplying by  #{a} by 4  gives #{func_mult.call(a)}\n"


# assinging function output to a variable
output=add(10)
puts "Assinging function out put to a variable, adding 7 to our input 10, we get #{output}\n"

# passing function as input into another function possible
d=add(multiply(6))
puts "Making function input to another function, we get #{d}";


















