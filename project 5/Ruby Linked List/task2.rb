#		 * CS 333 Programming Languages FA17
#		 * Project 5  task 2
#		 *
#		 * Mkhanyisi Gamedze
#		 * 23 October 2017


# Polymorphism demo ruby
puts "Polymorphism demo";

class Car #parent class
    @top_speed
    @fuel_economy
    @price
    @brand
    @affordability
    
  def init(name)
      @name=name
      
  end
  
  def Sell()
      puts "Car: #{@name} (#{@brand}), top speed #{@top_speed}, fuel_economy ->#{@fuel_economy}. Sell price #{@price} [affordability :#{@affordability} "
    end
end


class Lamborghini < Car # inherits all Car methods
    
    
    
    def about()
        puts "About:\nLamborghini: Founded :1963, Owner Volkswagen Group, Production output
3,245 vehicles (2015)"
        @brand="Lamborghini"
        @affordability="rich"
        puts "Affordability: #{@affordability}"
        
    end
    
    def update()
        @top_speed="350 km/h"
        @fuel_economy="10 MPG"
        @price="$200,000."
    end
end
        
class Buggati < Car # inherits all Car methods
    
    
    
    def about()
        puts "About:\nBuggati: Founded :1909;, Founder Ettore Bugatti, Headquarters	Molsheim, Alsace, France"
        @brand="Buggati"
        @affordability="elites"
        puts "Affordability: #{@affordability}"
        
    end
    
    def update()
        @top_speed="408.84 km/h"
        @fuel_economy="15 MPG"
        @price="$1.5 million"
    end
end    

class Kia < Car # inherits all Car methods
    
    
    
    def about()
        puts "About:\nKia Motors: Founded December 1944, Headquarters	Seoul, South Korea, Production output 2,827,321 units (2013"
        @brand="Kia"
        @affordability="middle class"
        puts "Affordability: #{@affordability}"
        
    end
    
    def update()
        @top_speed="208 km/h "
        @fuel_economy="38.1mpg "
        @price="$12,390 to $26,995"
    end
end  


c1=Buggati.new()    

c1.init("spider")
c1.about()
c1.update()
c1.Sell()
puts "\n \n \n"
k1=Kia.new()
k1.init("2017 Kia Sportage")
k1.about()
k1.update()
k1.Sell()
