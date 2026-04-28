<?php

if (isset($_POST['submit'])){
	$conn = mysqli_connect("localhost","root","","college10");
	if(!$conn){
		die("Connected died: ".mysqli_connect_error());
	}
	
	$fname = $_POST['fname'];
	$lname = $_POST['lname'];
	$age = $_POST['age'];
	$gender = $_POST['gender'];
	$email = $_POST['email'];
	$address = $_POST['address'];
	$branch = $_POST['branch'];
	$division = $_POST['division'];
	$year = $_POST['year'];
	$skills = $_POST['skills'];
	$dob = $_POST['dob'];
	
	## $stmt = $conn->prepare("SELECT * FROM users WHERE age > ?") 
	if(!empty($_POST['skills'])){
		$skills = implode(",",$_POST['skills']);
	} else{
		$skills = "";
	}
	
	$sql = "INSERT INTO students (fname,lname,age,gender,email,address,branch,division,year,skills,dob)
	VALUES('$fname','$lname','$age','$gender','$email','$address','$branch','$division','$year','$skills','$dob')";
	
	if(mysqli_query($conn,$sql)){
		echo "Data saved - omkar_login.php:32";
	} else {
		echo "Error: - omkar_login.php:34".mysqli_error($conn);
	}
	
	mysqli_close($conn);
}
?>


