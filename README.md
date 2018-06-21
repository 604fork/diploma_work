## Vladislav Volkov course work

Library with external business logic

### How to deploy and test this library?

To deploy and test library follow the next easy steps:

1) Open the terminal and go to the project directory <br>
2) Enter this command: "python3 drmServer.py" (it will start http server on 8000 port)<br>
3) Open course-work project in your IDE<br>
4) Add CMake option: "-DSERVER_URL=127.0.0.1:8000" (In CLion: File/Settings.../Build, Execution, Deployment/CMake)<br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;where: 127.0.0.1 - IP address of http server, 8000 - port<br>
5) Build project<br>

### How to set server answers?

In .../cgi-bin/functionAnswers we have directory: functionAnswers.<br>
<br>
So, if you want change some answers, you need edit the files in this directory.<br>
