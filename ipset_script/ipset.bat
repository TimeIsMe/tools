@echo off

REM **************************************************
REM author:Mingliang Wang
REM date:2022.11.29
REM version:1.0
REM **************************************************

set li0=script of set address of ipv4
cls
echo %li0%

set cur_path=%~dp0

REM #########################SECTION 1#########################
rem set enviriment
rem such as ip_1=xxx
SETLOCAL ENABLEDELAYEDEXPANSION
set /a count=0
echo ip[0]:dhcp
for /f %%i in (%cur_path%/ipaddr.txt) do (
	set /a count+=1
	set ip[!count!]=%%i
	echo ip[!count!]:%%i
)
ENDLOCAL

REM #########################SECTION 2#########################
:restart
REM input
set /p input=enter your choice:
REM echo %input%
if "%input%" == "" goto end

if ip[%input%] == "" (
   echo invalid input, please input again!
   goto restart
)
set /a .=%input%
::echo %.%

if %.% == 0 (
	echo . = 0
	goto DHCP
)

SETLOCAL ENABLEDELAYEDEXPANSION
set /a j=0
echo cur_path: %cur_path%
for /f %%i in (%cur_path%ipaddr.txt) do (
    set /a j+=1
    if %.%==!j! (set ip_set=%%i )
)

set ip_set=%ip_set%
echo ip_set=%ip_set%

REM #########################SECTION 3#########################
REM string splite
set /a count=0
set gatway=""
set ip_buf=%ip_set%
:stringloop

if "!ip_buf!" EQU "" goto SPLITE_END

for /f "delims=." %%a in ("!ip_buf!") do set sub_str=%%a

set /a count+=1

REM echo count=!count!

REM concat string
if !count! LSS 4 (
       if !gatway! NEQ "" (set gatway=%gatway%.%sub_str%)
       if !gatway! EQU "" (set gatway=%sub_str%)
)

:striploop
set stripchar=!ip_buf:~0,1!
set ip_buf=!ip_buf:~1!

if "!stripchar!" EQU "." goto stringloop

if "!ip_buf!" NEQ "" goto striploop

goto stringloop

:SPLITE_END

REM set gatway host
set gatway=%gatway%.1
REM echo gatway=%gatway%

REM #########################SECTION 4#########################
REM netsh interface ipv4 set address name="Ethernet" source=static %ip_set% 255.255.255.0 %gatway%

REM echo %gatway%
netsh interface ipv4 set address name="Ethernet" source=static %ip_set% 255.255.255.0 %gatway%
goto DISPLAY

:DHCP
netsh interface ipv4 set address "Ethernet" dhcp
netsh interface ipv4 set dns "Ethernet" dhcp

REM #########################SECTION 5#########################
REM display ipaddr
:DISPLAY
echo please wait four seconds....

TIMEOUT 3

ipconfig

ENDLOCAL


::netsh interface ipv4 set dns name="Ethernet" source=dhcp

::echo display the ip address
::ipconfig

:end

TIMEOUT 5
REM pause
