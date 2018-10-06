# Bubble sort ruby demonstration
puts "Ruby bubble sort";

# returns array sorted in ascending order, through the bubble sort algorithm
def bubble_sort(array)
  
  n = array.length
  
  loop do
    swapped = false

    (n-1).times do |i|
      if array[i] > array[i+1]  # whenever we have a situation where numbers are arranged in descending order, swap
        array[i], array[i+1] = array[i+1], array[i]
        swapped = true
      end
    end

    if(swapped==false)
        break
    end
  end

  return array
end

# create a random array of size x to hold variables between 0 & max
def rand_array(x, max)
    rnd=Random.new    
  array=Array.new
  for i in 0..x do 
      array.push(rnd.rand(max))
  end
  
  return array
end

ar=rand_array(7, 6) 

puts "Before sorting our array is \n#{ar}"
puts "After sorting our array, output is: \n#{bubble_sort(ar)}"