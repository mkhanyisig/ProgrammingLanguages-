#		 * CS 333 Programming Languages FA17
#		 * Project 5  task 1
#		 *
#		 * Mkhanyisi Gamedze
#		 * 23 October 2017


puts "Ruby LinkedList demo 1";

class Node
  attr_accessor :data, :next, :previous #  public accessors

  def initialize(data, nxt, prev)
      @data = data
      @next = nxt
      @previous= prev
  end
end

class LinkedList
    
  attr_accessor  :head, :tail,:size #  public accessors

  def initialize()
      n = Node.new(0, nil,nil)
    @head = n # two null pointers @ init
    @tail=@head
    @size=0
  end
  
  def print()
      puts "printing list: "
      ptr=@head
      
      while(ptr.next!=nil)
        puts " #{ptr.data}"
        ptr=ptr.next
      end
      if(ptr.next==nil)
          puts " #{ptr.data}"
      end
  end
  
   def backward()
      puts "printing list backward: "
      ptr=@tail
      #puts "#{ptr.data}"
      
      while(ptr.previous!=nil)
        puts " #{ptr.data}"
        ptr=ptr.previous
      end
      if(ptr.previous==nil)
          puts " #{ptr.data}"
      end
  end
  
  def push(val)
      n = Node.new(val, nil,nil) 
      
      if(@size==0)
          @head.data=val
      elsif @size==1
          n = Node.new(val, nil,nil) 
          @head.previous=n
          n.next=@head
          @tail=@head
          @head=n
          #puts "head #{@head.data}  tail #{@tail.data}"
      else
          @head.previous=n
          n.next=@head
          @head=n
      end
      @size+=1
      
  end
  
  def pop()
      n=@head
      v=n.data
      @head=n.next
      @head.previous=nil
      @size-=1
      return v
  end
  
  def append(val)
      n=Node.new(val, nil,@tail)
      #puts "n #{n.data}"
      @tail.next=n
      @tail=n # change pointer
      puts "tail #{@tail.data}"
      @size+=1
  end
  
  def remove(val)
    ptr = @head
    if (ptr.data == val)
        puts "head removed "
      @head = ptr.next
      @size-=1
    else
      while (ptr.next != nil) && (ptr.next.data != val) # loop till first occurence found
        ptr = ptr.next
      end
      unless ptr.next == nil # erase node with val
        ptr.next = ptr.next.next 
        ptr.next.previous=ptr
        @size-=1
      end
    end
  end
  
  def delete(val)
    ptr = @head
    if (ptr.data == val)
        puts "head removed "
      @head = ptr.next
      @size-=1
    else
        (0..3).each do |i|    
            while (ptr.next != nil) && (ptr.next.data != val) # loop till first occurence found
                 ptr = ptr.next
            end
            unless ptr.next == nil # erase node with val
                ptr.next = ptr.next.next 
                ptr.next.previous=ptr
                @size-=1
            end
            redo if(ptr.next != nil) # traverse whole list to check for all instances of val occuring
        end
    end
  end
  
  def size()
      return @size
    end
    
  def clear()
    @head = nil # two null pointers @ init
    @tail=@head
    @size=0
  end
    

  
 end
 
 # Testing all my methods
 
 ll=LinkedList.new()
 for i in 0..5 do
     puts " #{i}"
      ll.push(i)
 end
 puts "size : #{ll.size()}"
 ll.print()
 puts "popped:  #{ll.pop()}"
 puts "popped:  #{ll.pop()}"
 puts "size : #{ll.size()}"
 ll.print()
 puts "\nAppend: "
 ll.append(7)
 ll.append(15)
 ll.append(2)
 puts "size : #{ll.size()}"
 ll.print()
 
 ll.remove(2)
 puts "\nlinkedlist head #{ll.head.data}"
 ll.append(0)
 ll.append("x")
 ll.push("hey")
 ll.append("there")
 ll.push("look")
 ll.append("$")
 ll.push("b")
 puts "\n \nBefore deleting 0"
 ll.backward()
 ll.delete(0)
 puts "After deleting all instances of 0"
 ll.backward()
 
 puts "size : #{ll.size()}"
 
 
      