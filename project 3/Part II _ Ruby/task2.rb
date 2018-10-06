#  Ruby demonstration Mkhanyisi 
puts "Binary search ";


$g_variable = 333 # declaring a global variable

def binarySearch(list ,value,min ,max )
    @value=value
    @min=min
    @max=max
    puts "searching for #@value in the list of numbers from #@min -  #@max"
    if(min>max) # terminating condition, variable not there
        puts ">value variable #@value not in list";
        return -1
    else
        @center=((max+min)/2).to_i
        
        if(list[@center]<value) # right side
            return  binarySearch(list ,value,@center+1 ,max )
        elsif(list[@center]>value) # left side
            return binarySearch(list ,value,min ,@center+1 )
        else # object found 
            puts ">found your value #@value"
            return 1
        end
    end
end


$digits = Array(0..67)

$output=binarySearch($digits ,22,0 ,67 )


puts "done #$output"



