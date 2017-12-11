<!DOCTYPE html>
<html lang="fi-FI">
<head>

<meta charset="utf-8">
<link rel="stylesheet" href="tyyli.css">
<title>Taulukkosivu</title>

<style>
.button {
  display: inline-block;
  border-radius: 4px;
  background-color: #555555;
  border: none;
  color: #FFFFFF;
  text-align: center;
  font-size: 18px;
  padding: 20px;
  width: 180px;
  transition: all 0.5s;
  cursor: pointer;
  margin: 5px;
}

.button span {
  cursor: pointer;
  display: inline-block;
  position: relative;
  transition: 0.5s;
}

.button span:after {
  content: '\00bb';
  position: absolute;
  opacity: 0;
  top: 0;
  right: -20px;
  transition: 0.5s;
}

.button:hover span {
  padding-right: 25px;
}

.button:hover span:after {
  opacity: 1;
  right: 0;
}</style>

</head>

<body>

<h2>RoTa 6000 taulukko</h2>


<?php

$servername = "139.59.170.58";
$dbname='projekti';
$username='root';
$password='projekti2017';

$con=mysqli_connect($host,$username,$password,$dbname);
if (mysqli_connect_errno()) {
echo "Fail !";
}


$result = mysqli_query($con,"SELECT * FROM Rotta2");
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

date_default_timezone_set('Europe/Helsinki');

echo "<br>Sivu päivitetty viimeksi: " . (date("d.m.Y"));

echo date(" G:i:s ") . "<br><br>";
mysqli_close($con);

?>
<a class="button" style="vertical-align:middle"  href="etusivu.html"><span>Takaisin</span></a>

</body>
</html>
