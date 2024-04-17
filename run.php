<?php
header( "refresh:15;url=index.html" );
$command_venv = escapeshellcmd("python3 -m venv venv && source venv/bin/activate");
$output_venv = shell_exec($command_venv);
sleep(1);
$command_run = escapeshellcmd("./main");
$output_run = shell_exec($command_run);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>M3OEP - Mario Kart</title>
    <meta name="author" content="Aaron Perkel and Owen Cook">
    <meta name="description" content="CS2300 M3OEP - Spring 2024 - Mario Kart - C++ Python HTML">
    <!-- https://stackoverflow.com/questions/16716695/prevent-caching-of-html-page -->
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate"/>
    <meta http-equiv="Pragma" content="no-cache"/>
    <meta http-equiv="Expires" content="0"/>
	<link rel="icon" href="images/8.png">
	<link rel="apple-touch-icon" href="images/8.png">
    <style>
        img {
                display: block; /* Ensures the image is treated as a block-level element */
                margin: 0 auto; /* Centers the image horizontally */
                animation: rotation 2s infinite linear;
            }

            @keyframes rotation {
                from {
                    transform: rotate(0deg);
                }
                to {
                    transform: rotate(360deg);
                }
            }
    </style>
</head>
<body>
    <header>
        <h1>CS2300 M3OEP - Mario Kart</h1>
    </header>
    <main>
        <h3>A new game is being created!</h3>
        <p>Please do not close this window or click the Back or Refresh buttons in your browser.</p>
        <br>
        <br>
        <img src="images/8.png" width="200">
    </main>
</body>
</html>
