const char PAGE_LOGIN[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html lang="pt_br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Protótipo de automação</title>
    <style>
        @font-face {
        font-family: 'Inter';
        src: url(../font/Inter_24pt-Bold.ttf);
        }
        :root {
            --color-primary: #022853;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            background-color: white;
            color: var(--color-primary);
            font-family: 'Inter';
        }

        header {
            width: 100%;
            height: 170px;
            background-image: url(../images/header--image--1.png);
            background-size: cover;
            display: flex;
            align-items: center;
            justify-content: space-around;
        }

        .header-container {
            display: flex;
            align-items: center;
            margin-bottom: 25px;
            color: white;
            font-size: 12px;
        }

        .login {
            display: flex;
            align-items: center;
            flex-direction: column;
            justify-content: space-between;
            padding-top: 10px;
            gap: 60px;
        }

        .login-intro {
            font-size: 14px;
            text-align: center;
            width: 70%;
            height: 73px;
            padding: 20px;
            display: flex;
            flex-direction: column;
            gap: 15px;
        }

        .login-info{
            display: flex;
            flex-direction: column;
            gap: 10px;
        }

        .label-text {
            display: flex;
            padding: 20px;
            align-items: start;
            flex-direction: column;
            gap: 20px;
        }

        input {
            all: unset;
            font-family: 'Inter';
            padding: 10px;
            border: 0px;
            border-radius: 10px;
            background-color: #0228531F;            
            width: 236px;
            height: 32px;
        }

        .login-container {
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 40px;
        }

        button {
            padding: 15px 40px 15px 40px;
            border: 2px solid var(--color-primary);
            background-color: white;
            border-radius: 10px;
            color: var(--color-primary);
            font-family: 'Inter';
            font-size: 20px;
        }

    </style>
</head>
<body>
    <header>
        <div class ="header-container">
            <img src="../images/logo--ramo.png" class="logo" alt="Logo do ramo">
            <h2>Ramo Estudantil IEEE <br> IFF Campos Centro</h2>
        </div>
    </header>

    <main>
        <div class="login">
            <div class="login-intro">
                <h1>Bem vindo(a)!</h1>
                <h2>Insira seu nome para continuar:</h2>
            </div>
                <form class = "login-container" onsubmit="redirectUser(event)">
                    <div class="label-text">
                        <input type="text" id="user" required>
                    </div>
                    <div>
                        <button type="submit" class="acess">Acessar</button>
                    </div>
                </form>
        </div>
    </main>
    <script>
        function redirectUser(event) {
            event.preventDefault();
            const user = document.getElementById('user').value;

            localStorage.setItem('user', user);
            
            window.location.href = 'main.html';
        }
    </script>
</body>
</html>
)=====";

const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Protótipo de automação</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Inter:ital,opsz,wght@0,14..32,100..900;1,14..32,100..900&family=Sarpanch:wght@700&display=swap" rel="stylesheet">

    <style>

        :root {
            --color-primary: #022853;
        }

        body {
            margin: 0;
            padding: 0;
            font-family: 'Inter';  
            font-weight: bold;
        }

        header {
            padding: 5px;
            background-image: url(../images/header--image--2.png);
            background-size: cover;
            width: 100%;
            height: 97px;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        .return-button {
            background-image: url(../images/return.png);
            width: 38px;
            height: 38px;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin: 40px;
        }

        .control-intro {
            font-size: 24px;
            color:var(--color-primary);
            text-align: center;
        }

        .buttons-container {
            display: flex;
            flex-direction: column;
            margin-top: 40px;
            gap: 60px;
        }

        .button-info{
            text-decoration: none;
            border-radius: 10px;
            width: 236px;
            height: 98px;
            background-color: var(--color-primary);
            color: white;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
            font-family: 'Inter';
            font-size: 24px;
            font-weight: bold;
        }

        #button-2{
            opacity: 70%;
        }

        #button-3{
            opacity: 50%;
        }
        
    </style>
