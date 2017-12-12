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
  
if (mysqli_connect_errno()) 
{ 
  echo "Yhteys epäonnistui" . mysqli_connect_error(); 
} 
  
$result = mysqli_query($con,"SELECT * FROM Rottahaku"); 
echo "<table border='5'>" .
"<tr> <th>Tila</th> <th>Pvm</th> <th>Aika</th> </tr>";
while($row = mysqli_fetch_array($result)) { 
echo "<tr>";
echo "<td>" . $row['Tila'] . "</td>";
echo "<td>" . $row['Pvm'] . "</td>";
echo "<td>" . $row['Aika'] . "</td>";
echo "</tr>";
} 
echo "</table>"; 
  
mysqli_close($con); 
?>