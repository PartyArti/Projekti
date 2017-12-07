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
<a href="etusivu.html">Takaisin</a>
<p>
</body>
</html>
