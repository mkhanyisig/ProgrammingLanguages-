<!DOCTYPE html>
<html>
<title>Web Page Design</title>
<head>
<script>
function welcome() {
   document.write("Lets test our Control flow statements  <br>");
}


function conditional(x){
    document.write("Conditional statement check: <br> is "+x+" even, odd or neither <br>");
    // checks whether a numbet is odd, even or neither
    if(x%2==1){
        document.write(x+" is odd");
    }else if(X%2==0){
        document.write(x+" is even");
    }
    else{
        document.write(x+"  is neither even nor odd");
    }
}

// forlop control flow demo & while loop
function looping(x){
    // counting upto 5
    document.write("<br> <br> <br> Lets count from 0 to "+x+"  : ");
    for(i=0; i<x; i++){
        document.write(i+"  ");
        
    }
    document.write("<br> Now lets count from down from "+x+" to 0 using while loop : ");
    while(x>=0){
        document.write(x+"  ");
        x-=1;
    }
    
    
    document.write("<br >done <br>");
} 

// For in loop, loop through all array elements (loop through an Object)
function colby_college(x){
    
     document.write("<br >Lets loop through Colby's properties { <br>");
    // create object with properties and then loop through it: in this case Colby 
    var COLBY = {
        Address: "4000 Mayflower Hill Dr, Waterville, ME 04901",
        Acceptance_rate: "17.5% (2016)",
        Mascot: "Mule",
        Established: "1813",
        Mascot: "White Mules",
        Website:	"http://www.colby.edu",
    }
    
    for (var property in COLBY) {
        document.write(property + ": " + COLBY[property]+"<br>");
    }
    document.write("} <br>");
    
} 


// testing the switch
 
function csclass(course){
    
    // print out what CS course number you are in
    document.write(" <br> <br> I am in CS"+course+"  what is the title of that class? <br>  ==> ");
    
    switch (course) {
    //var trees = "green";
     // document.write("  hey ");
    
    case 333:
     document.write("  Programming languages ");
    break;
    
    case 251:
     document.write("  Data analysis & visualization ");
    break;
    case 273:
     document.write("  Computer Game design ");
    break;
    case 231:
     document.write("  Data structures & Algorithms ");
    break;
    case 151:
     document.write("  Computational thinking: Art ");
    break;
    case 152:
     document.write("  Computational thinking: Science ");
    break;
    
    default:
        document.write("  I dont know, check out the course catalogue");
    }  
}



welcome();
conditional(7);  // conditional 
csclass(251);   // case control flow
looping(7); // for loop
colby_college(); // for in loop

</script>
</head>
<body>
</body>
</html>