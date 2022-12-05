const char MAIN_page[] PROGMEM = R"=====(
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="https://cdn.statically.io/gh/skittlexyz/carboneye_assets/main/css/bootstrap.min.css">
        <link rel="stylesheet" href="https://cdn.statically.io/gh/skittlexyz/carboneye_assets/main/css/styles.css">

        <link rel="icon" href="https://cdn.statically.io/gh/skittlexyz/carboneye_assets/main/assets/favicon.svg" />
        <title>
            CarbonEye
        </title>
    </head>
    <body>
        <nav class="navbar navbar-dark bg-dark top-sticky">
            <div class="container-fluid">
                <a class="text1 nohover" href="http://127.0.0.1:3000/carboneyepage/pages/index.html">CarbonEye🍃</a>
                <a href="http://127.0.0.1:3000/carboneyepage/pages/index.html" type="button">
                    <span clas>
                        <svg xmlns="http://www.w3.org/2000/svg" width="32" height="32" fill="#969696"
                            class="bi bi-arrow-left-square-fill" viewBox="0 0 16 16">
                            <path
                                d="M16 14a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V2a2 2 0 0 1 2-2h12a2 2 0 0 1 2 2v12zm-4.5-6.5H5.707l2.147-2.146a.5.5 0 1 0-.708-.708l-3 3a.5.5 0 0 0 0 .708l3 3a.5.5 0 0 0 .708-.708L5.707 8.5H11.5a.5.5 0 0 0 0-1z" />
                        </svg>
                    </span>
                    <div class="collapse navbar-collapse" id="navbarNav">
                        <ul class="navbar-nav">
                            <li class="nav-item">
                                <a class="nav-link active" aria-current="page" href="./index.html">Página Inicial</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link" href="./colors.html">Cores</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link" href="./profile.html">Perfil</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link" href="./config.html">Configurações</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link" href="./suport.html">Suporte</a>
                            </li>
                        </ul>
                    </div>
            </div>
        </nav>
        <div class="sidebyleft" style="margin: 10px;">
            <div class="card text-bg-dark mb-3" style="max-width: 1080px;">
                <div class="row g-0">
                    <div class="col-md-4">
                        <img src="https://raw.githubusercontent.com/skittlexyz/carboneye_assets/main/assets/places/one.png" class="img-fluid rounded-start" alt="carboneye">
                    </div>
                    <div class="col-md-8">
                        <div class="card-body">
                            <h5 class="card-title">Sala de Aula</h5>
                            <p class="card-text">CarbonEye localizado na Sala de Aula.</p>
                            <p class="card-text">PPM (partes por milhão): <span id="ppm">0</span></p>
                            <p class="card-text">Temperatura (Cº): <span id="temp">0</span></p>
                            <p class="card-text"><small class="text-muted">Última atualização agora.</small></p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <nav class="navbar navbar-dark bg-dark bottom-sticky-right">
            <a href="./index.html">
                <img src="https://raw.githubusercontent.com/skittlexyz/carboneye_assets/main/assets/logo2.png" alt="logo" style="width: 50px; margin: 10%;">
            </a>
        </nav>
        <script>
            setInterval(function () {
                getData1();
                getData2();
            }, 200);
            function getData1() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
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
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("temp").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "readVal2", true);
                xhttp.send();
            }
        </script>
        <script src="https://cdn.statically.io/gh/skittlexyz/carboneye_assets/main/js/bootstrap.bundle.min.js"></script>
    </body>
    </html>
)=====";