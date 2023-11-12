<h1 align="center">UrbanFlow - Sprint 4 Edge</h1>
<img src="./images/foto_circuito.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/dashboard.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/mqtt_tago.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/terminal_wokwi.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
  
## :link: `Links`
  <br>
* Youtube: https://youtu.be/ubO15qhy05E
* Wokwi: https://wokwi.com/projects/380873831375964161



## :memo: `Descrição do projeto`

* O urban flow é um aplicativo  que mostra para os usuarios, qual a melhor rota de ônibus que  o usuario deve tomar  para que chegue em seu destino com melhor tempo, tambem levando em consideração a lotação do ônibus para que o usuario não tenha que pegar um ônibus lotado, todas essas informações (lotação, localização e tempo de espera) são mostradas no aplicativo assim que você seleciona sua rota, onde você tambem pode salvar essa rota para caso utilize ela mais de uma vez e não queira pesquisar toda hora, e uma ultima funcionalidade é que a cada mês o sistema gera um relatorio com todas as informações coletadas, como lotação media de tal ônibus, horarios com mais e menos movimento etc.
  <br>
* Pensando nisso adequamos essa ideia, utilizando 2 sensores PIR para detectar prensença de entrada ou saída das pessoas nos ônibus. Usamos a Tago tanto para as informações via MQTT quanto para fazer o Dashboard.

## :books: `Funcionalidades`

* <b>Sensor PIR para entrada</b>: Quando ocorre presença de movimento, significa que uma pessoa acabou de entrar no ônibus.
  <br>
* <b>Sensor PIR para saída</b>: Quando ocorre presença de movimento, significa que uma pessoa acabou de sair do ônibus.
  <br>
* <b>Dashboard</b>:  A informação de quantidades de pessoas no ônibus é armazenada e exibida num gráfico de volume

## :seedling: `Instruções de uso`

* Clonar repositório
  <br>
* Colocar o código na IDE Arduino
  <br>
* Fazer as devidas conexões dos sensores no ESP32
  <br>
* Criar um device na Tago
  <br>
* Copiar e colar o código da Tago no código do ESP32
  <br>
* Criar o dashboard
  <br>
* Rodar o programa

## :clipboard: `Requisitos`

* 1 ESP32
  <br>
* IDE Arduino
  <br>
* 2 Sensores PIR
  <br>
* Tago.io
  <br>
* Ligação ao computador
  <br>
* Conexão Wifi

## :hammer: `Dependências`
* Biblioteca ArduinoJson, para enviar dados no formato JSON.
  <br>
* Biblioteca Wifi, para fazer a conexão do ESP32 com o wifi.
  <br>
* Biblioteca PubSubClient, para enviar dados via MQTT
  <br>
* Device na Tago.io

## :wrench: `Tecnologias utilizadas`

* ESP32;
  <br>
* C++;
  <br>
* Sensor PIR;
  <br>
* Tago.io;
  <br>
* MQTT;
  <br>
* JSON;


## :handshake: `Colaboradores`
<table>
  <tr>
    <td align="center">
        <sub>
          <b>Enzo Luiz Goulart - RM99666</b>
          <br>
        </sub>
        <sub>
          <b>Natan Eguchi dos Santos - RM98720</b>
          <br>
        </sub>
        <sub>
          <b>Kayky Paschoal Ribeiro - RM99929</b>
          <br>
        </sub>
        <sub>
          <b>Gustavo Henrique Santos Bonfim - RM98864</b>
          <br>
        </sub>
        <sub>
          <b>Lucas Yuji Farias Umada - RM99757 </b>
          <br>
        </sub>
    </td>
  </tr>
</table>

## :dart: `Status do projeto`
Em desenvolvimento :hourglass_flowing_sand: