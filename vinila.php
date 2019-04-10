<!DOCTYPE html>
<html>
<body>
<?php
$cid=$_POST['cid'];
$cname=$_POST['cname'];
$con=@mysqli_connect("localhost","root","123456");
echo "connected to database";
$db=@mysqli_select_db($con,"student");
echo "selected database";
$str="INSERT INTO course1 VALUES('$cid','$cname')";
if ($con->multi_query($str) === TRUE) {
    echo "New records created successfully";
} else {
    echo "Error: " . $str . "<br>" . $con->error;
}
$res=@mysqli_query($str);
if($res>0)
{
echo "record created";
}
?>
</body>
</html>

