 <?php 

$servername = "localhost";
$username = "username";
$password = "";
$dbname="test";

// Create connection
$conn = new mysqli($servername, $username, $password,$dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo"data connection susseful";

 // prepare sql and bind parameters
 $stmt = $conn->prepare("INSERT INTO History (Time, Compartment_no, Slot_time) VALUES (?, ?, ?)");
 echo "New ";
$stmt->bind_param("sss", $Slot1_Time, $Slot1_Comp_No, $Slot1_Slot_Time);
  

$Slot1_Time = $_POST['Slot1_Time'];//1300
$Slot1_Comp_No = $_POST['Slot1_Comp_No'];
$Slot1_Slot_Time = $_POST['Slot1_Slot_Time'];
$status=$stmt->execute();
if ($status === TRUE) {
  echo "New record created successfully";
} else { echo "Error: " . $sql . "<br>" . $conn->error; }

$Slot2_Time = $_POST['Slot2_Time'];
$Slot2_Comp_No = $_POST['Slot2_Comp_No'];
$Slot2_Slot_Time = $_POST['Slot2_Slot_Time'];

$Slot3_Time = $_POST['Slot3_Time'];
$Slot3_Comp_No = $_POST['Slot3_Comp_No'];
$Slot3_Slot_Time = $_POST['Slot3_Slot_Time'];

$On_button = $_POST['On_button'];
$Off_button = $_POST['Off_button'];

$status = $_POST['status'];
echo $status;

echo $Slot1_Time." ";
echo $Slot1_Comp_No." ";
echo $Slot1_Slot_Time;
echo nl2br("\n");
echo $Slot2_Time." ";
echo $Slot2_Comp_No." ";
echo $Slot2_Slot_Time." ";
echo nl2br("\n");
echo $Slot3_Time." ";
echo $Slot3_Comp_No." ";
echo $Slot3_Slot_Time." ";
echo "<br>".$On_button;
echo "<br>".$Off_button;
?>