</head>
<body>
    <header>
        <a class="return-button" href="login.html"></a>
        <img src="../images/logo--ramo.png">
    </header>
    <main>
        <label class="control-intro">Olá, <span id="user-name"></span>! O que deseja controlar?</label>
        <div class="buttons-container">
            <a class="button-info" id="button-1" href="light.html">
                <img src="../images/lampada.png" alt="lâmpada">
                <label>Iluminação</label>
            </a>
            <a class="button-info" id="button-2" href="lock.html">
                <img src="../images/cadeado.png" alt="cadeado">
                <label>Fechadura</label>
            </a>
            <a class="button-info" id="button-3" href="disp.html">
                <img src="../images/televisao.png" alt="televisão">
                <label>Dispositivos</label>
            </a>
        </div>
    </main>
    <script>
        const username = localStorage.getItem('user');
        if (username) {
            document.getElementById('user-name').textContent = username;
        } else {
            // Redireciona para o login
            window.location.href = 'login.html';
        }
    </script>
    
</body>
</html>

)=====";

const char PAGE_LIGHT[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Iluminação</title>

    <style>
        :root {
            --color-primary: #0072AE;
            --color-secundary: #022853;
        }

        body {
            margin: 0;
            padding: 0;
            font-family: 'Inter';  
            font-weight: bold;
            color: var(--color-secundary)
        }

        header {
            padding: 5px;
            background-image: url(../images/header--image--2.png);
            background-size: cover;
            width: 100%;
            height: 97px;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        button {
            font-family: 'Inter';
            font-weight: bold;
            font-size: 24px;
            border: 0;
            border-radius: 10px;
            width: 120px;
            height: 80px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
        }

        .return-button {
            background-image: url(../images/return.png);
            width: 38px;
            height: 38px;
        }

        .click-container {
            display: flex;
            align-items: center;
            text-align: center;
            flex-direction: column;
            justify-content: space-between;
            gap: 40px;
            margin: 40px 0 0 0;
            font-size: 24px;
        }

        .click-info {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 40px;
        }

        .on {
            background-color: var(--color-primary);
            color:white;
            
        }

        .off {
            background-color: white;
            color: var(--color-primary);
            border: 2px solid var(--color-primary);
        }

        .reg {
            background-color: white;
            border: 2px solid var(--color-primary);
            border-radius: 10px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
            font-family: 'Inter';
            font-size: 24px;
            font-weight: bold;
            color: var(--color-primary);
            width: 200px;
            height: 80px;
        }

    </style>
</head>
<body>
    <header>
        <a class="return-button" href="main.html"></a>
        <img src="../images/logo--ramo.png">
    </header>
    <main>
        <div class="click-container">
            <label>Iluminações disponíveis:</label>
            <div class="click-info">
                <button id="btn1" class="on" onclick="changeState(1)">
                    <img id="light1" src="../images/lampada.png">
                    <label>L1</label>
                </button>
                <button id="btn2" class="on" onclick="changeState(2)">
                    <img id="light2" src="../images/lampada.png">
                    <label>L2</label>
                </button>
                <button id="btn3" class="on" onclick="changeState(3)">
                    <img id="light3" src="../images/lampada.png">
                    <label>L3</label>
                </button>
                <button id="btn4" class="on" onclick="changeState(4)">
                    <img id="light4" src="../images/lampada.png">
                    <label>L4</label>
                </button>
            </div>
            <button class="reg">
                <img src="../images/plus.png">
                <label>Cadastrar</label>
            </button>
        </div>
    </main>

    <script>
        var leds = [0,0,0,0];
        // função que atualiza o estilo do botao e da imagem quando o primeiro é acionado
        function updateButtonAndImage(ledNumber) {
            var button = document.getElementById(`btn${ledNumber}`);
            var imageLight = document.getElementById(`light${ledNumber}`);

            var imgOn = "/images/lampada.png"
            var imgOff = "/images/lampadaB.png"

            if (leds[ledNumber - 1] === 1) {
                button.classList.remove("on");
                button.classList.add("off");
                imageLight.src = imgOff;
            } else {
                button.classList.remove("off");
                button.classList.add("on");
                imageLight.src = imgOn;
            }            
        }

        // Checa o estado anterior do led
        window.onload = function() {
            for (let i = 0; i < 4; i++) {
            const savedState = localStorage.getItem(`led${i + 1}`);
            if (savedState !== null) {
                leds[i] = parseInt(savedState);
            }
            updateButtonAndImage(i + 1);
            }
        } 

        // Função de callback do botão
        function changeState(ledNumber) {
          var xhr = new XMLHttpRequest();

          leds[ledNumber - 1] = leds[ledNumber - 1] === 1 ? 0 : 1;

          updateButtonAndImage(ledNumber);
          localStorage.setItem(`led${ledNumber}`, leds[ledNumber - 1]);

          var url = leds[ledNumber - 1] === 1 ? "/L" + ledNumber : "/H" + ledNumber;
          xhr.open("GET", url, true);
          xhr.send();
        }
    </script>
</body>
</html>

)=====";

const char PAGE_LOCK[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Iluminação</title>

    <style>
        :root {
            --color-primary: #0072AE;
            --color-secundary: #022853;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;

        }

        body {
            font-family: 'Inter';  
            font-weight: bold;
            color: var(--color-secundary)
        }

        header {
            padding: 5px;
            background-image: url(../images/header--image--2.png);
            background-size: cover;
            width: 100%;
            height: 97px;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        button {
            font-family: 'Inter';
            font-weight: bold;
            font-size: 24px;
            border: 0;
            border-radius: 10px;
            width: 120px;
            height: 80px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
        }

        .return-button {
            background-image: url(../images/return.png);
            width: 38px;
            height: 38px;
        }

        .click-container {
            display: flex;
            align-items: center;
            text-align: center;
            flex-direction: column;
            justify-content: space-between;
            gap: 40px;
            margin: 40px 0 0 0;
            font-size: 24px;
        }

        .click-info {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 40px;
        }

        .on {
            background-color: var(--color-primary);
            color:white;
            
        }

        .off {
            background-color: white;
            color: var(--color-primary);
            border: 2px solid var(--color-primary);
        }

        .reg {
            background-color: white;
            border: 2px solid var(--color-primary);
            border-radius: 10px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
            font-family: 'Inter';
            font-size: 24px;
            font-weight: bold;
            color: var(--color-primary);
            width: 200px;
            height: 80px;
        }

    </style>
</head>
<body>
    <header>
        <a class="return-button" href="main.html"></a>
        <img src="../images/logo--ramo.png">
    </header>
    <main>
        <div class="click-container">
            <label>Fechaduras disponíveis:</label>
            <div class="click-info">
                <button id="btn6" class="off" onclick="changeState(6)">
                    <img id="light6" src="../images/cadeadoB.png">
                    <label>F1</label>
                </button>
            </div>
            <button class="reg">
                <img src="../images/plus.png">
                <label>Cadastrar</label>
            </button>
        </div>
    </main>

    <script>
        var leds = [0,0,0,0];
        // função que atualiza o estilo do botao e da imagem quando o primeiro é acionado
        function updateButtonAndImage(ledNumber) {
            var button = document.getElementById(`btn${ledNumber}`);
            var imageLight = document.getElementById(`light${ledNumber}`);

            var imgOn = "/images/cadeado.png"
            var imgOff = "/images/cadeadoB.png"

            if (leds[ledNumber - 1] === 1) {
                button.classList.remove("on");
                button.classList.add("off");
                imageLight.src = imgOff;
            } else {
                button.classList.remove("off");
                button.classList.add("on");
                imageLight.src = imgOn;
            }            
        }

        // Checa o estado anterior do led
        window.onload = function() {
            for (let i = 0; i < 4; i++) {
            const savedState = localStorage.getItem(`led${i + 1}`);
            if (savedState !== null) {
                leds[i] = parseInt(savedState);
            }
            updateButtonAndImage(i + 1);
            }
        } 

        // Função de callback do botão
        function changeState(ledNumber) {
          var xhr = new XMLHttpRequest();

          leds[ledNumber - 1] = leds[ledNumber - 1] === 1 ? 0 : 1;

          updateButtonAndImage(ledNumber);
          localStorage.setItem(`led${ledNumber}`, leds[ledNumber - 1]);

          var url = leds[ledNumber - 1] === 1 ? "/L" + ledNumber : "/H" + ledNumber;
          xhr.open("GET", url, true);
          xhr.send();
        }
    </script>
</body>
</html>
)=====";

const char PAGE_DISP[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Iluminação</title>

    <style>
        :root {
            --color-primary: #0072AE;
            --color-secundary: #022853;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;

        }

        body {
            font-family: 'Inter';  
            font-weight: bold;
            color: var(--color-secundary)
        }

        header {
            padding: 5px;
            background-image: url(../images/header--image--2.png);
            background-size: cover;
            width: 100%;
            height: 97px;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        button {
            font-family: 'Inter';
            font-weight: bold;
            font-size: 24px;
            border: 0;
            border-radius: 10px;
            width: 120px;
            height: 80px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
        }

        .return-button {
            background-image: url(../images/return.png);
            width: 38px;
            height: 38px;
        }

        .click-container {
            display: flex;
            align-items: center;
            text-align: center;
            flex-direction: column;
            justify-content: space-between;
            gap: 40px;
            margin: 40px 0 0 0;
            font-size: 24px;
        }

        .click-info {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 40px;
        }

        .on {
            background-color: var(--color-primary);
            color:white;
            
        }

        .off {
            background-color: white;
            color: var(--color-primary);
            border: 2px solid var(--color-primary);
        }

        .reg {
            background-color: white;
            border: 2px solid var(--color-primary);
            border-radius: 10px;
            display: flex;
            align-items: center;
            justify-content: space-evenly;
            font-family: 'Inter';
            font-size: 24px;
            font-weight: bold;
            color: var(--color-primary);
            width: 200px;
            height: 80px;
        }

    </style>
</head>
<body>
    <header>
        <a class="return-button" href="main.html"></a>
        <img src="../images/logo--ramo.png">
    </header>
    <main>
        <div class="click-container">
            <label>Dispositivos disponíveis:</label>
            <div class="click-info">
                <button id="btn5" class="off" onclick="changeState(5)">
                    <img id="light5" src="../images/televisaoB.png">
                    <label>D1</label>
                </button>
            </div>
            <button class="reg">
                <img src="../images/plus.png">
                <label>Cadastrar</label>
            </button>
        </div>
    </main>

    <script>
        var leds = [0,0,0,0,0];
        // função que atualiza o estilo do botao e da imagem quando o primeiro é acionado
        function updateButtonAndImage(ledNumber) {
            var button = document.getElementById(`btn${ledNumber}`);
            var imageLight = document.getElementById(`light${ledNumber}`);

            var imgOn = "/images/televisao.png"
            var imgOff = "/images/televisaoB.png"

            if (leds[ledNumber - 1] === 1) {
                button.classList.remove("on");
                button.classList.add("off");
                imageLight.src = imgOff;
            } else {
                button.classList.remove("off");
                button.classList.add("on");
                imageLight.src = imgOn;
            }            
        }

        // Checa o estado anterior do led
        window.onload = function() {
            for (let i = 0; i < 5; i++) {
            const savedState = localStorage.getItem(`led${i + 1}`);
            if (savedState !== null) {
                leds[i] = parseInt(savedState);
            }
            updateButtonAndImage(i + 1);
            }
        } 

        // Função de callback do botão
        function changeState(ledNumber) {
          var xhr = new XMLHttpRequest();

          leds[ledNumber - 1] = leds[ledNumber - 1] === 1 ? 0 : 1;

          updateButtonAndImage(ledNumber);
          localStorage.setItem(`led${ledNumber}`, leds[ledNumber - 1]);

          var url = leds[ledNumber - 1] === 1 ? "/L" + ledNumber : "/H" + ledNumber;
          xhr.open("GET", url, true);
          xhr.send();
        }
    </script>
</body>
</html>
)=====";
