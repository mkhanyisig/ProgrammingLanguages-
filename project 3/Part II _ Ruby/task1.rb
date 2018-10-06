#  Ruby demonstration Mkhanyisi 
puts "Hello CS33 World! ";

#It is not recommended to use global variables. They make programs cryptic.
$g_variable = 333 # declaring a global variable, whose scope covers the entire code

#  demostrating the use of a global variable within a class
class Class1
   # class fields
   @@school="Colby College"
   
   
   # define additional functions onto my project, this functions present user info
   # 
   def initialize()
      # adding some local variables, whose scope within the whole class
      @cust_id = 2019
      @cust_name = "Mkhanyisi Gamedze"
      @cust_addr = 6170
   end
   def display_details()
      # local variables called outside the init method, as they are class variables
      puts "\n We have a #@@school student"
      puts "Student graduation year is #@cust_id"
      puts "Student name: #@cust_name"
      puts "Student box address: #@cust_addr \n \n"
   end
   def print_global
      puts "Global variable is #$g_variable"
   end
   
   # Instance variables are available across methods for any particular instance or object
   def instance(val)
       @value=val # creating new instance variable
       puts "New  instance variable is #@value"
    end
   
   
   
end
class Class2
   def print_global
      puts "Global variable in Class2 is #$g_variable"
   end
end


class1obj = Class1.new # declare new object instance
class1obj.print_global
class1obj.display_details()
class1obj.instance(69)