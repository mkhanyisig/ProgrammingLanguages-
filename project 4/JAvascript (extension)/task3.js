<!DOCTYPE html>
<html>
<title>Web Page Design</title>
<head>
<script>
function welcome() {
   document.write("Lets build a bubble sort algorithm in Javascript  <br>");
}

function bubbleSort(array){
    var l = array.length;
    var swapped =-1;  // my equivalent of false
    
    while(true){
        swapped =-1;
        
        for(i=0;i<l;i++){
            if(array[i] > array[i+1]){ // if swap needed because of improper order
                // swap elements
                var a=array[i];
                var b=array[i+1];
                array[i]=b;
                array[i+1]=a;
                swapped=1;   // swap made
            }
        }
        
        if(swapped==-1){
            break;
        }
        
    }
    document.write("<br>Final sorted array ["+array+"]<br>");
    
}

function buildarray(x){ // build a random  int array
    var ar = new Array();
    for(i=0;i<x;i++){
        ar.push(Math.floor(55*Math.random(55)));   
    }
    return ar;
}

welcome();
var b=buildarray(12);
document.write("My array Before sorting: ["+b+"]");
bubbleSort(b);




</script>
</head>
<body>
</body>
</html>