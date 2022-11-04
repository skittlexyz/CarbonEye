const char MAIN_page[] PROGMEM = R"=====(
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <link rel="preconnect" href="https://fonts.googleapis.com">
            <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
            <link href="https://fonts.googleapis.com/css2?family=Prompt:ital,wght@0,200;1,400&display=swap" rel="stylesheet">
            
            <style>
                html {
                    display: inline-block;
                    margin: 0px auto;
                }
                body {
                    margin-top: 10%;
                    margin-left: 20%; margin-right: 20%;
                    background: #212121;
                }
                h1 {
                    font-family: "Prompt", sans-serif;
                    font-size: 40pt;
                    font-style: italic;
                    color: #39B54A;
                    margin-left: 5%; margin-right: 5%; margin-top: 5%; margin-bottom: 5%;
                }
                p {
                    font-family: "Prompt", sans-serif;
                    font-size: 20pt;
                    color: #b8b8b8;
                }
                .container {
                    display: flex;
                    flex-direction: column;
                }
                .container::after{
                    content: " ";
                    display: block;
                }
                .left,
                .center {
                    border-radius: 999999999px;
                    box-shadow:  9px 9px 26px #181818,-9px -9px 26px #2a2a2a;
                text-align: center;
                }
            </style>
            <title>CarbonEye</title>
        </head>
        <body>

            <div class="container">
                <div class="center">
                    <h1>CarbonEye🍃</h1>
                </div>
                <br>
                <div class="left">
                    <p>PPM (partes por milhão): <span id="ppm">0</span></p>
                    <p>Tempratura: <span id="temp">0</span> Cº</p>
                </div>
            </div>

            <script>
                setInterval(function() {
                getData1();
                getData2();
                }, 200);

                function getData1() {
                    var xhttp = new XMLHttpRequest();
                    xhttp.onreadystatechange = function() {
                        if (this.readyState == 4 && this.status == 200) {
                            document.getElementById("ppm").innerHTML =
                                this.responseText;
                        }
                    };
                    xhttp.open("GET", "readVal1", true);
                    xhttp.send();
                }

                function getData2() {
                    var xhttp = new XMLHttpRequest();
                    xhttp.onreadystatechange = function() {
                        if (this.readyState == 4 && this.status == 200) {
                            document.getElementById("temp").innerHTML =
                                this.responseText;
                        }
                    };
                    xhttp.open("GET", "readVal2", true);
                    xhttp.send();
                }
            </script>
        </body>
    </html>
)=====";