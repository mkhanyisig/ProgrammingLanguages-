<!DOCTYPE html>
<html>
<title>Web Page Design</title>
<head>
<script>
function welcome() {
   document.write("Passing function as variable in javascript  <br>");
}

function add(a,b){
    document.write("<br>Addition :"+a+"+"+b+"= "+(a+b)+"<br>");
    return a+b;
}
function multiply(a,b){
    document.write("<br> Multiplication  :"+a+"+"+b+"= "+(a+b)+"<br>");
    return a*b;
}

welcome();

// passing function as variable
add(5,7);
multiply(2,9);
document.write("<br>  Passing function as variable<br>");
multiply(add(4,7),multiply(9,3))


</script>
</head>
<body>
</body>
</html>