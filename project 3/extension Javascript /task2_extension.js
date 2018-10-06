<html>
   <head>
   
      <script type="text/javascript">
         function bSearch()
         {
            document.write ("Lets find your value");
            var list=buildList(36);
            document.write("<br> your list ["+list+"] <br><br>"+"binary search 6: " )
            document.write("##$$ <br>"+binarySearch(list, 6, 0 , 36)+"##$$ <br>" )
            
         }
         
        var list =  new Array(); // new javascript list
        var center;
        
        
        function buildList(num_values){
            // builds list of integers from zero up until the num_values integer
            for (i = 0; i <num_values; i++) {
                list.push(i); 
            }
            
            return list;
        }
        

        function binarySearch(list, value, min , max) 
        {
            
 			document.write("<br> <br>new search value"+value+"  min:"+min+" max:"+max+"<br> <br>");
            if(min>max){
                document.write("#### your value: "+value+"  was not found" );
                return 1;
            }
            else{
                var center=Math.round((max+min)/2); // give whole number
                
                document.write("recursion center:"+center+"v @ index: "+list[center]+ "<br> <br>");
                
                
                if(list[center]<value){
                    // search right branch
                    binarySearch(list, value, center , max); // recursion
                }
                
                else if(list[center]>value){
                    // search left branch
                    binarySearch(list, value, min , center); // recursion
                }
                
                else{
                    // value found
                    // list[center]==value => positive outcome
                    document.write("**** your value: "+value+"  was  found <br> <br>" );
                    
                    return -1;
                }
            }
            
            
        }
      </script>
      
   </head>
   <body>
      <p>Click the following button to call the function</p>
      
      <form>
         <input type="button" onclick="bSearch()" value="binary search your value">
      </form>
      
      
   </body>
</html>