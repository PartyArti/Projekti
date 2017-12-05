<!DOCTYPE html>
<html lang="fi-FI">
<head>

<meta charset="utf-8">
<link rel="stylesheet" href="tyyli.css">
<title>Taulukkosivu</title>
</head>

<body>

<h2>RoTa 6000 taulukko</h2>


<?php 
  

  
/* 
 * To change this license header, choose License Headers in Project Properties. 
 * To change this template file, choose Tools | Templates 
 * and open the template in the editor. 
 */ 
$servername = "139.59.170.58";
$dbname='projekti';
$username='root';
$password='projekti2017';

$con=mysqli_connect($host,$username,$password,$dbname);
if (mysqli_connect_errno()) {
echo "Fail !";
}

  
$result = mysqli_query($con,"SELECT * FROM yritelma"); 
echo "<table border='5'>" .
"<tr> <th>ID</th> <th>Pvm</th> <th>Aika</th> <th>Tila</th> </tr>"; 
while($row = mysqli_fetch_array($result)) { 
echo "<tr>"; 
echo "<td>" . $row['ID'] . "</td>"; 
echo "<td>" . $row['Pvm'] . "</td>"; 
echo "<td>" . $row['Aika'] . "</td>"; 
echo "<td>" . $row['Tila'] . "</td>"; 
echo "</tr>"; 
} 
echo "</table>"; 
  
    date_default_timezone_set('Europe/Helsinki');

echo "<br>Sivu päivitetty viimeksi: " . (date("d.m.Y"));

echo date(" h:i:s") . "<br><br>";
  
mysqli_close($con); 

?>
<p><a href="etusivu.html">Takaisin</a>
</body>
</html>
